#include <cstring>
#include <utility>
#include <cstdio>
#include <queue>
#define MOD 1000000007
typedef long long ll; 
ll ds[100005], dt[100005]; 
int dps[100005], dpt[100005]; 
int lst[100005], to[400005], pre[400005], w[400005], tot; 
std::priority_queue<std::pair<ll, int> > que; 
inline void add_edge(int u, int v, int _w)
{
	to[tot] = v; 
	pre[tot] = lst[u];
	w[tot] = _w; 
	lst[u] = tot++; 
}
void work(int n, int s, ll *dis, int *dp)
{
	memset(dis, 0x3f, n << 3); 
	dis[s] = 0; 
	dp[s] = 1; 
	que.push({0, s}); 
	while (!que.empty())
	{
		ll d = -que.top().first;
		int u = que.top().second; 
		que.pop(); 
		if (dis[u] != d)
			continue; 
		for (int i = lst[u]; ~i; i = pre[i])
		{
			int v = to[i]; 
			if (dis[v] > dis[u] + w[i])
			{
				dis[v] = dis[u] + w[i]; 
				dp[v] = 0; 
				que.push({-dis[v], v}); 
			}
			if (dis[v] == dis[u] + w[i])
				(dp[v] += dp[u]) %= MOD; 
		}
	}
}
int main()
{
	// freopen("ARC090-E.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n, m, s, t; 
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++)
	{
		int u, v, _w; 
		scanf("%d%d%d", &u, &v, &_w);
		add_edge(--u, --v, _w); 
		add_edge(v, u, _w);
	}
	work(n, --s, ds, dps); 
	work(n, --t, dt, dpt); 
	ll ans = (ll)dps[t] * dps[t] % MOD; 
	// printf("%lld\n", ans);
	for (int i = 0; i < n; i++)
	{
		if (ds[i] + dt[i] == ds[t] && ds[i] == dt[i])
			(ans -= (ll)dps[i] * dps[i] % MOD * dpt[i] % MOD * dpt[i]) %= MOD; 
		for (int k = lst[i]; ~k; k = pre[k])
		{
			int j = to[k];
			if (ds[i] + dt[j] + w[k] == ds[t] && ds[i] * 2 < ds[t] && dt[j] * 2 < ds[t])
				(ans -= (ll)dps[i] * dps[i] % MOD * dpt[j] % MOD * dpt[j]) %= MOD; 
		}
	}
	printf("%lld\n", (ans + MOD) % MOD);
	return 0; 
}
