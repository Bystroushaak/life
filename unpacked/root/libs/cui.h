#ifndef _CUI_H
#define _CUI_H

#define BLACK	"\033[0;30m"
#define RED	"\033[0;31m"
#define GREEN	"\033[0;32m"
#define BROWN	"\033[0;33m"
#define BLUE	"\033[0;34m"
#define PURPLE	"\033[0;35m"
#define CYAN	"\033[0;36m"
#define LGRAY	"\033[0;37m"

#define DGRAY	"\033[1;30m"
#define LBLUE	"\033[1;31m"
#define LGREEN	"\033[1;32m"
#define LCYAN	"\033[1;33m"
#define LRED	"\033[1;34m"
#define LPURPLE	"\033[1;35m"
#define YELLOW	"\033[1;36m"
#define WHITE	"\033[1;37m"

#define NORMAL "\033[22;37m"

void goto_xy(int, int);
void clear_line(void);
void clear_scr(void);

#endif

