#include<bits/stdc++.h>
using namespace std;

#define MAXN 200010

int n;
long long ans;
pair<int,int> a[MAXN];
multiset<int> x,y;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		x.insert(a[i].first=min(p,q));
		y.insert(a[i].second=max(p,q));
	}
	sort(a+1,a+n+1);
	ans=((long long)*x.rbegin()-*x.begin())*(*y.rbegin()-*y.begin());
	for (int i=1; i<=n; ++i)
	{
		x.erase(x.find(a[i].first)); y.insert(a[i].first);
		y.erase(y.find(a[i].second)); x.insert(a[i].second);
		ans=min(ans,((long long)*x.rbegin()-*x.begin())*(*y.rbegin()-*y.begin()));
	}
	printf("%lld\n",ans);
}
