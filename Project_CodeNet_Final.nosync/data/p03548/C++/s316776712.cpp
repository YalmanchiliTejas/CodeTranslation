#include<stdio.h>
int main()
{
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	int ans=x/(y+z);
	if(x%(y+z)<z)
	{
		ans--;
		printf("%d\n",ans);
	}
	else printf("%d\n",ans);
	return 0;
}