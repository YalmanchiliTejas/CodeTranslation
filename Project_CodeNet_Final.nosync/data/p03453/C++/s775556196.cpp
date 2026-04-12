//besmellah
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair <int, int> pii;
const int maxn = 1e5 + 5, mod = 1e9 + 7, inf = 2e18;
int V[2 * maxn], U[2 * maxn], W[2 * maxn], ta[maxn], tb[maxn], dista[maxn], distb[maxn];
vector <int> adj[maxn];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	s--;
	t--;
	for (int i = 0; i < m; i++) {
		cin >> V[i] >> U[i] >> W[i];
		V[i]--;
		U[i]--;
		adj[V[i]].push_back(i);
		adj[U[i]].push_back(i);
	}
	fill(dista, dista + maxn, inf);
	set <pii> S;
	S.insert(pii(0, s));
	dista[s] = 0;
	ta[s] = 1;
	while (S.size()) {
		pii P = *S.begin();
		S.erase(S.begin());
		int v = P.second;
		for (auto e: adj[v]) {
			int u = v ^ V[e] ^ U[e];
			if (dista[v] + W[e] > dista[u]) continue;
			if (dista[v] + W[e] == dista[u]) {
				ta[u] = (ta[u] + ta[v]) % mod;
			}
			else {
				S.erase(pii(dista[u], u));
				ta[u] = ta[v];
				dista[u] = dista[v] + W[e];
				S.insert(pii(dista[u], u));
			}
		}
	}
	fill(distb, distb + maxn, inf);
	S.insert(pii(0, t));
	distb[t] = 0;
	tb[t] = 1;
	while (S.size()) {
		pii P = *S.begin();
		S.erase(S.begin());
		int v = P.second;
		for (auto e: adj[v]) {
			int u = v ^ V[e] ^ U[e];
			if (distb[v] + W[e] > distb[u]) continue;
			if (distb[v] + W[e] == distb[u]) {
				tb[u] = (tb[u] + tb[v]) % mod;
			}
			else {
				S.erase(pii(distb[u], u));
				tb[u] = tb[v];
				distb[u] = distb[v] + W[e];
				S.insert(pii(distb[u], u));
			}
		}
	}
//	cout << dista[t] << ' ' << distb[s] << ' ' << ta[t] << ' ' << tb[s] << endl;
	int ans = ta[t] * tb[s] % mod;
	for (int i = 0; i < n; i++) {
		if (dista[i] == distb[i] && 2 * dista[i] == dista[t]) {
			ans = (ans - ta[i] * ta[i] % mod * tb[i] % mod * tb[i] % mod + mod) % mod;
		}
	}
	for (int i = 0; i < m; i++) {
		if (dista[V[i]] > dista[U[i]]) swap(V[i], U[i]);
		if (dista[V[i]] + W[i] != dista[U[i]]) continue;
		if (distb[U[i]] + W[i] != distb[V[i]]) continue;
		if (dista[V[i]] + W[i] + distb[U[i]] != distb[s]) continue;
		if (2 * dista[V[i]] < dista[t] && 2 * distb[U[i]] < dista[t]) {
			ans = (ans - ta[V[i]] * ta[V[i]] % mod * tb[U[i]] % mod * tb[U[i]] % mod + mod) % mod;
		}
	}
	cout << ans;
}
