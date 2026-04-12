#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m;
vector<int>v[10];
bool vis[10];
int ans;
void dfs(int x,int s)
{
	if(s==n)
	{
		ans++;
		return;
	}
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(vis[y])continue;
		vis[y]=true;
		dfs(y,s+1);
		vis[y]=false;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vis[1]=true;
	dfs(1,1);
	printf("%d",ans);
	return 0;
} 