#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100000
using namespace std;
struct node
{
	int to;
	node *nxt;
}edges[MAXN*2+5];
node *ncnt=&edges[0],*Adj[MAXN+5];
int d[MAXN+5],cnt[MAXN+5],n;
void AddEdge(int u,int v)
{
	node *p=++ncnt;
	p->to=v;
	p->nxt=Adj[u];
	Adj[u]=p;
	
	node *q=++ncnt;
	q->to=u;
	q->nxt=Adj[v];
	Adj[v]=q;
}
bool DFS(int u,int fa)
{
	cnt[u]=0;
	for(node *p=Adj[u];p!=NULL;p=p->nxt)
	{
		int v=p->to;
		if(v==fa)
			continue;
		if(DFS(v,u)==true)
			return true;
		if(cnt[v]==0)
			cnt[u]++;
	}
	if(cnt[u]>=2)
		return true;
	return false;
}
int main()
{
//	freopen("blackwhite.in","r",stdin);
//	freopen("blackwhite.out","w",stdout);
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		AddEdge(u,v);
		d[u]++,d[v]++;
	}
	if(n==1)
	{
		printf("First\n");
		return 0;
	}
	if(n==2)
	{
		printf("Second\n");
		return 0;
	}
	int rt;
	for(int i=1;i<=n;i++)
		if(d[i]>=2)
		{
			rt=i;
			break;
		}
	if(DFS(rt,-1)==true||cnt[rt]==0)
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}