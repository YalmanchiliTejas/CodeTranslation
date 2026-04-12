#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define int long long
const int N = 1e5+7;
const int MOD = 1e9+7;

int n, m, s, t, curr;

VPII G[N];

VI DAG[N];

int dist[2][N];

struct comp
{
	bool operator()(int a, int b)
	{
		return mp(dist[curr][a], a)<mp(dist[curr][b], b);
	}
};

set<int, comp> S;

queue<int> Q;

int deg[N];

VI topo;

int dp[N];
int dpt[N];

void dijkstra(int s)
{
	for(int i = 1; i <= n; ++i)
	{
		dist[curr][i] = INF;
	}

	dist[curr][s] = 0;
	S.insert(s);

	while(!S.empty())
	{
		int v = *S.begin();
		S.erase(S.begin());

		for(auto it:G[v])
		{
			if(dist[curr][it.st]>dist[curr][v]+it.nd)
			{
				S.erase(it.st);
				dist[curr][it.st] = dist[curr][v]+it.nd;
				S.insert(it.st);
			}
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> s >> t;

	while(m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].eb(b, c);
		G[b].eb(a, c);
	}

	curr = 0;
	dijkstra(s);
	curr = 1;
	dijkstra(t);

	for(int i = 1; i <= n; ++i)
	{
		for(auto it:G[i])
		{
			if(dist[0][i]+it.nd+dist[1][it.st]==dist[0][t])
			{
				DAG[i].pb(it.st);
				++deg[it.st];
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!deg[i])
			Q.push(i);
	}

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		topo.pb(v);

		for(auto it:DAG[v])
		{
			if(--deg[it]==0)
				Q.push(it);
		}
	}

	dp[s] = 1;

	for(auto v:topo)
	{	
		for(auto it:DAG[v])
		{
			dp[it] += dp[v];
			dp[it] %= MOD;
		}
	}

	reverse(ALL(topo));

	dpt[t] = 1;

	for(auto v:topo)
	{	
		for(auto it:DAG[v])
		{
			dpt[v] += dpt[it];
			dpt[v] %= MOD;
		}
	}

	int ans = dp[t]*dp[t]%MOD;

	for(int i = 1; i <= n; ++i)
	{
		if(dist[0][i]+dist[1][i]==dist[0][t] && dist[0][i]==dist[1][i])
		{
			ans -= dp[i]*dp[i]%MOD*dpt[i]%MOD*dpt[i]%MOD;
			ans %= MOD;
		}
	}

	for(int v = 1; v <= n; ++v)
	{
		for(auto u:G[v])
		{
			if(dist[0][v]+u.nd+dist[1][u.st]==dist[0][t] && dist[0][v]+u.nd>dist[1][u.st] && dist[1][u.st]+u.nd>dist[0][v])
			{
				ans -= dp[v]*dp[v]%MOD*dpt[u.st]%MOD*dpt[u.st]%MOD;
				ans %= MOD;
			}
		}
	}

	ans %= MOD;
	ans += MOD;
	ans %= MOD;

	cout << ans << endl;
}