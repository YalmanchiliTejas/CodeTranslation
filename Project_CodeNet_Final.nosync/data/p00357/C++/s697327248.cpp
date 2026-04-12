#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,d[300001],i,flg1,flg2,mx;
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&d[i]);
	flg1=1;	mx=0;
	for(i=0;i<n-1;i++)	{
		mx=max(mx,i*10+d[i]);
		if(mx<(i+1)*10)	{
			flg1=0;	break;
		}
	}
	for(i=0;i<n/2;i++)	swap(d[i],d[n-i-1]);
	flg2=1;	mx=0;
	for(i=0;i<n-1;i++)	{
		mx=max(mx,i*10+d[i]);
		if(mx<(i+1)*10)	{
			flg2=0;	break;
		}
	}	
	if(flg1==1 && flg2==1)	printf("yes\n");
	else printf("no\n");
	return 0;
}
