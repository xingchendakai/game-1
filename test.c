#include "game.h"
void game()
{
	char ret=0;
	char board[ROW][COL];
	initboard(board,ROW,COL);
	printboard(board, ROW, COL);
	while (1)
	{
		playermove(board, ROW, COL);
		printboard(board, ROW, COL);
		//判断是否胜利
		ret =esucceed(board,ROW,COL);
		if (ret != 'c')
			break;
		computermove(board, ROW, COL);
		printboard(board, ROW, COL);
		ret = esucceed(board, ROW, COL);
		if (ret != 'c')
			break;
	}
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else
		printf("平局\n");
}
void menu()
{
	printf("*********************\n");
	printf("****1.play 0.exit****\n");
	printf("*********************\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);

}
int main()
{
	
	test();
	return 0;
}