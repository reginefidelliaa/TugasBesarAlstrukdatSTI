#include <stdio.h>
#include <stdlib.h>
#include "../ADT/arraydin.h"
#include "../ADT/queue.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkar.h"

#ifndef COMMAND_H
#define COMMAND_H

extern int command;
extern ArrayDin ListGame;
extern Queue GameQueue;
extern char *userplaygame;

void mainmenu();

void commandconfig();

void commandmenu();

void STARTBNMO();

void LOADBNMO();

void SAVE();

void CREATEGAME();

void LISTGAME();

void DELETEGAME();

void QUEUEGAME();

void PLAYGAME();

void SKIPGAME();

void QUIT();

void HELP();

void COMMANDLAIN();

void DisplayGame();

int stringtoint(char *string);

void WelcomeBNMO(FILE *w);

#endif