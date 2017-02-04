#include "ncurses.h"
#include <stdlib.h>
#include <string.h> 
// 80x25 character screen

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main(int argc, char *argv[])
{
	WINDOW *my_win;
	int startx, starty, width, height;
	int ch;

	initscr();	//Start curses mode
	raw();		//Line buffering disabled
	keypad(stdscr, TRUE);	//We get F1, F2 etc...
	noecho();	//Don't echo() while we do getch
	/*-----------------------------------------------------*/
	

	height = 3;
	width = 10;
	starty = (LINES - height) / 2;	/* Calculating for a center placement */
	startx = (COLS - width) / 2;	/* of the window		*/
	printw("Press F1 to exit");
	refresh();
	my_win = create_newwin(height, width, starty, startx);

	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case KEY_LEFT:
				destroy_win(my_win);
				my_win = create_newwin(height, width, starty,--startx);
				break;
			case KEY_RIGHT:
				destroy_win(my_win);
				my_win = create_newwin(height, width, starty,++startx);
				break;
			case KEY_UP:
				destroy_win(my_win);
				my_win = create_newwin(height, width, --starty,startx);
				break;
			case KEY_DOWN:
				destroy_win(my_win);
				my_win = create_newwin(height, width, ++starty,startx);
				break;	
		}
	}
	
	
	
	
	
	
	/*
	start_color();			
	
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	printw("A Big string which i didn't care to type fully ");
	mvchgat(0, 0, -1, A_BLINK, 1, NULL);	
	*/
	
	
	
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
	//refresh();
	//getch();
	endwin();

	return 0;


}


WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}


























