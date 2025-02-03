#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "scramble.h"

int main()
{
    int choice;
    mainMenu();
    
    while(choice != 8)
    {
        scanf("%d", &choice);
    }
    return 0;
}