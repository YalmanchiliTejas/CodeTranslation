#include<stdio.h>
#include<stdlib.h>
bool F(int t,int e,int x)
{
	for(int a=0; a<=t+e; a+=x)
	{
		if(abs(a-t)<=e)
			return true;
	}
	return false;
}
int main()
{
	int n,t,e,x;
	scanf("%d%d%d",&n,&t,&e);
	for(int i=1;i<=n; ++i)
	{
		scanf("%d",&x);
		if(F(t,e,x))
		{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}