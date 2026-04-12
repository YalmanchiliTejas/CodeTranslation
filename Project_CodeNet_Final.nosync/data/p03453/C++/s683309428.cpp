#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <functional>
using namespace std;

typedef long long ll;

int n, m, s, t;
vector<pair<ll, int>> edg[100003];
ll d[100003], dps[100003], dpt[100003];
ll mod = 1e9 + 7;

int main() {
	cin >> n >> m >> s >> t;
	--s; --t;
	for (int i = 0; i < m; ++i) {
		int u, v; ll dis; cin >> u >> v >> dis;
		--u; --v;
		edg[u].push_back({ dis, v });
		edg[v].push_back({ dis, u });
	}
	for (int i = 0; i < n; ++i) d[i] = 1e18;
	d[s] = 0;
	priority_queue<pair<ll, int>> que;
	for (int i = 0; i < (int)edg[s].size(); ++i) que.push({ -edg[s][i].first, edg[s][i].second });
	while (!que.empty()) {
		ll dis = -que.top().first; int pos = que.top().second; que.pop();
		if (dis >= d[pos]) continue;
		d[pos] = dis;
		for (int i = 0; i < (int)edg[pos].size(); ++i) {
			que.push({ -dis - edg[pos][i].first, edg[pos][i].second });
		}
	}

	priority_queue<pair<ll, int>> que2;
	dps[s] = 1;
	for (int i = 0; i < n; ++i) que2.push({ -d[i], i });
	while (!que2.empty()) {
		int pos = que2.top().second; que2.pop();
		for (int i = 0; i < (int)edg[pos].size(); ++i) {
			ll w = edg[pos][i].first; int to = edg[pos][i].second;
			if (d[pos] + w != d[to]) continue;
			dps[to] += dps[pos];
			dps[to] %= mod;
		}
	}
	dpt[t] = 1;
	for (int i = 0; i < n; ++i) que2.push({ d[i], i });
	while (!que2.empty()) {
		int pos = que2.top().second; que2.pop();
		for (int i = 0; i < (int)edg[pos].size(); ++i) {
			ll w = edg[pos][i].first; int to = edg[pos][i].second;
			if (d[pos] - w != d[to]) continue;
			dpt[to] += dpt[pos];
			dpt[to] %= mod;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (2*d[i] == d[t]) {
			ans += (dps[i] * dpt[i] % mod)*(dps[i] * dpt[i] % mod) % mod;
			ans %= mod;
		}
		for (int j = 0; j < (int)edg[i].size(); ++j) {
			ll w = edg[i][j].first; int to = edg[i][j].second;
			if (d[i] + w != d[to]) continue;
			if (2*d[i] < d[t] && d[t] < 2*d[to]) {
				ans += (dps[i] * dpt[to] % mod)*(dps[i] * dpt[to] % mod) % mod;
				ans %= mod;
			}
		}
	}
	ans = (dps[t] * dps[t] % mod - ans + mod) % mod;
	cout << ans << endl;
	return 0;
}