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
		//�ж��Ƿ�ʤ��
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
		printf("���Ӯ\n");
	else if (ret == '#')
		printf("����Ӯ\n");
	else
		printf("ƽ��\n");
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
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);

}
int main()
{
	
	test();
	return 0;
}