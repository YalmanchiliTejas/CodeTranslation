#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1e5+10;
struct edge{int to,Next;}ed[N<<1];
int edcnt,head[N];
void addedge(int u,int v){ed[++edcnt]=(edge){v,head[u]};head[u]=edcnt;}
int deg[N];
queue<int>q;
bool used[N];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		addedge(u,v);addedge(v,u);
		deg[u]++;deg[v]++;
	}
	for(int i=1;i<=n;i++)
	if(deg[i]==1) q.push(i);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(used[u]) continue;
		used[u]=true;
		bool flag=false;
		for(int i=head[u];i;i=ed[i].Next)
		if(!used[ed[i].to])
		{
			int v=ed[i].to;
			used[v]=true;
			for(int j=head[v];j;j=ed[j].Next)
			if(!used[ed[j].to])
			{
				deg[ed[j].to]--;
				if(deg[ed[j].to]==1) q.push(ed[j].to);
			}
			flag=true;
		}
		if(!flag)
		{
			printf("First\n");
			return 0;
		}
	}
	printf("Second\n");
	return 0;
}