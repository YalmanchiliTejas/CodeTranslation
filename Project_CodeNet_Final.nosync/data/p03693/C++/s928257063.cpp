#include<stdio.h>
int main(void)
{
	int r,g,b,x,y,z;
	scanf("%d %d %d",&r,&g,&b);
	r=r*100;
	g=g*10;
	x=r+g+b;
	y=x%4;
	if(y==0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}