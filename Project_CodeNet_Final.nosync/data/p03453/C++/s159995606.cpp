#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18 + 239;

int add(int a, int b) {
	return (a + b) % MOD;
} 

int sub(int a, int b) {
	return (a - b + MOD) % MOD;
}

int mul(int a, int b) {
	return (a * b) % MOD;
}

int n;
vector<vector<pair<int, int>>> g;

void dij(int st, vector<int> &d, vector<int> &cnt) {
	d.resize(n, INF);
	cnt.resize(n, 0);
	d[st] = 0;
	cnt[st] = 1;
	set<pair<int, int>> s;
	s.insert({d[st], st});
	while (!s.empty()) {
		int v = s.begin()->second;
		s.erase(s.begin());
		for (auto t : g[v]) {
			if (d[t.first] + t.second == d[v]) {
				cnt[v] = add(cnt[v], cnt[t.first]);
			}
		}
		for (auto t : g[v]) {
			if (d[t.first] > d[v] + t.second) {
				s.erase({d[t.first], t.first});
				d[t.first] = d[v] + t.second;
				s.insert({d[t.first], t.first});
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, s, t;
	cin >> n >> m >> s >> t;
	g.resize(n);
	s--;
	t--;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		c *= 2;
		u--;
		v--;
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
	vector<int> ds, cnts, dt, cntt;
	dij(s, ds, cnts);
	dij(t, dt, cntt);
	int ans = mul(cnts[t], cnts[t]);
	for (int i = 0; i < n; i++) {
		if (ds[i] + dt[i] == ds[t] && ds[i] == dt[i]) {
			int v = mul(cnts[i], cntt[i]);
			v = mul(v, v);
			ans = sub(ans, v);
		}
	}
	for (int i = 0; i < n; i++) {
		for (auto x : g[i]) {
			if (ds[x.first] + x.second + dt[i] == ds[t]) {
				if (ds[x.first] < ds[t] / 2 && ds[t] / 2 < ds[x.first] + x.second) {
					int v = mul(cnts[x.first], cntt[i]);
					v = mul(v, v);
					ans = sub(ans, v);
				}
			}
		}
	}
	cout << ans << endl;
}
