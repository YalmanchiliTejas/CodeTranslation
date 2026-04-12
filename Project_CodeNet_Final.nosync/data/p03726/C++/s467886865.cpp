/*deco loves Chino*/
#include<bits/stdc++.h>
using namespace std;
int head[100010],dis[100010],pos,n,flag=1;
int cnt;
struct edge
{
	int next,to;
}e[200010];
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int u,int fa)
{
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)
		{
			continue;
		}
		dfs(v,u);
	}
	if(!dis[u])
	{
		if(dis[fa])
		{
			cout<<"First";
			exit(0);
		}
		dis[u]=dis[fa]=1;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dis[0]=1;
	dfs(1,0);
	if(flag)
	{
		cout<<"Second";
	}
}