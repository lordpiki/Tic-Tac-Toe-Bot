#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "Minimax.h"

#define X_TURN 1
#define O_TURN -1

#define TIE 0
#define NONE 2
#define WIN 3

#define BOARD_SIZE 3

int check_for_win(int board[]);
bool check_for_player(int board[], int turn);
int switchTurns(int turn);
