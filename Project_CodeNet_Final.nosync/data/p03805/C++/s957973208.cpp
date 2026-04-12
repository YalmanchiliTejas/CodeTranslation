#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include<map>
#include<queue>
#include <algorithm>
using namespace std;
#define int long long

const int maxn = 1e5+5;
int n,m;
vector<int>e[10];
int vis[10];
int ans = 0;
bool check()
{
	for(int i=1;i<=n;i++)
		if(!vis[i]) return false;
	return true;
}
void dfs(int s)
{
	if(check())
	{
		ans++;
		return ;
	}
	for(int i=0;i<e[s].size();i++)
	{
		if(!vis[e[s][i]])
		{
			vis[e[s][i]]=1;
			dfs(e[s][i]);
			vis[e[s][i]]=0;
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0,u,v;i<m;i++)
	{
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}