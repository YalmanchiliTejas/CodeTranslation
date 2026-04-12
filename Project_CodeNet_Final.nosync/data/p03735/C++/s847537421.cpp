#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
#define MAX 200200
#define lson (now<<1)
#define rson (now<<1|1)
const int inf=1e9;
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int n,Rmin,Rmax,Bmin,Bmax;ll ans=2e18;
struct Node{int x,y;}a[MAX];
bool operator<(Node a,Node b){if(a.x!=b.x)return a.x>b.x;return a.y>b.y;}
struct SegMentTree
{
	int t1[MAX<<2],t2[MAX<<2],a[MAX];
	void pushup(int now){t1[now]=max(t1[lson],t1[rson]);t2[now]=min(t2[lson],t2[rson]);}
	void Build(int now,int l,int r)
	{
		if(l==r){t1[now]=t2[now]=a[l];return;}
		int mid=(l+r)>>1;
		Build(lson,l,mid);Build(rson,mid+1,r);
		pushup(now);
	}
	int Querymx(int now,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)return t1[now];
		int mid=(l+r)>>1,ret=0;
		if(L<=mid)ret=max(ret,Querymx(lson,l,mid,L,R));
		if(R>mid)ret=max(ret,Querymx(rson,mid+1,r,L,R));
		return ret;
	}
	int Querymn(int now,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)return t2[now];
		int mid=(l+r)>>1,ret=1e9;
		if(L<=mid)ret=min(ret,Querymn(lson,l,mid,L,R));
		if(R>mid)ret=min(ret,Querymn(rson,mid+1,r,L,R));
		return ret;
	}
}T;
int main()
{
	n=read();int mn=1e9;
	for(int i=1;i<=n;++i)a[i].x=read(),a[i].y=read();
	for(int i=1;i<=n;++i)if(a[i].x<a[i].y)swap(a[i].x,a[i].y);
	for(int i=1;i<=n;++i)mn=min(mn,a[i].y);
	for(int i=1;i<=n;++i)if(a[i].y==mn){swap(a[i],a[n]);break;}
	Rmin=mn;sort(&a[1],&a[n]);
	for(int i=1;i<n;++i)T.a[i]=a[i].y;
	T.Build(1,1,n-1);
	//Rmax=Max
	for(int i=1;i<n;++i)
	{
		Rmax=a[1].x;
		Bmax=max(a[n].x,max(T.Querymx(1,1,n-1,1,i),a[i+1].x));
		Bmin=min(a[n].x,min(T.Querymn(1,1,n-1,1,i),i==n-1?inf:a[n-1].x));
		ans=min(ans,1ll*(Rmax-Rmin)*(Bmax-Bmin));
	}
	//Bmax=Max
	for(int i=1;i<n;++i)
	{
		Bmax=max(a[n].x,a[1].x);
		Rmax=max(T.Querymx(1,1,n-1,1,i),i==n-1?0:max(T.Querymx(1,1,n-1,i+1,n-1),a[i+1].x));
		Bmin=min(a[n].x,min(i==n-1?inf:a[i+1].y,i==n-2?inf:a[n-1].x));
		ans=min(ans,1ll*(Rmax-Rmin)*(Bmax-Bmin));
	}
	printf("%lld\n",ans);
	return 0;
}
