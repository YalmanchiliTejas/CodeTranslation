#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,ma[maxn];
struct node { int v; node *nxt; } edge[maxn*2],*head[maxn],*ncnt;
void addedge(int u,int v)
{
	ncnt++;
	ncnt->v=v,ncnt->nxt=head[u];
	head[u]=ncnt;
}
void dfs(int u,int fa)
{
	for(node *p=head[u];p;p=p->nxt)
	{
		int v=p->v;
		if(v==fa) continue;
		dfs(v,u);
		if(!ma[v])
		{
			if(ma[u]) { printf("First\n"); exit(0); }
			ma[u]=v,ma[v]=u;
		}
	}
}
int main()
{
	ncnt=&edge[0];
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	dfs(1,0);
	printf("%s\n",ma[1]?"Second":"First");
}