#include<stdio.h>
int x,y,z;
int main()
{
	while(scanf("%d%d%d",&x,&y,&z)!=EOF)
	{
		int maxx=-1;
		for(int i=1;;i++)
		{
			if(y*i+(i+1)*z<=x) maxx=i;
			else break;
		}
		printf("%d\n",maxx);
	}
	return 0;
}