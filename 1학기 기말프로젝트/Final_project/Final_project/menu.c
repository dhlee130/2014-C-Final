#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "myheader.h"

#define num 100

typedef struct
{                   
	char name[20];                   
	long id;                   
	float score; 
} STUDENT;

STUDENT *student[num];
int length;
char trash;

void main()
{
	int input;

	
	

	while(1)
	{
		printf("****************************************\n");
		printf("Menu\n");
		printf("1.����ϱ�\n");
		printf("2.�����ϱ�\n");
		printf("3.����\n");
		printf("****************************************\n");
			
		printf("\n��ȣ�� �Է��Ͻÿ�.\n");
		scanf("%d", &input);
		system("cls");

		if(input == 1)
		{
			while(1)
			{
				printf("****************************************\n");
				printf("Menu\n");
				printf("1.�̸���\n");
				printf("2.�й���\n");
				printf("3.������\n");
				printf("4.�ڷ�\n");
				printf("****************************************\n");
			
				printf("\n��ȣ�� �Է��Ͻÿ�.\n");
				scanf("%d", &input);
				fflush(stdin);
				if(input == 1)
				{
					system("cls");
					printf("�̸��� ���\n");
					nameprint();
					printf("\n\n����Ϸ��� ����!");
					scanf("%c", &trash);
					system("cls");
				}

				else if(input == 2)
				{
					system("cls");
					printf("�й��� ���\n");
					idprint();
					printf("\n\n����Ϸ��� ����!");
					scanf("%c", &trash);
					system("cls");
				}

				else if(input == 3)
				{
					system("cls");
					printf("������ ���\n");
					scoreprint();
					printf("\n\n����Ϸ��� ����!");
					scanf("%c", &trash);
					system("cls");
				}

				else if(input == 4)
				{
					system("cls");
					break;
				}
			}
		}

		else if(input == 2)
		{
			while(1)
			{
				printf("****************************************\n");
				printf("Menu\n");
				printf("1.�߰�\n");
				printf("2.����\n");
				printf("3.����\n");
				printf("4.�ڷ�\n");
				printf("****************************************\n");
			
				printf("\n��ȣ�� �Է��Ͻÿ�.\n");
				scanf("%d", &input);
				fflush(stdin);
				system("cls");
				if(input == 1)
				{
					addstudent();
					system("cls");
					printf("\n\n�����Ϸ�!!!!!\n\n");
					printf("\n\n����Ϸ��� ����!");
					scanf("%c", &trash);
					system("cls");
				}

				else if(input == 2)
				{
					changestudent();
					system("cls");
					printf("\n\n�����Ϸ�!!!!!\n\n");
					printf("\n\n����Ϸ��� ����!");
					scanf("%c", &trash);
					system("cls");
				}

				else if(input == 3)
				{
					deletestudent();
					system("cls");
					printf("\n\n�����Ϸ�!!!!!\n\n");
					printf("\n\n����Ϸ��� ����!");
					scanf("%c", &trash);
					system("cls");
				}

				else if(input == 4)
				{
					system("cls");
					break;
				}
			}
		}

		else if(input == 3)
			break;
 	}
}