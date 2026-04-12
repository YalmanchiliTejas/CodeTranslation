#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

#define R register
#define ll long long

const ll inf=(1LL<<60);
const int MAXN=2e5+10;

int n;
struct Pair
{
	int x,y;
}p[MAXN];

ll ans=inf;
int a[MAXN],b[MAXN];

inline void solve1()
{
	for(R int i=1;i<=n;i++)
	a[i]=p[i].x,b[i]=p[i].y;
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	ll res=(ll)(a[n]-a[1])*(b[n]-b[1]);
	if(res<ans) ans=res;
}

struct Segment_Tree
{
	int mx[MAXN<<2],mn[MAXN<<2];
	inline int ls(int x) { return x<<1; }
	inline int rs(int x) { return x<<1|1; }
	inline void update(int x)
	{
		mx[x]=max(mx[ls(x)],mx[rs(x)]);
		mn[x]=min(mn[ls(x)],mn[rs(x)]);
	}
	inline void chg(int x,int l,int r,int ad,int k)
	{
		if(l==r)
		{
			mn[x]=mx[x]=k;
			return;
		}
		int mid=l+r;mid>>=1;
		if(ad<=mid) chg(ls(x),l,mid,ad,k);
		else chg(rs(x),mid+1,r,ad,k);
		update(x);
	}
	inline int findmin()
	{
		return mn[1];
	}
	inline int findmax()
	{
		return mx[1];
	}
}Tr,Tb;

inline bool cmp(Pair p1,Pair p2)
{
	if(p1.x==p2.x) return p1.y<p2.y;
	return p1.x<p2.x;
}

int tag[MAXN];

inline void solve2()
{
	sort(p+1,p+1+n,cmp);
	int mxnode=-1,mxnum1=-1,mxnum2=-1;
	for(R int i=1;i<=n;i++)
	{
		if(p[i].y>mxnum1)
		{
			mxnode=i;
			mxnum1=p[i].y;
			mxnum2=p[i].x;
			continue;
		}
		if(p[i].y==mxnum1)
		{
			if(p[i].x>mxnum2)
			{
				mxnode=i;
				mxnum2=p[i].x;
				continue;
			}
		}
	}
	tag[mxnode]=1;
	swap(p[1].x,p[1].y);
	tag[1]=1;
	for(R int i=1;i<=n;i++)
	{
		Tb.chg(1,1,n,i,p[i].x);
		Tr.chg(1,1,n,i,p[i].y);
	}
	ll res=(ll)(Tb.findmax()-Tb.findmin())*(Tr.findmax()-Tr.findmin());
	if(res<ans) ans=res;
	for(R int i=1;i<=n;i++)
	{
		if(tag[i]) continue;
		Tb.chg(1,1,n,i,p[i].y);
		Tr.chg(1,1,n,i,p[i].x);
		ll tres=(ll)(Tb.findmax()-Tb.findmin())*(Tr.findmax()-Tr.findmin());
		if(tres<ans) ans=tres;
	}
}

int main()
{
	scanf("%d",&n);
	for(R int i=1;i<=n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		p[i].x=x;
		p[i].y=y;
	}
	solve1();
	solve2();
	printf("%lld\n",ans);
	return 0;
}