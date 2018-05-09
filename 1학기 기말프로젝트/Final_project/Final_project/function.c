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


void inputstudent(FILE *ip)  //입력받는함수
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

int compareid(const void *a, const void *b)  //학번으로 비교하는 함수, 학번은 같을수없음
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

int comparescore(const void *a, const void *b) //성적을 비교하는 함수, 같으면 이름의 사전순
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

int comparename(const void *a, const void *b) //이름의 사전순 정렬
{
	STUDENT *st1 = *(STUDENT **)a;
	STUDENT *st2 = *(STUDENT **)b;

	strcmp(st1->name, st2->name);
	
}

void printstudent() //출력하는 함수
{
	int i;

	for(i=0; i<length; i++)
	{
		printf("%s %d %.2f \n", student[i]->name, student[i]->id, student[i]->score);
	}
}

void fprintstudent()  //파일에출력하는 함수
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

void fprintstudent2()  //파일에 제거할때 출력하는 함수
{
	int i;

	FILE *ip;
	ip = fopen("student.db", "w");

	for(i=0; i<length-1; i++)
		fprintf(ip, "%s %d %.2f \n", student[i]->name, student[i]->id, student[i]->score);
	

	fclose(ip);
}


void idprint()  //학번순 출력
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

void scoreprint()  //성적순출력
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

void nameprint() //이름순 출력
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

void addstudent()  //학생 추가
{
	int i;

	char name[max];
	float sc;
	long idd;
	
	STUDENT *temp;

	FILE *ip;
	ip = fopen("student.db", "r+");

	inputstudent(ip);

	printf("추가할 학생의 이름 : ");
	scanf("%s", name);
	printf("추가할 학생의 학번 : ");
	scanf("%d", &idd);
	printf("추가할 학생의 성적 : ");
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

void deletestudent()  //학생 제거
{
	int i;

	

	FILE *ip;
	ip = fopen("student.db", "r+");

	inputstudent(ip);
	printstudent();

	printf("몇번째 학생을 삭제하시겠습니까?(위에서부터 1번)  :  ");
	scanf("%d", &delnum);
	fflush(stdin);
	for(i=delnum-1; i<length; i++)
		student[i] = student[i+1];

	student[length-1] = NULL;
	
	
	fprintstudent2(); 	




	

	
}

void changestudent()  //학생 수정
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

	printf("몇번째 학생을 수정하시겠습니까?(위에서부터 1번)  :  ");
	scanf("%d", &changenum);

	printf("변경할 이름 :  ");
	scanf("%s", name);
	printf("변경할 학번 :  ");
	scanf("%d", &idd);
	printf("변경할 점수 :  ");
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

