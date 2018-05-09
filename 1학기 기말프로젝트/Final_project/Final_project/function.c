#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define num 100
#define max 20
typedef struct
{                   
	char name[20];                   
	long id;                   
	float score; 
} STUDENT;

STUDENT *student[num];
int length;
int delnum;


void inputstudent(FILE *ip)  //�Է¹޴��Լ�
{
	int i;
	char name[max];
	float sc;
	long idd;
	length = 0;

	for(i=0; i<100; i++)
	{
		STUDENT *temp;

		fscanf(ip, "%s %d %f", name, &idd, &sc);
		temp = (STUDENT *) malloc (sizeof(STUDENT) +strlen(name));

		
		if(feof(ip))
			break;
		
		temp->id = idd;
		temp->score = sc;
		strcpy(temp->name, name);

		student[i] = temp;
		length++;
		
		
		
		
	}

}

int compareid(const void *a, const void *b)  //�й����� ���ϴ� �Լ�, �й��� ����������
{
	STUDENT *st1 = *(STUDENT **)a;
	STUDENT *st2 = *(STUDENT **)b;

	if(st1->id > st2->id)
		return 1;
	else if(st1->id < st2->id)
		return -1;
	else
		return 0;

}

int comparescore(const void *a, const void *b) //������ ���ϴ� �Լ�, ������ �̸��� ������
{
	STUDENT *st1 = *(STUDENT **)a;
	STUDENT *st2 = *(STUDENT **)b;

	if(st1->score > st2->score)
		return 1;
	else if(st1->score < st2->score)
		return -1;
	else
		strcmp(st1->name, st2->name);
}

int comparename(const void *a, const void *b) //�̸��� ������ ����
{
	STUDENT *st1 = *(STUDENT **)a;
	STUDENT *st2 = *(STUDENT **)b;

	strcmp(st1->name, st2->name);
	
}

void printstudent() //����ϴ� �Լ�
{
	int i;

	for(i=0; i<length; i++)
	{
		printf("%s %d %.2f \n", student[i]->name, student[i]->id, student[i]->score);
	}
}

void fprintstudent()  //���Ͽ�����ϴ� �Լ�
{
	int i;

	FILE *ip;
	ip = fopen("student.db", "r+");

	for(i=0; i<length; i++)
	{
		
		fprintf(ip, "%s %d %.2f \n", student[i]->name, student[i]->id, student[i]->score);
	}

	fclose(ip);
}

void fprintstudent2()  //���Ͽ� �����Ҷ� ����ϴ� �Լ�
{
	int i;

	FILE *ip;
	ip = fopen("student.db", "w");

	for(i=0; i<length-1; i++)
		fprintf(ip, "%s %d %.2f \n", student[i]->name, student[i]->id, student[i]->score);
	

	fclose(ip);
}


void idprint()  //�й��� ���
{
	int i;

	FILE *ip;
	ip = fopen("student.db", "r+");

	inputstudent(ip);
	qsort(student, length, sizeof(STUDENT *), compareid);
	printstudent();

	for(i=0; i<length; i++)
		free(student[i]);
}

void scoreprint()  //���������
{
	int i;

	FILE *ip;
	ip = fopen("student.db", "r+");

	inputstudent(ip);
	qsort(student, length, sizeof(STUDENT *), comparescore);
	printstudent();

	for(i=0; i<length; i++)
		free(student[i]);
}

void nameprint() //�̸��� ���
{
	int i;

	FILE *ip;
	ip = fopen("student.db", "r+");

	inputstudent(ip);
	qsort(student, length, sizeof(STUDENT *), comparename);
	printstudent();

	for(i=0; i<length; i++)
		free(student[i]);
}

void addstudent()  //�л� �߰�
{
	int i;

	char name[max];
	float sc;
	long idd;
	
	STUDENT *temp;

	FILE *ip;
	ip = fopen("student.db", "r+");

	inputstudent(ip);

	printf("�߰��� �л��� �̸� : ");
	scanf("%s", name);
	printf("�߰��� �л��� �й� : ");
	scanf("%d", &idd);
	printf("�߰��� �л��� ���� : ");
	scanf("%f", &sc);
	fflush(stdin);
	temp = (STUDENT *) malloc (sizeof(STUDENT) +strlen(name));

	temp->id = idd;
	temp->score = sc;
	strcpy(temp->name, name);

	student[length] = temp;
	length++;

	fprintstudent();

	
}

void deletestudent()  //�л� ����
{
	int i;

	

	FILE *ip;
	ip = fopen("student.db", "r+");

	inputstudent(ip);
	printstudent();

	printf("���° �л��� �����Ͻðڽ��ϱ�?(���������� 1��)  :  ");
	scanf("%d", &delnum);
	fflush(stdin);
	for(i=delnum-1; i<length; i++)
		student[i] = student[i+1];

	student[length-1] = NULL;
	
	
	fprintstudent2(); 	




	

	
}

void changestudent()  //�л� ����
{
	int i;

	int changenum;

	STUDENT *temp;

	char name[max];
	float sc;
	long idd;

	FILE *ip;
	ip = fopen("student.db", "r+");

	inputstudent(ip);
	printstudent();

	printf("���° �л��� �����Ͻðڽ��ϱ�?(���������� 1��)  :  ");
	scanf("%d", &changenum);

	printf("������ �̸� :  ");
	scanf("%s", name);
	printf("������ �й� :  ");
	scanf("%d", &idd);
	printf("������ ���� :  ");
	scanf("%f", &sc);
	fflush(stdin);
	for(i=delnum-1; i<length; i++)

	temp = (STUDENT *) malloc (sizeof(STUDENT) +strlen(name));

	temp->id = idd;
	temp->score = sc;
	strcpy(temp->name, name);

	student[changenum-1] = temp;

	fprintstudent();
}

