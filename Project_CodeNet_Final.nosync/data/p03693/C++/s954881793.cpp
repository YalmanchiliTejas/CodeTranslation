#include<stdio.h>
int main(void)
{
	int r,g,b,x;
	scanf("%d",&r);
	scanf("%d",&g);
	scanf("%d",&b);
	x=(r*100)+(g*10)+(b);
	if(x%4==0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
