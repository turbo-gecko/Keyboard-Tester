# Keyboard-Tester
DOS program for testing keyboards on a PC/XT.
I wrote this program for diagnosing an AT to PC/XT keyboard protocol converter I have developed using an Arduino. I was originally using the keyboard test functionality in 'CheckIt' but found it not quite suited for the sort of testing I was doing.

## Usage
KB [option]
option:
-h      - This help message
-84     - AT 84 key layout
The default keyboard layout is the PC/XT 83 key layout

## Description
The program is used to test keyboard codes sent to the computer as interpreted by DOS.
The top half of the screen is a pictorial layout of the keyboard where keys will change colour when the are pressed.
Modifier keys such as 'Shift', 'Ctrl', 'Alt' etc., will show Green whilst pressed where the remainder of the keys will show blue, and remain blue, after they have been pressed once.
On the right of the keyboard layout, is the 4 state indicators for
- Scroll Lock
- Num Lock
- Caps Lock
- Insert Mode

## Code
The program was writtin in Microsoft Quick C (2.5) and developed on an XT (NuXT) computer. There are only 2 C files with KB.C being the main program and KB_DEF.C containing constants and the translation tables.
KB.EXE is included for those who do not want to modify or build the software. This was compiled under MS DOS 6.22.
