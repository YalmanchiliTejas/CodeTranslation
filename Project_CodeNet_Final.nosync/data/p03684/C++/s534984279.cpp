#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod =1000000007;
const int maxn=100010;
struct point
{
	int index,x,y; 	
}p[maxn];
struct edge
{
	int u,v;
	int len;
}e[maxn*2];
int fa[maxn],tot,n;
void init()
{
	scanf("%d",&n);
	for(int i=0;i<maxn;i++)
		fa[i]=i;
	tot=0;
}
int get_fa(int x)
{
	if(x==fa[x])	return x;
	else return fa[x]=get_fa(fa[x]);
}
void addedge(point u,point v)
{
	e[tot].u=u.index;
	e[tot].v=v.index;
	e[tot++].len=min(abs(u.x-v.x),abs(u.y-v.y));
}
bool cmp1(point a,point b)
{
	return a.x<b.x;
}
bool cmp2(point a,point b)
{
	return a.y<b.y;
}
bool cmp(edge a,edge b)
{
	return a.len<b.len;	
}
ll fun()
{
	ll ans=0;
	int m=tot,t=0;
	sort(e,e+m,cmp);
	for(int i=0;i<m;i++)
	{
		int x=get_fa(e[i].u);
		int y=get_fa(e[i].v);
		if(x!=y)
		{
			ans+=e[i].len;
			fa[x]=y;
			t++;
			if(t==n-1)
				return ans;
		}
	}
	return ans;
}
int main()
{
	init();
	for(int i=0;i<n;i++)
		scanf("%d%d",&p[i].x,&p[i].y),p[i].index=i;
	sort(p,p+n,cmp1);
	for(int i=0;i<n-1;i++)
		addedge(p[i],p[i+1]);
	sort(p,p+n,cmp2);
	for(int i=0;i<n-1;i++)
		addedge(p[i],p[i+1]);
	ll ans=fun();
	printf("%lld\n",ans);
	return 0;
}