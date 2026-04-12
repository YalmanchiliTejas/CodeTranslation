#include<stdio.h>
int main(void)
{
	int r,g,b,n;
	scanf("%d %d %d",&r,&g,&b);
	r*=100;
	g*=10;
	n=r+g+b;
	if(n%4==0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
