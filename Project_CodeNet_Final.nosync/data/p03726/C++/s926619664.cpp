#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int pip[200050];

struct edge
{
	int nxt,v;
}e[400050];

int head[200050],ecnt;

void adde(int u,int v)
{
	e[++ ecnt].v = v;
	e[ecnt].nxt = head[u];
	head[u] = ecnt;
}

void dfs(int pos,int lst)
{
	for(int i = head[pos];i;i = e[i].nxt)
	{
		int v = e[i].v;
		if(v != lst)
			dfs(v,pos);
	}
	if(!pip[pos])
	{
		if(pip[lst])
		{
			printf("First\n");
			exit(0);
		}
		pip[lst] = 1;
		pip[pos] = 1;
	}
}

int main()
{
	int n; scanf("%d",&n);
	for(int i = 1;i < n; ++ i)
	{
		int u,v; scanf("%d%d",&u,&v);
		adde(u,v),adde(v,u);
	}
	pip[0] = 1;
	dfs(1,0);
	printf("Second\n");
}