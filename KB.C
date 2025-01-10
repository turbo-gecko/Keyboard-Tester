/* KB.C
 *
 * Program for testing the scan codes being sent from an XT
 * keyboard using scan code set 1.
 *
 * Copyright 2025 - Gary Hammond
 * Code is free to use and modify for non-commercial purposes.
 *
 * v1.0	- Initial version
 */

#include <bios.h>
#include <graph.h>
#include <stdio.h>

#include "KB_DEF.C"

void displayHelp(void);
void drawBox(int, int, int, int);
void drawKeyboard(char *, struct key_code *, int);
void kbWindow(void);
void stWindow(struct rccoord);
void keyPressed(struct key_code *, int);
void keyStatus(struct sk_status *, int);

/* ------------------------------------------------------------------
 * Main program
 * ------------------------------------------------------------------ */
int main(int argc, char *argv[])
{
	struct rccoord stw_pos;	/* Last text position in status window */
	int i = 0;				/* Used for loop counting */
	int kb_stat = 0;        /* Keyboard Status bytes */
	int kb_stat_prev = 0;   /* Previous keyboard status bytes */
	int scode = 0;          /* Scan code */
	int table_size = 0;     /* Sive of the key_code table */
	char text[82];          /* Text buffer for a line of text */

	char *kb_text_ptr = NULL;
	struct key_code *table_ptr = NULL;
	struct sk_status *status_ptr = NULL;

	/* Initialise starting text position */
	stw_pos.row = 1;
	stw_pos.col = 1;

	/* Set the default keyboard to the 83 key PC/XT keyboard */
	kb_text_ptr = k83_text;
	status_ptr = k83_status;
	table_size = sizeof(k83_table);
	table_ptr = k83_table;

	/* Check to see if command line argument exists */
	if(argc == 2)
	{
		if(strcmp(argv[1], "-84") == 0)
		{
			kb_text_ptr = k84_text;
			status_ptr = k84_status;
			table_size = sizeof(k84_table);
			table_ptr = k84_table;
		}
		else if(strcmp(argv[1], "-h") == 0)
		{
			displayHelp();
			exit(0);
		}
	}

	/* Set up the screen */
	_clearscreen(_GCLEARSCREEN);
	drawKeyboard(kb_text_ptr, table_ptr, table_size);
	keyStatus(status_ptr, kb_stat);
	stWindow(stw_pos);

	/* Main loop - Exit by the 'Esc' key */
	while(scode != 0x011B)
	{
		/* Check to see if the keyboard status byte has changed */
		kb_stat = _bios_keybrd(_NKEYBRD_SHIFTSTATUS);
		if(kb_stat != kb_stat_prev) /* Changed? */
		{
		   keyStatus(status_ptr, kb_stat);

		   stWindow(stw_pos);
		   sprintf(text, "Status : %04x\n", kb_stat);
		   _outtext(text);
		   kb_stat_prev = kb_stat;
		   stw_pos = _gettextposition();
		}

		/* Check to see if a key has been pressed */
		scode = _bios_keybrd(_NKEYBRD_READY);
		if(scode != 0)
		{
			/* Traverse the key table for a valid key press */
			for(i = 0; i < (table_size/sizeof(struct key_code)); i++)
			{
				/* Display the key press in the keyboard window */
				if(table_ptr[i].code == (scode >> 8))
				{
					keyPressed(table_ptr, i);
				}
			}

			/* Display the key press info in the status window */
			stWindow(stw_pos);
			if(((scode & 255) != '\r') && ((scode & 255) != 0))
			{
				sprintf(text, "Code   : %02x   ASCII : %02x %c\n",
						((unsigned char) (scode >> 8)),
						(scode & 255),
						(scode & 255));
			}
			else /* Account for an ASCII code that screws up output */
			{
				sprintf(text, "Code   : %02x   ASCII : %02x %c\n",
						((unsigned char) (scode >> 8)),
						(scode & 255),
						255);
			}
			_outtext(text);
			stw_pos = _gettextposition();

			/* Consume the key press to empty the buffer */
			scode = _bios_keybrd(_NKEYBRD_READ);
		}
	}
	exit(0);
}

/* ------------------------------------------------------------------
 * Displays the command line help info
 * ------------------------------------------------------------------ */
void displayHelp(void)
{
	_outtext("KB [option]\n");
	_outtext("option:\n");
	_outtext("-h      - This help message\n");
	_outtext("-84     - AT 84 key layout\n\n");
	_outtext("The default keyboard layout is\n");
	_outtext("the PC/XT 83 key layout\n\n");
}

/* ------------------------------------------------------------------
 * Draws a double border box
 * ------------------------------------------------------------------ */
void drawBox(int u_row, int u_col, int l_row, int l_col)
{
	int i = 0;

	_settextposition(u_row, u_col);
	putchar(201);

	_settextposition(u_row, l_col);
	putchar(187);

	_settextposition(l_row, u_col);
	putchar(200);

	_settextposition(l_row, l_col);
	putchar(188);

	for(i = u_row + 1; i < l_col; i++)
	{
		_settextposition(u_row, i);
		putchar(205);
		
		_settextposition(l_row, i);
		putchar(205);
	}

	_settextposition(u_row, l_col - 8);
	putchar(209);

	_settextposition(l_row, l_col - 8);
	putchar(207);

	for(i = u_col + 1; i < l_row; i++)
	{
		_settextposition(i, u_col);
		putchar(186);
		
		_settextposition(i, l_col - 8);
		putchar(179);

		_settextposition(i, l_col);
		putchar(186);
	}
}
/* ------------------------------------------------------------------
 * Draws the keyboard in the keyboard window
 * ------------------------------------------------------------------ */
void drawKeyboard(char *kb_text, struct key_code *ptr, int size)
{
	int i = 0;
	char text[21];

	kbWindow();

	_setbkcolor(DEF_BG);
	_settextcolor(DEF_FG);

	/* Draw the window border */
	drawBox(KBW_UR, KBW_UC, KBW_LR, KBW_LC);

	sprintf(text, "%c%s%c", 181, kb_text, 198);
	_settextposition(KBW_UR, KBT_COL);
	_outtext(text);

	sprintf(text, "%cState%c", 181, 198);
	_settextposition(KBW_UR, KBW_LC - 7);
	_outtext(text);

	_setbkcolor(KBC_DEF_BG);
	_settextcolor(KBC_DEF_FG);

	for(i = 0; i < (size/sizeof(struct key_code)); i++)
	{
		_settextposition(ptr[i].row + KB_ROW_OFFSET,
						 ptr[i].col + KB_COL_OFFSET);
		_outtext(ptr[i].label);
	}
	_setbkcolor(DEF_BG);
	_settextcolor(DEF_FG);
}

/* ------------------------------------------------------------------
 * Sets the current text window to the keyboard window
 * ------------------------------------------------------------------ */
void kbWindow(void)
{
	_displaycursor(_GCURSOROFF);
	_settextwindow(KBW_UR, KBW_UC, KBW_LR, KBW_LC);
}

/* ------------------------------------------------------------------
 * Sets the current text window to the status window
 * ------------------------------------------------------------------ */
void stWindow(struct rccoord pos)
{
	_displaycursor(_GCURSORON);
	_settextwindow(STW_UR, STW_UC, STW_LR, STW_LC);
	_settextposition(pos.row, pos.col);
}

/* ------------------------------------------------------------------
 * Changes the key in the keyboard window to show that it has been
 * pressed.
 * ------------------------------------------------------------------ */
void keyPressed(struct key_code *ptr, int key)
{
	kbWindow();
	_setbkcolor(BG_BLUE);
	_settextcolor(FG_YELLOW);
	_settextposition(ptr[key].row + KB_ROW_OFFSET,
					 ptr[key].col + KB_COL_OFFSET);
	_outtext(ptr[key].label);
	_setbkcolor(DEF_BG);
	_settextcolor(DEF_FG);
}

/* ------------------------------------------------------------------
 * Updates the toggle states and modifier key states in the keyboard
 * window.
 * ------------------------------------------------------------------ */
void keyStatus(struct sk_status *ptr, int s_word)
{
	static int i = 0;

	kbWindow();
	for(i = 0; i < 16; i++)
	{
		if((ptr[i].bit & s_word) == 0)
		{
			_setbkcolor(KBC_DEF_BG);
			_settextcolor(KBC_DEF_FG);
		}
		else
		{
			_setbkcolor(BG_GREEN);
			_settextcolor(FG_YELLOW);
		}
		_settextposition(ptr[i].row + KB_ROW_OFFSET,
						 ptr[i].col + KB_COL_OFFSET);
		_outtext(ptr[i].label);
	}
	_setbkcolor(DEF_BG);
	_settextcolor(DEF_FG);
}

