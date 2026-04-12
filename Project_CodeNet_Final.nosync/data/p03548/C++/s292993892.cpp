#include <stdio.h>
int main()
{
	int x,y,z,t,i,n;
	scanf("%d %d %d",&x,&y,&z);
	n=x/y;
	for(i=n;i>=1;i--)
	{
		if(i*y+(i+1)*z<=x)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}