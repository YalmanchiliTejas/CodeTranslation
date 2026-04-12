#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MOD(x) ((x)%mod)
int n;
map<pair<int,int>,bool>m;
struct point
{
	long long x,y;
	int id;
}p[100005];
int cnt;
struct edge
{
	int u,v;
	long long w;
}e[400005];
bool cmp1(point a,point b)
{
	return a.x<b.x;
}
bool cmp2(point a,point b)
{
	return a.y<b.y;
}
bool cmp3(edge a,edge b)
{
	return a.w<b.w;
}
int fa[100005];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
long long sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&p[i].x,&p[i].y);
		p[i].id=i;
	}
	sort(p+1,p+1+n,cmp1);
	for(int i=1;i<n;i++)
	{
		if(m[make_pair(p[i].id,p[i+1].id)]) continue;
		if(m[make_pair(p[i+1].id,p[i].id)]) continue;
		m[make_pair(p[i].id,p[i+1].id)]=1;
		cnt++;
		e[cnt].u=p[i].id;
		e[cnt].v=p[i+1].id;
		e[cnt].w=min(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y));
	}
	sort(p+1,p+1+n,cmp2);
	for(int i=1;i<n;i++)
	{
		if(m[make_pair(p[i].id,p[i+1].id)]) continue;
		if(m[make_pair(p[i+1].id,p[i].id)]) continue;
		m[make_pair(p[i].id,p[i+1].id)]=1;
		cnt++;
		e[cnt].u=p[i].id;
		e[cnt].v=p[i+1].id;
		e[cnt].w=min(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y));
	}
	sort(e+1,e+1+cnt,cmp3);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		if(find(e[i].u)==find(e[i].v)) continue;
		fa[find(e[i].u)]=find(e[i].v);
		sum+=e[i].w;
	}
	printf("%lld",sum);
	return 0;
}