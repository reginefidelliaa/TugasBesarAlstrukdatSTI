#include <stdio.h>
#include <stdlib.h>
#include "../ADT/arraydin.h"

#ifndef COMMAND_H
#define COMMAND_H

extern int command;
extern ArrayDin ListGame;

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

#endif