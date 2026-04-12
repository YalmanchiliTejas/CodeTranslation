#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define W 1
#define B 2

const int N=1e5+5;

int n, root;
int leaf[N];
int col[N];
vector<int> g[N];

int dfs(int u, int par)
{
	vector<pair<int, int> > childs;
	for(auto &it:g[u])
	{
		if(it==par)
			continue;
		childs.push_back({dfs(it, u), it});
	}
	for(auto &it:childs)
	{
		if(it.first==0)
		{
			col[u]=W;
			col[it.second]=B;
			break;
		}
	}
	for(auto &it:childs)
	{
		if(col[it.second]==0)
		{
			bool check=1;
			for(auto &it2:g[it.second])
				check&=(col[it2]!=2);
			if(check)
				col[it.second]=1;
		}
	}
	if(u==root)
	{
		bool check=1;
		for(auto &it:childs)
			check&=(it.first==W);
		if(check)
			col[u]=W;
	}
	return col[u];
}

int32_t main()
{
	IOS;
	cin>>n;
	if(n==2)
	{
		cout<<"Second";
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()>1)
		{
			root=i;
			dfs(i, i);
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(col[i]==W)
		{
			bool check=1;
			for(auto &it:g[i])
				check&=(col[it]==W);
			if(check)
			{
				cout<<"First";
				return 0;
			}
		}
	}
	cout<<"Second";
	return 0;
}
