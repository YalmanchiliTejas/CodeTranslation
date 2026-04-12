#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

vi adj[100001];
int deg[100001];
int h[100001];
priority_queue<ii> leaves;
int par[100001];

void dfs(int u, int p)
{
	int ch=0;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==p) continue;
		h[v]=h[u]+1;
		par[v]=u;
		dfs(v,u);
		ch++;
	}
	if(ch==0)
	{
		leaves.push(mp(h[u],u));
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; 
		cin>>u>>v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
		deg[u]++;deg[v]++;
	}
	par[0]=-1;
	dfs(0,-1);
	while(!leaves.empty())
	{
		int u = leaves.top().se;
		leaves.pop();
		if(par[u]==-1)
		{
			cout<<"First\n";
			return 0;
		}
		int p =par[u];
		if(par[p]==-1)
		{
			if(deg[p]>1)
			{
				cout<<"First\n";
				return 0;
			}
			else
			{
				cout<<"Second\n";
				return 0;
			}
		}
		else
		{
			if(deg[p]>2)
			{
				cout<<"First\n";
				return 0;
			}
			int pp = par[p];
			deg[pp]--;
			if(deg[pp]<=1)
			{
				leaves.push(mp(h[pp],pp));
			}
		}
	}
	
}
