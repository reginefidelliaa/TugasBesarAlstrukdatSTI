#include "command.h"
#include "ADT/array.c"
#include "ADT/mesinkata.c"

FILE *file = NULL;

void START(){
    file = "..//player//default.txt";
    STARTWORD();
    for(int i = 0; i < currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }

}

void LOAD();

void SAVE();

void CREATEGAME();

void LISTGAME();

void DELETEGAME();

void QUEUEGAME();

void PLAYGAME();

void SKIPGAME();

void QUIT();

void HELP();

void COMMANDLAIN()
{
    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
}