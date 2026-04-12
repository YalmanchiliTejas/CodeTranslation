#include<stdio.h>
int main(void)
{
	int a,b,c,x,y,z,ans;
	scanf("%d %d %d",&a,&b,&c);
	x=a*100;
	y=b*10;
	z=x+y+c;
	if(z%4==0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}