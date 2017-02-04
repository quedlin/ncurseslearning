#include "ncurses.h"
// 80x25 character screen

int main()
{
	int ch;

	initscr();	//Start curses mode
	raw();		//Line buffering disabled
	keypad(stdscr, TRUE);	//We get F1, F2 etc...
	noecho();	//Don't echo() while we do getch

/*

	move(4,50);
	printw("Hai there");
	move(4,9);
	printw("Welcome");
	move(4,20);
	printw("I am c++");
*/

	printw("Type any character to see it in bold\n");
	ch = getch();	//If raw() hadn't been called, 
			//we have to press enter 
			//before it gets to the program
	if(ch == KEY_F(1))	//Without keypad enabled, 
		printw("F1 Key pressed");	//this would not get to us either

	else
	{
		printw("");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}


	refresh();
	getch();
	endwin();

	return 0;


}
