#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001

int size[MAXN],cnt;
vector<int> edge[MAXN];

void addedge(int u,int v)
{
	edge[u].push_back(v);
}

void dfs1(int now,int father)
{
	size[now]=1;
	for(int i=0;i<edge[now].size();++i)
	{
		if(edge[now][i]==father)continue;
		dfs1(edge[now][i],now);
		if(size[edge[now][i]]==2)size[edge[now][i]]=-1;
		else size[now]+=size[edge[now][i]];
	}
}

void dfs2(int now,int father)
{
	++cnt;
	int num=0;
	for(int i=0;i<edge[now].size();++i)
	{
		if(edge[now][i]==father)continue;
		if(size[edge[now][i]]==1){++num;}
		if(size[edge[now][i]]!=-1)dfs2(edge[now][i],now);
	}
	if(num>=2){puts("First");exit(0);}
}

int main()
{
	int n;
	scanf("%d",&n);	
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs1(1,0);
	dfs2(1,0);
	if(cnt==1)puts("First");else puts("Second");
}