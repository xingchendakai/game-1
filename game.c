#include "game.h"
void initboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}
void printboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void playermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("请玩家落子");
	while (1)
	{
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入->\n");
			}
		}
		else
		{
			printf("该坐标非法，请重新输入->\n");
		}
	}
}
void computermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("电脑落子\n");
	while (1)
	{
		x = rand()%row;
		y = rand()%col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
		
}
int isfull(char board[ROW][COL], int row, int col)
{
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			if (board[x][y] == ' ')
				return 0;
		}
	}
	return 1;
}
char esucceed(char board[ROW][COL], int row, int col)
{
	for (int x = 0; x < row; x++)
	{
		if (board[x][0] == board[x][1] && board[x][1] == board[x][2] && board[x][0] != ' ')
			return board[x][0];
	}
	for (int y = 0; y < col; y++)
	{
		if (board[0][y] == board[1][y] && board[1][y] == board[2][y] && board[0][y] != ' ')
			return board[0][y];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	if (1 == isfull(board, ROW, COL))
		return 'Q';
	return 'c';
}