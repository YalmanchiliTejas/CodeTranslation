#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10, MOD = 1e9 + 7;

vector<vector<pair<ll, ll>>> gr;

ll n, m;
bool used[SIZE][2];
set<pair<ll, ll>> s;
ll dp[SIZE][2], dist[SIZE][2];

void djikstra(int st, int ind) {
	used[st][ind] = 1;
	
	for (int i = 0; i < n; i++) dist[i][ind] = INF;
	dist[st][ind] = 0;
	dp[st][ind] = 1;
	for (int i = 0; i < n; i++) {
		s.insert({ dist[i][ind], i });
	}

	while (!s.empty()) {
		pair<ll, ll> v = *(s.begin());
		s.erase(s.begin());

		for (auto to : gr[v.second]) {
			if (dist[to.first][ind] == to.second + dist[v.second][ind]) {
				dp[to.first][ind] += dp[v.second][ind];
				dp[to.first][ind] %= MOD;
			}
			else if (dist[to.first][ind] > to.second + dist[v.second][ind]) {
				dp[to.first][ind] = dp[v.second][ind];
				s.erase({ dist[to.first][ind], to.first });
				dist[to.first][ind] = to.second + dist[v.second][ind];
				s.insert({ dist[to.first][ind], to.first });
			}
		}
	}
}

vector<tuple<ll, ll, ll>> edges;

int main()
{
	fastInp;
	ll s, t;
	cin >> n >> m;
	cin >> s >> t;
	s--; t--;

	gr.resize(n);
	for (int i = 0; i < m; i++) {
		ll u, v, d;
		cin >> u >> v >> d;
		u--; v--;
		edges.push_back({ u, v, d });
		gr[u].push_back({ v, d });
		gr[v].push_back({ u, d });
	}

	djikstra(s, 0);
	djikstra(t, 1);

	ll ans = (dp[t][0] * dp[s][1]) % MOD;

	for (int i = 0; i < n; i++) {
		if (dist[i][0] == dist[i][1] && dist[i][1] + dist[i][0] == dist[t][0]) {
			ans -= ((dp[i][0] * dp[i][1]) % MOD * ((dp[i][1] * dp[i][0]) % MOD)) % MOD;
			if (ans < 0) ans += MOD;
		}
	}

	ll tD = dist[t][0];
	for (auto cur : edges) {
		ll u = get<0>(cur), v = get<1>(cur), d = get<2>(cur);
		if ((dist[u][0] + dist[v][1] + d == tD)) {
			if ((dist[u][0] * 2 < tD && dist[v][1] * 2 < tD)) {
				ans -= ((dp[u][0] * dp[v][1]) % MOD * ((dp[u][0] * dp[v][1]) % MOD)) % MOD;
				if (ans < 0) ans += MOD;
			}
		}
		else if ((dist[u][1] + dist[v][0] + d == tD)) {
			if ((dist[u][1] * 2 < tD && dist[v][0] * 2 < tD)) {
				ans -= ((dp[u][1] * dp[v][0]) % MOD * ((dp[u][1] * dp[v][0]) % MOD)) % MOD;
				if (ans < 0) ans += MOD;
			}
		}
	}

	cout << ans;

	return 0;
}