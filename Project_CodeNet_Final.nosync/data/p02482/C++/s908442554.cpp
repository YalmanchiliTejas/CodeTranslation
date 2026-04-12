#include<stdio.h>
int main(void)
{
	int a,b,c,d;
	scanf("%d %d",&c,&d);
	if (c<d){
		printf("a < b\n");
	}
	else if(c>d){
		printf("a > b\n");
	}
	else if(c==d){
		printf("a == b\n");
	}
	return 0;
}