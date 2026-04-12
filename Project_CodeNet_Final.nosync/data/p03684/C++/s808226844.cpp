#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define N 100100
using namespace std;

ll n,fa[N],bb,ans;
struct Node
{
	ll x,y,id;
} node[N];
struct Bn
{
	ll a,b,c;
	bool operator < (const Bn u) const
	{
		return c<u.c;
	}
} bn[N<<1];

ll ff(ll u)
{
	return u==fa[u]?u:fa[u]=ff(fa[u]);
}
inline bool cmp1(Node u,Node v)
{
	return u.x<v.x;
}
inline bool cmp2(Node u,Node v)
{
	return u.y<v.y;
}

int main()
{
	ll i,j,p;
	cin>>n;
//fafafa
	for(i=1; i<=n; i++)
	{
		scanf("%lld%lld",&node[i].x,&node[i].y);
		node[i].id=i;
		fa[i]=i;
	}
	sort(node+1,node+n+1,cmp1);
	for(i=1; i<n; i++) bn[++bb].a=node[i].id,bn[bb].b=node[i+1].id,bn[bb].c=node[i+1].x-node[i].x;
	sort(node+1,node+n+1,cmp2);
	for(i=1; i<n; i++) bn[++bb].a=node[i].id,bn[bb].b=node[i+1].id,bn[bb].c=node[i+1].y-node[i].y;
	sort(bn+1,bn+bb+1);
	for(i=1; i<=bb; i++)
	{
		if(ff(bn[i].a)==ff(bn[i].b)) continue;
		fa[ff(bn[i].a)]=ff(bn[i].b);
		ans+=bn[i].c;
	}
	cout<<ans;
}