#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"������ͷ�ļ�(�����붨��).h"

//���˵�
void menu()
{
	printf("***************************\n");
	printf("***************************\n");
	printf("*****     1.play      *****\n");
	printf("*****     2.exit      *****\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("***************************\n");
}
//��Ϸ����
void play()
{
//��������
	char Q[H][L];
//��ʼ������

	cleanQ(Q,H, L);
//��ӡ����

	displayQ(Q, H,L);
//������Ϸ״̬
	char ret = 0;
	while (1)
	{
		//�������
		Pmove(Q, H, L);
			
		displayQ(Q, H, L);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(Q, H, L);
		if (ret != 'C')
			break;
		//������
		Cmove(Q, H, L);

		displayQ(Q, H, L);

		ret = IsWin(Q, H, L);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}




}


int main()
{
	int i = 0;
	do {
		menu();
		printf("��ѡ��\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			play();
//��ʼ��Ϸ
			break;
		case 2:
			printf("�˳���Ϸ\n");
				break;
		default:
			printf("����������\n");
			break;
		}

	}while (i);
	return 0;
}
