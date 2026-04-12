#include<stdio.h>
#include<string.h>

int yama=0;
int head[101]={0};
char mozi[101][1001];

void push();
void pop();
void move();

int main()
{
	char act[10];
	int num;
	
	scanf("%d",&num);
	while(1){
		scanf("%s",act);
		if(strcmp(act,"quit")==0)
			break;
		else if(strcmp(act,"push")==0)
			push();
		else if(strcmp(act,"pop")==0)
			pop();
		else if(strcmp(act,"move")==0)
			move();
	}
	return 0;
}

void push()
{
	char c;
	int  num;
	scanf("%d",&num);
	scanf(" %c",&c);
	mozi[num][head[num]]=c;
	head[num]++;
}

void pop()
{
	int  num;
	scanf("%d",&num);
	head[num]--;
	printf("%c\n",mozi[num][head[num]]);
}

void move()
{
	int num1,num2;
	scanf("%d %d",&num1,&num2);
	head[num1]--;
	mozi[num2][head[num2]]=mozi[num1][head[num1]];
	head[num2]++;
}