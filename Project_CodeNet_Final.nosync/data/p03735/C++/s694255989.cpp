#include<bits/stdc++.h>
using namespace std;
long long n;
pair<long long,long long>a[200005];
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].first,&a[i].second);
		if(a[i].first>a[i].second)swap(a[i].first,a[i].second);
	}
	sort(a+1,a+n+1);
	long long mnf=1e18,mns=1e18,mxf=-1e18,mxs=-1e18;
	for(int i=1;i<=n;i++)mnf=min(mnf,a[i].first);
	for(int i=1;i<=n;i++)mxf=max(mxf,a[i].first);
	for(int i=1;i<=n;i++)mns=min(mns,a[i].second);
	for(int i=1;i<=n;i++)mxs=max(mxs,a[i].second);
	long long ans=(mxf-mnf)*(mxs-mns),nw=1e18;
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,(mxs-mnf)*(mxf-min(nw,a[i].first)));
		nw=min(nw,a[i].second);
		mxf=max(mxf,a[i].second);
	}
	printf("%lld\n",ans);
	return 0;
}