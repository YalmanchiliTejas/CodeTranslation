#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=2000001000;
int main()
{
	int a,b,c,x,y;
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	if (x<=y)
	{
		int ans=INF;
		for (int i=0;i<=y;i++)
		{
			int tmp=c*i*2+max(x-i,0)*a+max(y-i,0)*b;
			ans=min(ans,tmp);
		}
		printf("%d\n",ans);
	}
	else
	{
		int ans=INF;
		for (int i=0;i<=x;i++)
		{
			int tmp=c*i*2+max(x-i,0)*a+max(y-i,0)*b;
			ans=min(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
} 