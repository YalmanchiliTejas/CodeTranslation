#include<cstdio>
int sum,n;
int main()
{
	scanf("%d",&n);
	sum=n*800;
	while(n>=15){sum-=200;n-=15;}
	printf("%d\n",sum);
	return 0;
}