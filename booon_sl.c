#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "booon.h"

void my_mvaddstr(int y, int x, const char *str)
{
	char str_c[128];

	strcpy(str_c, str);
	
	if (x + LENGTH > COLS) {
		str_c[COLS - x] = '\0';
	}

	mvaddstr(y, x, str_c);
}

int main(int argc, char *argv[])
{
	int j, i;
 
	setlocale(LC_ALL, "");

	initscr();

	j = LINES/2 - 3;

	for (i = 0; i < COLS; ++i) {
		clear();

		my_mvaddstr(j    , i, BOOONSTR1);
		my_mvaddstr(j + 1, i, BOOONSTR2);
		my_mvaddstr(j + 2, i, BOOONSTR3);
		my_mvaddstr(j + 3, i, BOOONSTR4);
		my_mvaddstr(j + 4, i, BOOONSTR5);
		my_mvaddstr(j + 5, i, BOOONSTR6);

		move(LINES - 1, COLS - 1);
		refresh();
		usleep(50000);
	}

	endwin();

	return 0;
}

