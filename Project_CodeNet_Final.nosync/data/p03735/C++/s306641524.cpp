#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

typedef long long LL;

int n,mx,mn;
int minn,maxx;
pair<int,int> a[210000];
LL ans;
int main()
{
	scanf("%d",&n);
	mx=-1e9,mn=1e9;
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].first,&a[i].second);
		if (a[i].first>a[i].second) swap(a[i].first,a[i].second);
		mx=max(mx,a[i].second);
		mn=min(mn,a[i].second);
	}
	sort(a+1,a+1+n);
	ans=(LL)(a[n].first-a[1].first)*(LL)(mx-mn);
	minn=maxx=a[1].second;
	for (int i=2;i<=n;i++)
	{
		ans=min(ans,(LL)(mx-a[1].first)*(LL)(max(maxx,a[n].first)-min(minn,a[i].first)));
		minn=min(minn,a[i].second);
		maxx=max(maxx,a[i].second);
	}
	printf("%lld\n",ans);
	return 0;
}