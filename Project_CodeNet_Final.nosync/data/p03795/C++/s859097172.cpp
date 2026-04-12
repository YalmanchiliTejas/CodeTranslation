#include <stdio.h>

int main(void)
{
	int n1,nx,ny,na;
	
	scanf("%d",&n1);
	
	nx=800*n1;
	ny=(n1/15)*200;
	na=nx-ny;
	printf("%d",na);
	
	return 0;
}