#ifndef _SCRAMBLE_H_
#define _SCRAMBLE_H_

void append(char **str, const char *suffix);
char *move(int bot, int top);
char *turns(int x);
char *scrGen(int bot, int top, int length, int wideMoves);


#endif