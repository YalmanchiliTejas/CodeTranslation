#include<stdio.h>
int main(void)
{
	int s,x,y,n;
	scanf("%d",&n);
	if (n<15){
		x=800*n;
	}
	else{
		x=(800*n)-200*(n/15);
	}
	printf("%d\n",x);
	return 0;
}