#include "Game.h"


int check_for_win(int board[])
{
	if (check_for_player(board, X_TURN))
	{
		//printf("X WON\n");
		return X_TURN;
	}
	else if (check_for_player(board, O_TURN))
	{
		//printf("O WON\n");
		return O_TURN;
	}
	else if (!getEmptySpots(board))
	{
		return TIE;
	}
	return NONE;
}


bool check_for_player(int board[], int turn)
{
	int i = 0, j = 0, count = 0;
	int possible_wins[][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 4, 8}, {2, 4, 6}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8} };
	for (i = 0; i < 8; i++)
	{
		count = 0;
		for (j = 0; j < WIN; j++)
		{
			if (board[possible_wins[i][j]] == turn)
			{
				count++;
			}
		}
		if (count == WIN)
		{
			return true;
		}
	}
	return false;
}


int switchTurns(int turn)
{
	return -turn;
}
