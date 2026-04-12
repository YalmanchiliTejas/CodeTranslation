#include<stdio.h>
int main()
{
	int x,y,z,sum;
	while(scanf("%d%d%d",&x,&y,&z)!=EOF)
	{
		sum=(x-(y+2*z))/(y+z)+1;
		printf("%d\n",sum);
	}
}