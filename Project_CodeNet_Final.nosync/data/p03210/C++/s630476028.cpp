#include<stdio.h>
int main(void)
{
	int x;
	scanf("%d",&x);
	if(x==7){
		printf("YES\n");
	}
	if(x==5){
		printf("YES\n");
	}
	if(x==3){
		printf("YES\n");
	}
	if(!(x==7 || x==5 ||x==3)){
		printf("NO\n");
	}
	return 0;
}