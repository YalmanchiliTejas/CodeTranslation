#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const long long inf = 1e18;
const int mod = 1e9 + 7, rev2 = 5e8 + 4;
typedef pair<long long, int> li;

int n, m, s, t;
vector< pair<int,int> > G[N];
vector<int> dag[N], rev[N];
long long ds[N], dt[N];
int cs[N], ct[N], ks[N], kt[N];
bool vis[N];
int cnt[N];
int ans;

void dijkstra(int target, long long d[], int cnt[]) {
	for (int i = 1; i <= n; ++i) d[i] = inf;
	priority_queue < li, vector<li>, greater<li> > pq;
	pq.push(li(0, target)); d[target] = 0; cnt[target] = 1;

	while(!pq.empty()) {
		int u = pq.top().second; long long du = pq.top().first; pq.pop();
		if (du != d[u]) continue;

		for (auto e : G[u]) {
			int v = e.second, w = e.first;
			if (d[v] > du + w) {
				d[v] = du + w; pq.push(li(d[v], v));
				cnt[v] = cnt[u];
			} else if (d[v] == du + w) {
				cnt[v] = (cnt[v] + cnt[u]) % mod;
			}
		}
	}
}

void dfs(int u) {
	vis[u] = 1;
	if (ds[u] + dt[u] != ds[t]) return;
	if (ds[u] == dt[u]) ans = (ans + 1LL * ks[u] * kt[u]) % mod;

	for (int v : dag[u]) {
		if (ds[v] + dt[v] != ds[t]) continue;
		if (!vis[v]) dfs(v);
		if (ds[v] > dt[v] && dt[u] > ds[u]) {
			ans = (ans + 1LL * ks[u] * kt[v]) % mod;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> s >> t;
	while(m--) {
		int u, v, w; cin >> u >> v >> w;
		G[u].push_back(make_pair(w, v));
		G[v].push_back(make_pair(w, u));
	}
	dijkstra(s, ds, cs);
	dijkstra(t, dt, ct);
	for (int i = 1; i <= n; ++i) {
		ks[i] = 1LL * cs[i] * cs[i] % mod;
		kt[i] = 1LL * ct[i] * ct[i] % mod;
		cs[i] = 1LL * cs[i] * (cs[i] - 1) % mod;
		ct[i] = 1LL * ct[i] * (ct[i] - 1) % mod;
	}

	for (int u = 1; u <= n; ++u) {
		for (auto e : G[u]) if (ds[u] == ds[e.second] - e.first) 
			dag[u].push_back(e.second), rev[e.second].push_back(u);
	}

	dfs(s);

	ans = (ks[t] - ans) % mod;
	if (ans < 0) ans += mod;

	cout << ans << endl;
}