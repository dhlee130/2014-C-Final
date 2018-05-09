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
		printf("1.출력하기\n");
		printf("2.수정하기\n");
		printf("3.종료\n");
		printf("****************************************\n");
			
		printf("\n번호를 입력하시오.\n");
		scanf("%d", &input);
		system("cls");

		if(input == 1)
		{
			while(1)
			{
				printf("****************************************\n");
				printf("Menu\n");
				printf("1.이름순\n");
				printf("2.학번순\n");
				printf("3.성적순\n");
				printf("4.뒤로\n");
				printf("****************************************\n");
			
				printf("\n번호를 입력하시오.\n");
				scanf("%d", &input);
				fflush(stdin);
				if(input == 1)
				{
					system("cls");
					printf("이름순 출력\n");
					nameprint();
					printf("\n\n계속하려면 엔터!");
					scanf("%c", &trash);
					system("cls");
				}

				else if(input == 2)
				{
					system("cls");
					printf("학번순 출력\n");
					idprint();
					printf("\n\n계속하려면 엔터!");
					scanf("%c", &trash);
					system("cls");
				}

				else if(input == 3)
				{
					system("cls");
					printf("성적순 출력\n");
					scoreprint();
					printf("\n\n계속하려면 엔터!");
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
				printf("1.추가\n");
				printf("2.변경\n");
				printf("3.삭제\n");
				printf("4.뒤로\n");
				printf("****************************************\n");
			
				printf("\n번호를 입력하시오.\n");
				scanf("%d", &input);
				fflush(stdin);
				system("cls");
				if(input == 1)
				{
					addstudent();
					system("cls");
					printf("\n\n수정완료!!!!!\n\n");
					printf("\n\n계속하려면 엔터!");
					scanf("%c", &trash);
					system("cls");
				}

				else if(input == 2)
				{
					changestudent();
					system("cls");
					printf("\n\n수정완료!!!!!\n\n");
					printf("\n\n계속하려면 엔터!");
					scanf("%c", &trash);
					system("cls");
				}

				else if(input == 3)
				{
					deletestudent();
					system("cls");
					printf("\n\n수정완료!!!!!\n\n");
					printf("\n\n계속하려면 엔터!");
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