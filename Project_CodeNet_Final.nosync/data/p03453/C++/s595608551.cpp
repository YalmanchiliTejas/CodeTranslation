#include <iostream>
#include <vector>
#include <set>
#define int long long
using namespace std;

const int N = 200 * 1000 + 8, mod = 1000 * 1000 * 1000 + 7;
const long long inf = 1ll * N * mod;
int n, m;

vector <pair <int, long long> > adj[N];
long long dis1[N], dis2[N];
int dp1[N], dp2[N];
set <pair <long long, int> > s;

void dij(int st, long long dis[], int cnt[]) {
	for (int i = 1; i <= n; i++) {
		dis[i] = inf;
	}
	dis[st] = 0;
	cnt[st] = 1;
	s.insert({0, st});
	while (s.size()) {
		int v = (*s.begin()).second;
		s.erase(s.begin());
	//	cout << "74 " << v << endl;
		for (auto p : adj[v]) {
			long long u = p.first, w = p.second;
		//	cout << "73 " << v << " " << u << endl;
			if (dis[v] + w < dis[u]) {
				
				s.erase({dis[u], u});
				dis[u] = dis[v] + w;
				cnt[u] = 0;
				s.insert({dis[u], u});
			}
			if (dis[v] + w == dis[u]) {
				cnt[u] += cnt[v];
				cnt[u] %= mod;
			}
		}
	}
}

int32_t main() {
	int st, ed;
	cin >> n >> m >> st >> ed;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		w *= 2;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dij(st, dis1, dp1);
	dij(ed, dis2, dp2);
//	for (int i = 1; i <= n; i++) {
//		cout << "72 " << dis1[i] << " " << dis2[i] << endl;
//	}
	long long ans = 1ll * dp1[ed] * dp1[ed];
	ans %= mod;
//	cout << "71 " << ans << endl;
	long long d = dis1[ed];
	for (int i = 1; i <= n; i++) {
		if (dis1[i] == d / 2) {
			long long x = 1ll * dp1[i] * dp2[i];
			x %= mod;
			x *= x;
			x %= mod;
			ans -= x - mod;
			ans %= mod;
		}
		for (auto p : adj[i]) {
			long long u = p.first, w = p.second;
			if (dis1[i] < d / 2 && d / 2 < dis1[u] && 0ll + dis1[i] + w + dis2[u] == d) {
				long long x = 1ll * dp1[i] * dp2[u];
				x %= mod;
				x *= x;
				x %= mod;
				ans -= x - mod;
				ans %= mod;
			}
		}
	}
	cout << ans;
	return 0;
}
