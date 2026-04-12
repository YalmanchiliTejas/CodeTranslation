#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int>g[55];
bool vis[55];
int dfs(int now,int cur,int mask)
{
	if(mask==(1<<n)-1)
	{
		return 1;
	}
	int ans=0;
	for(int i=0;i<g[cur].size();i++)
	{
		int x=g[cur][i];
		int bit=1<<x;
		if(!(mask&bit))
		{
			ans+=dfs(now+1,x,mask|bit);
		}
	}
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cout<<dfs(0,0,1)<<endl;
	return 0;
}