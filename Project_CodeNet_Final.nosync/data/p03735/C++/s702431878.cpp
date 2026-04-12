#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct xxx{long long x,y;}d[201000];
bool cmp(xxx a,xxx b){return a.x<b.x;}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&d[i].x,&d[i].y);
		if(d[i].x>d[i].y)swap(d[i].x,d[i].y);
	}
	sort(d+1,d+n+1,cmp);
	long long Min1=2e9,Max1=-2e9,Min2=2e9,Max2=-2e9,ans=2e18,Min3=2e9,Max3=-2e9;
	for(int i=1;i<=n;i++)
	{
		Min1=min(Min1,d[i].x);
		Max1=max(Max1,d[i].x);
		Min2=min(Min2,d[i].y);
		Max2=max(Max2,d[i].y);
	}
	ans=min(ans,(Max1-Min1)*(Max2-Min2));
	for(int i=1;i<n;i++)
	{
		Max3=max(Max3,d[i].y);Min3=min(Min3,d[i].y);
		ans=min(ans,(max(Max2,d[i].x)-d[1].x)*(max(Max3,d[n].x)-min(Min3,d[i+1].x)));
	}
	printf("%lld",ans);return 0;
}