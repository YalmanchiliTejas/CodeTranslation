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
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int MOD=1e9+7;

int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}

int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}

vector<ii> adj[200011];
ll dist[200011];
ll dp[200011];
ll dp2[200011];
ll dist2[200011];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,s,t; cin>>n>>m>>s>>t; s--; t--;
	for(int i=0;i<m;i++)
	{
		int u,v; ll d; cin>>u>>v>>d;
		u--; v--; d*=2;
		adj[u].pb(mp(v,d)); adj[v].pb(mp(u,d)); 
	}
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	for(int i=0;i<n;i++) dist[i]=ll(1e18);
	pq.push(mp(0,s)); dist[s] = 0; dp[s] = 1;
	while(!pq.empty())
	{
		ll D = pq.top().fi; int u=pq.top().se; pq.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i].fi; ll w=adj[u][i].se;
			if(D+w<dist[v])
			{
				dp[v] = dp[u];
				dist[v] = D + w;
				pq.push(mp(dist[v],v));
			}
			else if(D+w==dist[v])
			{
				dp[v] = add(dp[v], dp[u]);
			}
		}
	}
	ll finaldist = dist[t];
	finaldist>>=1;
	swap(s,t);
	for(int i=0;i<n;i++) dist2[i]=ll(1e18);
	pq.push(mp(0,s)); dist2[s] = 0; dp2[s] = 1;
	while(!pq.empty())
	{
		ll D = pq.top().fi; int u=pq.top().se; pq.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i].fi; ll w=adj[u][i].se;
			if(D+w<dist2[v])
			{
				dp2[v] = dp2[u];
				dist2[v] = D + w;
				pq.push(mp(dist2[v],v));
			}
			else if(D+w==dist2[v])
			{
				dp2[v] = add(dp2[v], dp2[u]);
			}
		}
	}
	finaldist = dist2[t];
	finaldist>>=1;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(dist[i]==finaldist)
		{
			ans = add(ans, mult(mult(dp[i],dp2[i]),mult(dp[i],dp2[i])));
		}
	}
	for(int i=0;i<n;i++)
	{
		for(ii v:adj[i])
		{
			if(dist[i] + v.se == dist[v.fi] && dist[v.fi] + dist2[v.fi] == finaldist*2 && dist[v.fi] > finaldist && dist[i] < finaldist)
			{
				ans = add(ans, mult(mult(dp[i], dp2[v.fi]), mult(dp[i], dp2[v.fi])));
			}
		}
	}
	ans = add(mult(dp2[t], dp2[t]), MOD - ans);
	cout<<ans<<'\n';
}
