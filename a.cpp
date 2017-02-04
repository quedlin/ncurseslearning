#include "ncurses.h"
#include <stdlib.h>
#include <string.h> 
// 80x25 character screen

int main()
{
	

	initscr();	//Start curses mode
	raw();		//Line buffering disabled
	keypad(stdscr, TRUE);	//We get F1, F2 etc...
	noecho();	//Don't echo() while we do getch
	/*-----------------------------------------------------*/
	


	
	
	
	
	start_color();			/* Start color functionality	*/
	
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	printw("A Big string which i didn't care to type fully ");
	mvchgat(0, 0, -1, A_BLINK, 1, NULL);	
	
	
	
	
	/*
	char mesg[]="Just a string";	
	int row,col;				
					 
				
	getmaxyx(stdscr,row,col);		
	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
									
	mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
	printw("Try resizing your window(if possible) and then run this program again");
	*/
	
/*

	move(4,50);
	printw("Hai there");
	move(4,9);
	printw("Welcome");
	move(4,20);
	printw("I am c++");
*/

/*
	
	int ch;
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
*/

	
	
	/*-----------------------------------------------------*/
	refresh();
	getch();
	endwin();

	return 0;


}
