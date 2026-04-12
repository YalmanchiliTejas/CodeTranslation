#include <utility>
#include <cstring>
#include <cstdio>
#include <queue>
#define MOD 1000000007
typedef long long ll; 
int lst[100005], to[400005], pre[400005], w[400005], tot;
std::priority_queue<std::pair<ll, int> > que; 
inline void add_edge(int u, int v, int _w)
{
	to[tot] = v;
	pre[tot] = lst[u]; 
	w[tot] = _w; 
	lst[u] = tot++; 
}
void bfs(int n, int s, ll *dis, int *dp)
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
ll dis_s[100005], dis_t[100005]; 
int dp_s[100005], dp_t[100005]; 
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
	bfs(n, --s, dis_s, dp_s); 
	bfs(n, --t, dis_t, dp_t); 
	ll ans = (ll)dp_s[t] * dp_s[t] % MOD; 
	for (int u = 0; u < n; u++)
	{
		if (dis_s[u] + dis_t[u] == dis_s[t] && dis_s[u] == dis_t[u])
			(ans -= (ll)dp_s[u] * dp_s[u] % MOD * dp_t[u] % MOD * dp_t[u]) %= MOD; 
		for (int i = lst[u]; ~i; i = pre[i])
		{
			int v = to[i]; 
			if (dis_s[u] + dis_t[v] + w[i] == dis_s[t] && dis_s[u] << 1 < dis_s[t] && dis_t[v] << 1 < dis_s[t])
				(ans -= (ll)dp_s[u] * dp_s[u] % MOD * dp_t[v] % MOD * dp_t[v]) %= MOD; 
		}
	}
	printf("%lld\n", (ans + MOD) % MOD);
	return 0; 
}
