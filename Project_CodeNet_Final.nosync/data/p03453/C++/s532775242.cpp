#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vll;
typedef vector<pl> vpl;
constexpr ll MOD = 1e9+7;

vii G[100001];
pl dist[2][100001];

int main() {
	int N, M, S[2];
	cin >> N >> M >> S[0] >> S[1];
	while (M--) {
		int u, v, d;
		cin >> u >> v >> d;
		G[u].emplace_back(v, d);
		G[v].emplace_back(u, d);
	}
	
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= N; ++j) dist[i][j] = pl(1e18, 0);
		dist[i][S[i]] = pl(0, 1);
		priority_queue<pl, vpl, greater<pl>> pq;
		pq.emplace(0, S[i]);
		while (!pq.empty()) {
			ll d = pq.top().f;
			int u = pq.top().s;
			pq.pop();
			if (d > dist[i][u].f) continue;
			for (auto& v : G[u]) {
				if (d + v.s < dist[i][v.f].f) {
					dist[i][v.f] = pl(d + v.s, dist[i][u].s);
					pq.emplace(dist[i][v.f].f, v.f);
				}
				else if (d + v.s == dist[i][v.f].f) {
					dist[i][v.f].s = (dist[i][u].s + dist[i][v.f].s) % MOD;
				}
			}
		}
	}

	vii E;
	ll d = dist[0][S[1]].f;
	for (int u = 1; u <= N; ++u) {
		if (2 * dist[0][u].f == d) E.emplace_back(u, u);
		else if (2 * dist[0][u].f < d) {
			for (auto& v : G[u]) {
				if (2 * dist[1][v.f].f < d && dist[0][u].f + v.s + dist[1][v.f].f == d) E.emplace_back(u, v.f);
			}
		}
	}
	ll sum = 0, ans = 0;
	for (auto& x : E) {
		ll p = (dist[0][x.f].s % MOD) * (dist[1][x.s].s % MOD) % MOD;
		ans = (p * sum + ans) % MOD;
		sum = (p + sum) % MOD;
	}
	cout << 2 * ans % MOD << '\n';
}