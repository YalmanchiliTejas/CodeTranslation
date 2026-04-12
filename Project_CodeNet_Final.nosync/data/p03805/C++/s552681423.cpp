#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m,k=0,tot=0,ans=0,head[10];
bool vis[10]={0};
struct edge{
	int u,v,next;
}e[200];
void add(int u,int v)
{
	e[++k].u=u;e[k].v=v;
	e[k].next=head[u];
	head[u]=k;
}
void dfs(int u)
{
	tot++;
	if(tot==n)
	{
		ans++;tot--;
		return;
	}
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(vis[v])continue;
		dfs(v);
	}
	tot--;vis[u]=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}