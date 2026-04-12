#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <bitset>
#include <cmath>
#include <utility>
#define Maxn 100005
#define Maxm 1000005
#define lowbit(x) x&(-x)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define PI acos(-1.0)
#define eps 1e-7
#define LL long long 
#define Inf (1LL<<62)
#define inf 0x3f3f3f3f
#define input freopen("input.txt","r",stdin)
#define output freopen("output.txt","w",stdout)
using namespace std;
struct P
{
	int x,y;
	int id;
}p[Maxn];
int head[Maxn],k;
bool cmp1(P a,P b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	else
		return a.y<b.y;
}
bool cmp2(P a,P b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	else
		return a.x<b.x;
}
struct Edge
{
	int s;
	int e;
	int w;
	int next;
}edge[Maxn<<2];
void add(int s,int e,int w)
{
	edge[k].s=s;
	edge[k].e=e;
	edge[k].w=w;
	edge[k].next=head[s];
	head[s]=k++;
}
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int father[Maxn];
void init(int n)
{
	for(int i=0;i<n;i++)
		father[i]=i;
}
int find(int x)
{
	return father[x]==x?x:father[x]=find(father[x]);
}
LL kruscal(int n)
{
	init(n);
	sort(edge,edge+k,cmp);
	int cnt=0;
	LL ans=0;
	for(int i=0;i<k;i++)
	{
		int u=edge[i].s;
		int v=edge[i].e;
		int w=edge[i].w;
		int x=find(u);
		int y=find(v);
		if(x!=y)
		{
			ans+=w;
			father[x]=y;
			cnt++;
		}
		if(cnt==n-1)
			break;
	}
	if(cnt<n-1)
		return -1;
	return ans;
}
int main()
{
	int n;
	//input;output;
	while(~scanf("%d",&n))
	{
		k=0;
		memset(head,-1,sizeof(head));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			p[i].id=i;
		}
		sort(p,p+n,cmp1);
		for(int i=0;i<n-1;i++)
		{
			add(p[i].id,p[i+1].id,p[i+1].x-p[i].x);
			add(p[i+1].id,p[i].id,p[i+1].x-p[i].x);
		}
		sort(p,p+n,cmp2);
		for(int i=0;i<n-1;i++)
		{
			add(p[i].id,p[i+1].id,p[i+1].y-p[i].y);
			add(p[i+1].id,p[i].id,p[i+1].y-p[i].y);
		}
		//cout<<k<<endl;
		printf("%lld\n",kruscal(n));
	}
	return 0;
}