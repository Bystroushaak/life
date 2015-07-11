// Life for Bellards javascript PC emulator v1.0.0 (29.05.2011)
// by Bystroushaak (bystrousak@kitakitsune.org)

#include <tcclib.h>
#include "../libs/cui.h"

#define WIDTH	80
#define HEIGHT	30

char screen0[HEIGHT][WIDTH];
char screen1[HEIGHT][WIDTH];

int vline_n(char s[HEIGHT][WIDTH], int x, int y){
	int n = 0;
	if (x >= 0 && x <= WIDTH - 1){
		if (s[y][x] == 1)
			n++;
			
		if (y > 0 && s[y-1][x] == 1)
			n++;
			
		if (y < HEIGHT - 1 && s[y+1][x] == 1)
			n++;
	}
	
	return n;
}

int neighbors(char s[HEIGHT][WIDTH], int x, int y){
	return vline_n(s, x - 1, y) + vline_n(s, x + 1, y) + vline_n(s, x, y) - s[y][x];
}

// Compute one step
void step(char old[HEIGHT][WIDTH], char new[HEIGHT][WIDTH]){
	int x, y;
	
	for(x = 0; x < WIDTH - 1; x++)
		for(y = 0; y < HEIGHT - 1; y++){
			switch(neighbors(old, x, y)){
				case 0:
					new[y][x] = 0;
					break;
				case 1:
					new[y][x] = 0;
					break;
				case 2:
					new[y][x] = old[y][x]; // replace with = 1; and you will see something really interesting :)
					break;
				case 3:
					new[y][x] = 1;
					break;
				default:
					new[y][x] = 0;
					break;
			}
		}
}

// erase gamedesk
void erase(char s[HEIGHT][WIDTH]){
	int x, y;
	
	for (y = 0; y < HEIGHT - 1; y++)
		for (x = 0; x < WIDTH - 1; x++)
			s[y][x] = 0;
}

// print gamedesk
void show(char s[HEIGHT][WIDTH]){
	int x, y;
	
	goto_xy(0, 0);
	
	for (y = 0; y < HEIGHT - 1; y++){
		for (x = 0; x < WIDTH - 1; x++)
			if (s[y][x] == 1)
				putchar('#');
			else
				putchar(' ');
		
		putchar('\n');
	}
}

void main(){
	erase(screen0);
	erase(screen1);

	clear_scr();
	
	// after unpacked, add one dot into same corner of each stable cell and you will see nice efect (only for bigger screens)
	screen0[15][40] = 1;
	screen0[16][39] = 1;
	screen0[16][41] = 1;
	screen0[17][39] = 1;
	screen0[17][41] = 1;
	screen0[18][40] = 1;
	screen0[15][39] = 1;

	show(screen0);
	
	while (1){
		step(screen0, screen1);
		show(screen1);
		
		erase(screen0);
		
//		getchar();
		
		step(screen1, screen0);
		show(screen0);
		
		erase(screen1);
		
//		getchar();
	}
}
