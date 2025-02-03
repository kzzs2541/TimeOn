#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "scramble.h"


void append(char **str, const char *suffix) 
{
    if (*str == NULL) 
    {  
        *str = malloc(strlen(suffix) + 1);
        strcpy(*str, suffix);
    } 
    else 
    { 
        char *temp = realloc(*str, strlen(*str) + strlen(suffix) + 1);
        *str = temp;
        strcat(*str, suffix);
    }
}

char *scrGen(int bot, int top, int length, int wideMoves)//3x3: 1-18, 25; 2x2: 1-9, 10; 4x4:1-27, 45 
{

    srand(time(NULL));
    int i = 0, last, laster, current, wideCounter = 0;

    char *scramble = NULL;
    while (i < length)
    {
        if((top > 18 && wideCounter < wideMoves) || top <= 18)
        current = rand() % top + 1;
        else
            current = rand() % 18 + 1;

        if ((current - 1) / 3 != (last - 1) / 3 && !(((current - 1) / 3) - ((laster - 1) / 3) == 0 && ((current - 1) / 3) - ((last - 1) / 3) == 3 || ((current - 1) / 3) - ((last - 1) / 3) == -3)) /*sprawdza formacje typu R R2 lub R L R*/
        {
            append(&scramble, turns(current));
            i++;
            if(current > 18)
                wideCounter++;
        }
        laster = last;
        last = current;
        current = 0;
    }
    return scramble;
}

char *turns(int x) //base moves
{
    char *out = "";
    switch (x)
    {
    case 1:
        out = "R ";
        break;
    case 2:
        out = "R' ";
        break;
    case 3:
        out = "R2 ";
        break;
    case 4:
        out = "U ";
        break;
    case 5:
        out = "U' ";
        break;
    case 6:
        out = "U2 ";
        break;
    case 7:
        out = "F ";
        break;
    case 8:
        out = "F' ";
        break;
    case 9:
        out = "F2 ";
        break;
    case 10:
        out = "L ";
        break;
    case 11:
        out = "L' ";
        break;
    case 12:
        out = "L2 ";
        break;
    case 13:
        out = "D ";
        break;
    case 14:
        out = "D' ";
        break;
    case 15:
        out = "D2 ";
        break;
    case 16:
        out = "B ";
        break;
    case 17:
        out = "B' ";
        break;
    case 18:
        out = "B2 ";
        break;
    case 19:
        out = "Rw ";
        break;
    case 20:
        out = "Rw' ";
        break;
    case 21:
        out = "Rw2 ";
        break;
    case 22:
        out = "Uw ";
        break;
    case 23:
        out = "Uw' ";
        break;
    case 24:
        out = "Uw2 ";
        break;
    case 25:
        out = "Fw ";
        break;
    case 26:
        out = "Fw' ";
        break;
    case 27:
        out = "Fw2 ";
        break;
    case 28:
        out = "Lw ";
        break;
    case 29:
        out = "Lw' ";
        break;
    case 30:
        out = "Lw2 ";
        break;
    case 31:
        out = "Dw ";
        break;
    case 32:
        out = "Dw' ";
        break;
    case 33:
        out = "Dw2 ";
        break;
    case 34:
        out = "Bw ";
        break;
    case 35:
        out = "Bw' ";
        break;
    case 36:
        out = "Bw2 ";
        break;
    default:
        break;
    }

    return out;
}

