#include <tcclib.h>
#include "cui.h"

void goto_xy(int x, int y){
	printf("\033[%d;%dH", x, y);
}

void clear_line(void){
	puts("\033[K");
}

void clear_scr(void){
	goto_xy(0, 0);
	puts("\033[2J");
	goto_xy(0, 0);
}
