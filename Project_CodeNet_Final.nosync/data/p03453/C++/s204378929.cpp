#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005, mod = 1e9+7;

struct node {
	int to, next, dis;
} edge[MAXN*4], e[MAXN*20];
int head[MAXN], h[MAXN*5], top = 0, tot = 0;
int rd[MAXN*5], cd[MAXN*5];
inline void push(int i, int j, int d)
{ edge[++top] = (node) {j, head[i], d}, head[i] = top; }
inline void push2(int i, int j)
{
	e[++tot] = (node) {j, h[i], 0}, h[i] = tot;
	e[++tot] = (node) {i, h[j], 1}, h[j] = tot;
	rd[j]++, cd[i]++;
}

int n, m, s, t;
long long dis[2][MAXN];

priority_queue<pair<long long,int>, vector<pair<long long, int> >, greater<pair<long long,int> > > que;

int vis[MAXN];

void dijkstra(int S, long long dis[])
{
	memset(vis, 0, sizeof vis);
	dis[S] = 0, que.push(make_pair(0, S));
	while (!que.empty()) {
		int nd = que.top().second; que.pop();
		if (vis[nd]) continue;
		vis[nd] = 1;
		for (int i = head[nd]; i; i = edge[i].next) {
			int to = edge[i].to;
			if (dis[to] > dis[nd] + edge[i].dis) {
				dis[to] = dis[nd]+edge[i].dis;
				que.push(make_pair(dis[to], to));
			}
		}
	}
}

int tot_pt;
int mark[MAXN*5];

int stk[MAXN*5], stk_top = 0;
int f[MAXN*5], g[MAXN*5];

void solve()
{
	for (int i = 1; i <= n; i++) {
		if (dis[0][i] == dis[1][i] && dis[0][i]+dis[1][i] == dis[0][t]) mark[i] = 1;
		for (int j = head[i]; j; j = edge[j].next) {
			int to = edge[j].to;
			if (dis[0][to] != dis[0][i]+edge[j].dis) continue;
			if (dis[0][to]+dis[1][to] != dis[0][t] || dis[0][i]+dis[1][i] != dis[0][t] || dis[0][i]+dis[1][to]+edge[j].dis != dis[0][t]) continue;
			long long cur = dis[1][to]+edge[j].dis-dis[0][i];
			if (cur > 0 && cur < 2*edge[j].dis) {
				int nd = ++tot_pt;
				push2(i, nd), push2(nd, to), mark[nd] = 1;
			} else push2(i, to);
		}
	}
	for (int i = 1; i <= tot_pt; i++)
		if (rd[i] == 0) stk[++stk_top] = i;
	f[s] = 1;
	while (stk_top) {
		int nd = stk[stk_top--];
		for (int i = h[nd]; i; i = e[i].next) {
			if (e[i].dis == 0) {
				int to = e[i].to;
				(f[to] += f[nd]) %= mod;
				if ((--rd[to]) == 0) stk[++stk_top] = to;
			}
		}
	}
	for (int i = 1; i <= tot_pt; i++)
		if (cd[i] == 0) stk[++stk_top] = i;
	g[t] = 1;
	while (stk_top) {
		int nd = stk[stk_top--];
		for (int i = h[nd]; i; i = e[i].next) {
			if (e[i].dis == 1) {
				int to = e[i].to;
				(g[to] += g[nd]) %= mod;
				if ((--cd[to]) == 0) stk[++stk_top] = to;
			}
		}
	}
	int ans = (long long)f[t]*g[s]%mod;
	for (int i = 1; i <= tot_pt; i++)
		if (mark[i])
			(ans += mod-(long long)f[i]*g[i]%mod*f[i]%mod*g[i]%mod) %= mod;
	cout << ans << endl;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t), tot_pt = n;
	for (int i = 1; i <= m; i++) {
		int u, v, d; scanf("%d%d%d", &u, &v, &d);
		push(u, v, d), push(v, u, d);
	}
	memset(dis, 127/3, sizeof dis);
	dijkstra(s, dis[0]);
	dijkstra(t, dis[1]);
	solve();
	return 0;
}
