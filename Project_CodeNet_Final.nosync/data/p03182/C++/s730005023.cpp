#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=10000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define eps 1e-8
struct node{int l,r;ll a;}seg[200200];
bool operator<(node p,node q) {return p.r<q.r;}
int n,m;
ll mx[1600800],tag[1600800];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

void pushdown(int id,int l,int r)
{
	if (tag[id]!=0)
	{
		tag[id<<1]+=tag[id];tag[id<<1|1]+=tag[id];
		mx[id<<1]+=tag[id];mx[id<<1|1]+=tag[id];
		tag[id]=0;
	}
}

void modify(int id,int l,int r,int ql,int qr,ll val)
{
	pushdown(id,l,r);
	if ((l>=ql) && (r<=qr))
	{
		mx[id]+=val;tag[id]+=val;
		return;
	}
	int mid=(l+r)>>1;
	if (ql<=mid) modify(id<<1,l,mid,ql,qr,val);
	if (qr>mid) modify(id<<1|1,mid+1,r,ql,qr,val);
	mx[id]=max(mx[id<<1],mx[id<<1|1]);
}

ll query(int id,int l,int r,int ql,int qr)
{
	pushdown(id,l,r);
	if ((l>=ql) && (r<=qr)) return mx[id];
	int mid=(l+r)>>1;ll ans=0;
	if (ql<=mid) ans=max(ans,query(id<<1,l,mid,ql,qr));
	if (qr>mid) ans=max(ans,query(id<<1|1,mid+1,r,ql,qr));
	return ans;
}

signed main()
{
	n=read();m=read();
	rep(i,1,m)
	{
		seg[i].l=read();seg[i].r=read();seg[i].a=read();
	}
	sort(seg+1,seg+1+m);
	int pos=1;
	rep(i,1,n)
	{
		modify(1,1,n,i,i,query(1,1,n,1,i));
		while ((pos<=m) && (seg[pos].r==i))
		{
			modify(1,1,n,seg[pos].l,seg[pos].r,seg[pos].a);
			pos++;
		}
	}
	ll ans=max(0ll,query(1,1,n,1,n));
	printf("%lld",ans);
	return 0;
}
