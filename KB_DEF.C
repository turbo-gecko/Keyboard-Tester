/* KB_DEF.C
 *
 * Definitions file for KB.C.
 *
 * Copyright 2025 - Gary Hammond
 * Code is free to use and modify for non-commercial purposes.
 *
 * v1.0	- Initial version
 */

/* Note: It should be possible to create layouts for non-US keyboards
 * by copying this file to a new file i.e., KB_FR.C (for French) and
 * changing the line in KB.C that imports KB_DEF.C to KB_FR.C
 */

/* Background colours */
#define BG_BLACK    	0L
#define BG_BLUE			1L	
#define BG_GREEN		2L
#define BG_CYAN			3L
#define BG_RED			4L
#define BG_MAGENTA		5L
#define BG_BROWN		6L
#define BG_WHITE		7L
#define BG_D_GREY		8L
#define BG_L_BLUE		9L
#define BG_L_GREEN		10L
#define BG_L_CYAN		11L
#define BG_L_RED		12L
#define BG_L_MAGENTA	13L
#define BG_YELLOW		14L
#define BG_B_WHITE		15L

/* Foreground colours */
#define FG_BLACK    	0
#define FG_BLUE			1	
#define FG_GREEN		2
#define FG_CYAN			3
#define FG_RED			4
#define FG_MAGENTA		5
#define FG_BROWN		6
#define FG_WHITE		7
#define FG_D_GREY		8
#define FG_L_BLUE		9
#define FG_L_GREEN		10
#define FG_L_CYAN		11
#define FG_L_RED		12
#define FG_L_MAGENTA	13
#define FG_YELLOW		14
#define FG_B_WHITE		15

#define DEF_BG          BG_BLACK
#define DEF_FG          FG_WHITE
#define KBC_DEF_BG		BG_B_WHITE
#define KBC_DEF_FG		FG_BLACK

/* Text window co-ordinates */
#define KBW_UR      	1
#define KBW_UC      	1
#define KBW_LR          13
#define KBW_LC      	80

#define STW_UR          14
#define STW_UC      	1
#define STW_LR      	25
#define STW_LC      	80

#define KB_ROW_OFFSET   2
#define KB_COL_OFFSET   3
#define KBT_COL         5
struct sk_status
{
	int     bit;        /* Bit position */
	char    code;       /* Scan code */
	int     row;        /* Keyboard screen row */
	int     col;        /* Keyboard screen column */
	char    label[8];   /* Text to be displayed on keyboard screen */
};

struct key_code
{
	char    key;        /* Key number index */
	char    code;       /* Scan code */
	int     row;        /* Keyboard screen row */
	int     col;        /* Keyboard screen column */
	char    label[8];   /* Text to be displayed on keyboard screen */
};

/* ------------------------------------------------------------------
 * Bit fields for the 83 key keyboard status bytes
 * ------------------------------------------------------------------ */
struct sk_status k83_status[] =
{
	{0x0001, 0x36, 7, 46, "Shft"},
	{0x0002, 0x2A, 7, 10, "Sh"},
	{0x0004, 0x1D, 5, 10, "Ctrl"},
	{0x0008, 0x38, 9, 10, "Alt"},
	{0x0010, 0x00, 1, 71, " SCR "},
	{0x0020, 0x00, 3, 71, " NUM "},
	{0x0040, 0x00, 5, 71, " CAP "},
	{0x0080, 0x00, 7, 71, " INS "},
	{0x0100, 0x1D},
	{0x0200, 0x38},
	{0x0400, 0x00},
	{0x0800, 0x00},
	{0x1000, 0x46, 1, 60, "Scrol"},
	{0x2000, 0x45, 1, 54, " Num "},
	{0x4000, 0x3A, 9, 46, "Caps"},
	{0x8000, 0x52, 9, 51, "  0  "}
};

/* ------------------------------------------------------------------
 * PC/XT 83 key keyboard scan codes with the corresponding key
 * position and label for displaying in the keyboard area of the
 * screen.
 * ------------------------------------------------------------------ */
struct key_code k83_table[] =
{
	{1, 0x29, 5, 48, " `"},
	{2, 0x02, 1, 13, " 1"},
	{3, 0x03, 1, 16, " 2"},
	{4, 0x04, 1, 19, " 3"},
	{5, 0x05, 1, 22, " 4"},
	{6, 0x06, 1, 25, " 5"},
	{7, 0x07, 1, 28, " 6"},
	{8, 0x08, 1, 31, " 7"},
	{9, 0x09, 1, 34, " 8"},
	{10, 0x0A, 1, 37, " 9"},
	{11, 0x0B, 1, 40, " 0"},
	{12, 0x0C, 1, 43, " -"},
	{13, 0x0D, 1, 46, " ="},
	{15, 0x0E, 1, 49, {17, '-', 'B', 'S', 0}},
	{16, 0x0F, 3, 10, "Tab"},
	{17, 0x10, 3, 14, " Q"},
	{18, 0x11, 3, 17, " W"},
	{19, 0x12, 3, 20, " E"},
	{20, 0x13, 3, 23, " R"},
	{21, 0x14, 3, 26, " T"},
	{22, 0x15, 3, 29, " Y"},
	{23, 0x16, 3, 32, " U"},
	{24, 0x17, 3, 35, " I"},
	{25, 0x18, 3, 38, " O"},
	{26, 0x19, 3, 41, " P"},
	{27, 0x1A, 3, 44, " ["},
	{28, 0x1B, 3, 47, " ] "},
	{29, 0x2B, 7, 13, {' ', 92, 0}},
	{30, 0x3A, 9, 46, "Caps"},
	{31, 0x1E, 5, 15, " A"},
	{32, 0x1F, 5, 18, " S"},
	{33, 0x20, 5, 21, " D"},
	{34, 0x21, 5, 24, " F"},
	{35, 0x22, 5, 27, " G"},
	{36, 0x23, 5, 30, " H"},
	{37, 0x24, 5, 33, " J"},
	{38, 0x25, 5, 36, " K"},
	{39, 0x26, 5, 39, " L"},
	{40, 0x27, 5, 42, " ;"},
	{41, 0x28, 5, 45, " '"},
	{43, 0x1C, 3, 51, "  "},
	{43, 0x1C, 4, 51, {17, 217, 0}},
	{43, 0x1C, 5, 51, "  "},
	{44, 0x2A, 7, 10, "Sh"},
	{45, 0x56},
	{46, 0x2C, 7, 16, " Z"},
	{47, 0x2D, 7, 19, " X"},
	{48, 0x2E, 7, 22, " C"},
	{49, 0x2F, 7, 25, " V"},
	{50, 0x30, 7, 28, " B"},
	{51, 0x31, 7, 31, " N"},
	{52, 0x32, 7, 34, " M"},
	{53, 0x33, 7, 37, " ,"},
	{54, 0x34, 7, 40, " ."},
	{55, 0x35, 7, 43, " /"},
	{57, 0x36, 7, 46, "Shft"},
	{58, 0x1D, 5, 10, "Ctrl"},
	{60, 0x38, 9, 10, "Alt"},
	{61, 0x39, 9, 14, "       "},
	{61, 0x39, 9, 21, "      "},
	{61, 0x39, 9, 27, "Space"},
	{61, 0x39, 9, 32, "      "},
	{61, 0x39, 9, 38, "       "},
	{62, 0x00},
	{64, 0x00},
	{90, 0x45, 1, 54, " Num "},
	{91, 0x47, 3, 54, " 7"},
	{92, 0x4B, 5, 54, " 4"},
	{93, 0x4F, 7, 54, " 1"},
	{95, 0x00},
	{96, 0x48, 3, 57, " 8"},
	{97, 0x4C, 5, 57, " 5"},
	{98, 0x50, 7, 57, " 2"},
	{99, 0x52, 9, 51, "  0  "},
	{100, 0x37, 7, 51, " *"},
	{101, 0x49, 3, 60, " 9"},
	{102, 0x4D, 5, 60, " 6"},
	{103, 0x51, 7, 60, " 3"},
	{104, 0x53, 9, 57, "  .  "},
	{105, 0x4A, 3, 63, " -"},
	{106, 0x4E, 5, 63, "  "},
	{106, 0x4E, 6, 63, "  "},
	{106, 0x4E, 7, 63, " +"},
	{106, 0x4E, 8, 63, "  "},
	{108, 0x4E, 9, 63, "  "},
	{108, 0x00},
	{108, 0x00},
	{110, 0x01, 1, 10, "Es"},
	{112, 0x3B, 1, 2, "F1"},
	{113, 0x3C, 1, 5, "F2"},
	{114, 0x3D, 3, 2, "F3"},
	{115, 0x3E, 3, 5, "F4"},
	{116, 0x3F, 5, 2, "F5"},
	{117, 0x40, 5, 5, "F6"},
	{118, 0x41, 7, 2, "F7"},
	{119, 0x42, 7, 5, "F8"},
	{120, 0x43, 9, 2, "F9"},
	{121, 0x44, 9, 5, "10"},
	{122, 0x57},
	{123, 0x58},
	{124, 0x00},
	{125, 0x46, 1, 60, "Scrol"},
	{126, 0x00}
};

char k83_text[] = "PC/XT 83 Key";

/* ------------------------------------------------------------------
 * Bit fields for the 84 key keyboard status bytes
 * ------------------------------------------------------------------ */
struct sk_status k84_status[] =
{
	{0x0001, 0x36, 7, 46, " Shift "},
	{0x0002, 0x2A, 7, 9, "Shift"},
	{0x0004, 0x1D, 5, 9, "Ctrl"},
	{0x0008, 0x38, 9, 9, "Alt "},
	{0x0010, 0x00, 1, 71, " SCR "},
	{0x0020, 0x00, 3, 71, " NUM "},
	{0x0040, 0x00, 5, 71, " CAP "},
	{0x0080, 0x00, 7, 71, " INS "},
	{0x0100, 0x1D},
	{0x0200, 0x38},
	{0x0400, 0x00, 1, 65, "Rq"},
	{0x0800, 0x00},
	{0x1000, 0x46, 1, 62, "SL"},
	{0x2000, 0x45, 1, 59, "NL"},
	{0x4000, 0x3A, 9, 49, "Caps"},
	{0x8000, 0x52, 9, 56, "  0  "}
};

/* ------------------------------------------------------------------
 * AT 84 key keyboard scan codes with the corresponding key position
 * and label for displaying in the keyboard area of the screen.
 * ------------------------------------------------------------------ */
struct key_code k84_table[] =
{
	{1, 0x29, 1, 9, " `"},
	{2, 0x02, 1, 12, " 1"},
	{3, 0x03, 1, 15, " 2"},
	{4, 0x04, 1, 18, " 3"},
	{5, 0x05, 1, 21, " 4"},
	{6, 0x06, 1, 24, " 5"},
	{7, 0x07, 1, 27, " 6"},
	{8, 0x08, 1, 30, " 7"},
	{9, 0x09, 1, 33, " 8"},
	{10, 0x0A, 1, 36, " 9"},
	{11, 0x0B, 1, 39, " 0"},
	{12, 0x0C, 1, 42, " -"},
	{13, 0x0D, 1, 45, " ="},
	{15, 0x0E, 1, 51, {17, '-', 0}},
	{16, 0x0F, 3, 9, "Tab"},
	{17, 0x10, 3, 13, " Q"},
	{18, 0x11, 3, 16, " W"},
	{19, 0x12, 3, 19, " E"},
	{20, 0x13, 3, 22, " R"},
	{21, 0x14, 3, 25, " T"},
	{22, 0x15, 3, 28, " Y"},
	{23, 0x16, 3, 31, " U"},
	{24, 0x17, 3, 34, " I"},
	{25, 0x18, 3, 37, " O"},
	{26, 0x19, 3, 40, " P"},
	{27, 0x1A, 3, 43, " ["},
	{28, 0x1B, 3, 46, " ]"},
	{29, 0x2B, 1, 48, {' ', 92, 0}},
	{30, 0x3A, 9, 49, "Caps"},
	{31, 0x1E, 5, 14, " A"},
	{32, 0x1F, 5, 17, " S"},
	{33, 0x20, 5, 20, " D"},
	{34, 0x21, 5, 23, " F"},
	{35, 0x22, 5, 26, " G"},
	{36, 0x23, 5, 29, " H"},
	{37, 0x24, 5, 32, " J"},
	{38, 0x25, 5, 35, " K"},
	{39, 0x26, 5, 38, " L"},
	{40, 0x27, 5, 41, " ;"},
	{41, 0x28, 5, 44, " '"},
	{43, 0x1C, 3, 49, "    "},
	{43, 0x1C, 4, 49, "    "},
	{43, 0x1C, 5, 47, " Enter"},
	{44, 0x2A, 7, 9, "Shift"},
	{45, 0x56},
	{46, 0x2C, 7, 15, " Z"},
	{47, 0x2D, 7, 18, " X"},
	{48, 0x2E, 7, 21, " C"},
	{49, 0x2F, 7, 24, " V"},
	{50, 0x30, 7, 27, " B"},
	{51, 0x31, 7, 30, " N"},
	{52, 0x32, 7, 33, " M"},
	{53, 0x33, 7, 36, " ,"},
	{54, 0x34, 7, 39, " ."},
	{55, 0x35, 7, 42, " /"},
	{57, 0x36, 7, 46, " Shift "},
	{58, 0x1D, 5, 9, "Ctrl"},
	{60, 0x38, 9, 9, "Alt "},
	{61, 0x39, 9, 16, "      "},
	{61, 0x39, 9, 22, "     "},
	{61, 0x39, 9, 27, "Space"},
	{61, 0x39, 9, 32, "      "},
	{61, 0x39, 9, 38, "      "},
	{62, 0x00},
	{64, 0x00},
	{90, 0x45, 1, 59, "NL"},
	{91, 0x47, 3, 56, " 7"},
	{92, 0x4B, 5, 56, " 4"},
	{93, 0x4F, 7, 56, " 1"},
	{95, 0x00},
	{96, 0x48, 3, 59, " 8"},
	{97, 0x4C, 5, 59, " 5"},
	{98, 0x50, 7, 59, " 2"},
	{99, 0x52, 9, 56, "  0  "},
	{100, 0x37, 3, 65, " *"},
	{101, 0x49, 3, 62, " 9"},
	{102, 0x4D, 5, 62, " 6"},
	{103, 0x51, 7, 62, " 3"},
	{104, 0x53, 9, 62, " ."},
	{105, 0x4A, 5, 65, " -"},
	{106, 0x4E, 7, 65, "  "},
	{106, 0x4E, 8, 65, " +"},
	{108, 0x4E, 9, 65, "  "},
	{108, 0x00},
	{108, 0x00},
	{110, 0x01, 1, 56, "Es"},
	{112, 0x3B, 1, 1, "F1"},
	{113, 0x3C, 1, 4, "F2"},
	{114, 0x3D, 3, 1, "F3"},
	{115, 0x3E, 3, 4, "F4"},
	{116, 0x3F, 5, 1, "F5"},
	{117, 0x40, 5, 4, "F6"},
	{118, 0x41, 7, 1, "F7"},
	{119, 0x42, 7, 4, "F8"},
	{120, 0x43, 9, 1, "F9"},
	{121, 0x44, 9, 4, "10"},
	{122, 0x57},
	{123, 0x58},
	{124, 0x00},
	{125, 0x46, 1, 62, "SL"},
	{126, 0x00}
};

char k84_text[] = "AT 84 Key";


