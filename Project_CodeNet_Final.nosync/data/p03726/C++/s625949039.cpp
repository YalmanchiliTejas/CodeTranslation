#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010
int Adj[MAXN],V[MAXN*2],nxt[MAXN*2],c,n;
void AddEdge(int u,int v)
{
	c++;V[c]=v,nxt[c]=Adj[u];Adj[u]=c;
}
bool dfs(int u,int p)
{
	int flag=0;
	for(int i=Adj[u];i;i=nxt[i])
		if(V[i]!=p)
		{
			bool k=dfs(V[i],u);
			if(k==1)
			{
				flag++;
				if(flag>1)
				{
					printf("First\n");
					exit(0);
				}
			}
		}
	if(flag==0) return 1;
	else if(flag==1) return 0;
}
int du[MAXN];
bool check()
{
	for(int i=1;i<=n;i++)
		if(du[i]>2) return 0;
	return 1;
}
int main()
{
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		du[u]++,du[v]++;
		AddEdge(u,v);
		AddEdge(v,u);
	}
	if(check())
	{
		if(n&1) printf("First\n");
		else printf("Second\n");
		return 0;
	}
	bool ans=dfs(1,0);
	if(ans) printf("First\n");
	else printf("Second\n");
}