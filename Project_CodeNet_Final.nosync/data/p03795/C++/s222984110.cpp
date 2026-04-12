#include<cstdio>
int main()
{
	int x,y,N;
	scanf("%d",&N);
	x=N*800;
	y=200*((N-(N%15))/15);
	printf("%d",x-y);
	return 0;
}