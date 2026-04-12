#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+20;
int n,m,vis[N],ans;
vector<int> e[N];
void dfs(int u,int cnt)
{
	if(cnt==n)
	{
		ans++;
		return;
	}
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(!vis[v])
		{
			vis[v]=1;
			dfs(v,cnt+1);
			vis[v]=0;
		}
	}
}
int main()
{
	
	while(cin>>n>>m)
	{
		ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		vis[1]=1;
		dfs(1,1);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
			e[i].clear();
	}
	return 0;	
}