#include<bits/stdc++.h>
#include<algorithm>
#include<stdio.h>
#define ll long long
#define rg register
#define INF 0x3f3f3f3f
using namespace std;
struct node{
	ll x,y;
}a[200001];
ll ans1,ans2=INF,maxl=-1,maxr=-1,minl=INF,minr=INF,x[200001],y[200001],n;
ll maxx[200001],minn[200001];
bool cmp(const node &one,const node &two){return one.x<two.x;}
int main()
{
	scanf("%lld",&n);
	for(rg ll u=1;u<=n;u+=1)
	{
		scanf("%lld %lld",&x[u],&y[u]);
		if(x[u]>y[u])swap(x[u],y[u]);
		maxl=max(maxl,x[u]);
		minl=min(minl,x[u]);
		maxr=max(maxr,y[u]);
		minr=min(minr,y[u]);
		a[u].x=x[u];a[u].y=y[u];
	}
	ans1=(maxl-minl)*(maxr-minr);
	sort(a+1,a+n+1,cmp);
	maxx[1]=minn[1]=a[1].y;
	for(rg ll u=2;u<n;u+=1)
	{
		maxx[u]=max(maxx[u-1],a[u].y);
		minn[u]=min(minn[u-1],a[u].y);
		ans2=min(ans2,max(maxx[u],a[n].x)-min(minn[u],a[u+1].x));
	}
	ans2*=(maxr-minl);
	printf("%lld",min(ans1,ans2));
	return 0;
}