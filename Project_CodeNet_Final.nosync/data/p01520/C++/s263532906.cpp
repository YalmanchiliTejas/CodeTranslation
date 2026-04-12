#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(void)
{
	int n,t,e,i,j,flg,suu,x[100],xx;
	scanf("%d %d %d",&n,&t,&e);

	for(i=0;i<n;i++)	{
		scanf("%d",&x[i]);
	}
	suu=-1;
	for(i=0;i<n;i++)	{
		flg=0;
		xx=x[i];
		while(xx<=t+e)	{
			if(xx>=t-e && xx<=t+e)	{
				suu=i+1;
				flg=1;
				break;
			}
			xx+=x[i];
		}
		if(flg==1)	break;
	}
	printf("%d\n",suu);
	return 0;
}
