#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
#define R register
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int inf=1e9+7,$=2e5+5;
struct node{
	ll x,y;
}ball[$];
ll x[$],y[$],maxn[$],minl[$];
ll n,ans,ans1,ans2,bmax,bmin,rmax,rmin;
inline bool cmp(node a,node b){return a.x<b.x;}
void init(){
	n=read();
	bmax=rmax=-1,bmin=rmin=inf;
}

signed main(){
	init();
	for (R int i(1);i<=n;++i){
		x[i]=read(),y[i]=read();
		if (x[i]>y[i]) swap(x[i],y[i]);
		ball[i].x=x[i],ball[i].y=y[i];
		bmax=max(bmax,y[i]),bmin=min(bmin,y[i]);
		rmax=max(rmax,x[i]),rmin=min(rmin,x[i]);
	}
	ans1=(bmax-bmin)*(rmax-rmin);
	bmin=rmin;
	sort(ball+1,ball+n+1,cmp);
	ans2=inf,maxn[1]=minl[1]=ball[1].y;
	for (R int i(2);i<=n;++i){
		maxn[i]=max(maxn[i-1],ball[i].y);
		minl[i]=min(minl[i-1],ball[i].y);
		if (i!=n) ans2=min(ans2,max(maxn[i],ball[n].x)-min(minl[i],ball[i+1].x));
	}
	ans2*=(bmax-bmin);
	ans=min(ans1,ans2);
	printf("%lld\n",ans);
	return 0; 
}
