#include "PCH.h"

int main(int argc, char* argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s [current_board] [player_move]\n", argv[0]);
		return 1;
	}

	
	int board[BOARD_SIZE*BOARD_SIZE] = { 0 };

	for (int i = 0; i < 9; i++)
	{
		board[i] = argv[1][i * 2] - '0';
		if (board[i] == 2)
		{
			board[i] = O_TURN;
		}
//		printf(" %d %d\n", board[i], argv[1][i * 2]);
	}


	int turn = O_TURN, pos = 0, winner = 0, playerTurn = 0;

	do
	{
		if (turn == X_TURN)
		{
			print_board(board);
			printf("Best move is for %c is %d\n", convert(turn), getMove(board, turn, turn, true) + 1); // suggestion for user

			pos = checkPos(board);

			pos--; // making pos - 1 to match board
		}
		else
		{
			print_board(board);
			return getMove(board, turn, turn, true); // getting bot move

		}

		board[pos] = turn; // making move
		turn = switchTurns(turn); // switching turns

		winner = checkForWin(board); // getting winner

	} while (winner == NO_WIN); // checking if game ended

	print_board(board);
	if (winner == TIE)
	{
		printf("TIE!");
	}
	else
	{
		printf("%c won!", convert(checkForWin(board)));
	}
	printf("\n\nPress any key to exit.");

	getchar();
	return 0;
}