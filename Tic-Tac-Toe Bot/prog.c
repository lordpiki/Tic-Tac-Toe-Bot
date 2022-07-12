/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include "PCH.h"

int main(void)
{
	int board[BOARD_SIZE*BOARD_SIZE] = { 0 };
	int turn = X_TURN, pos = 0;
	
	do
	{
		
		if (turn == X_TURN)
		{
			print_board(board);
			printf("Best move is for %d is %d\n", turn, getMove(board, turn, turn, true) +1);
			
			printf("\nPlease enter your turn: ");
			scanf("%d", &pos);
			pos--;
			getchar();
		}
		else
		{
			pos = getMove(board, turn, turn, true);
			printf("\nO is choosing %d", pos + 1);
		}

		board[pos] = turn;
		turn = switchTurns(turn);

		
	} while (check_for_win(board) == NONE);
	print_board(board);
	printf("%c won!", convert(check_for_win(board)));

	getchar();
	return 0;
}