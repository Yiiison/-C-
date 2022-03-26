#define _CRT_SECURE_NO_WARNINGS 1
#include"������ͷ�ļ�(�����붨��).h"

void cleanQ(char Q[H][L], int h, int l)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < h; i++)
	{
		for (j = 0; j < l; j++)
		{
			Q[i][j] = ' ';
		}
	}

}

void displayQ(char Q[H][L], int h, int l)
{
	int i = 0;
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0;j < h;j++)
		{
			printf(" %c ", Q[i][j]);
			if (j < l - 1)
				printf("|");
		}
		printf("\n");
		if (i < h - 1)
		{
			int j = 0;
			for (j = 0;j < l; j++)
			{

				printf("---");
				if (j < l - 1)
					printf("|");

			}
			printf("\n");
		}
	}
}

void Pmove(char Q[H][L], int h, int l)
{
	int x = 0;
	int y = 0;
	printf("�����");
		while (1)
		{
			printf("��������������(�Կո����)��");
			scanf("%d %d", &x, &y);
			if (x >= 1 && x <= h && y >= 1 && y <= l)
			{
				if (Q[x - 1][y - 1] == ' ')
				{
					Q[x - 1][y - 1] = '*';
						break;
				}
				else
				{
					printf("λ�ô�������������\n");
				}
			}
		}
}
void Cmove(char Q[H][L], int h, int l)
{
	printf("������\n");
	while (1)
	{
		int x = rand() % H;
		int y = rand() % L;
		if (Q[x][y] == ' ')
		{
				Q[x][y] = '#';
				break;
		}
			
		
		
	}
}




int IsFull(char Q[H][L], int h, int l)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < l; j++)
		{
			if (Q[i][j] == ' ')
			{
				return 0;//����û��
			}
		}
	}

	return 1;//��������
}

char IsWin(char Q[H][L], int h, int l)
{
	int i = 0;
	//�ж�����
	for (i = 0; i < h; i++)
	{
		if (Q[i][0] ==Q[i][1] && Q[i][1] ==Q[i][2] && Q[i][1] != ' ')
		{
			return Q[i][1];//
		}
	}

	//�ж�����
	for (i = 0; i < l; i++)
	{
		if (Q[0][i] ==Q[1][i] && Q[1][i] == Q[2][i] && Q[1][i] != ' ')
		{
			return Q[1][i];
		}
	}

	//�ж϶Խ���
	if (Q[0][0] == Q[1][1] && Q[1][1] ==Q[2][2] &&Q[1][1] != ' ')
	{
		return Q[1][1];
	}
	if (Q[0][2] == Q[1][1] && Q[1][1] == Q[2][0] &&Q[1][1] != ' ')
	{
		return Q[1][1];
	}

	//�ж�ƽ��
	//����������˷���1�� ��������0
	int ret = IsFull(Q,h,l);
	if (ret == 1)
	{
		return 'Q';
	}

	//����
	return 'C';
}