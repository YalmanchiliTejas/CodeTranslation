//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<ll, ll> pll;

const ll MAXN = 2 * 100 * 1000 + 17, mod = 1e9 + 7, inf = 2e15 + 17;

ll n, m, s, t, ds[MAXN], dt[MAXN], cnts[MAXN], cntt[MAXN], ans;
pair<pll, ll> edge[MAXN];
vector<pll> adj[MAXN];

void dijs() {
	fill(ds + 1, ds + n + 1, inf);
	set<pll> st;
	st.insert({0, s});
	ds[s] = 0;
	cnts[s] = 1;
	while (!st.empty()) {
		int u = st.begin() -> ss;
		st.erase(st.begin());
		for (auto i : adj[u]) {
			if (ds[i.ff] > ds[u] + i.ss) {
				st.erase({ds[i.ff], i.ff});
				ds[i.ff] = ds[u] + i.ss;
				cnts[i.ff] = 0;
				st.insert({ds[i.ff], i.ff});
			}
			if (ds[i.ff] == ds[u] + i.ss)
				(cnts[i.ff] += cnts[u]) %= mod;
		}

	}
}

void dijt() {
	fill(dt + 1, dt + n + 1, inf);
	set<pll> st;
	st.insert({0, t});
	dt[t] = 0;
	cntt[t] = 1;
	while (!st.empty()) {
		int u = st.begin() -> ss;
		st.erase(st.begin());
		for (auto i : adj[u]) {
			if (dt[i.ff] > dt[u] + i.ss) {
				st.erase({dt[i.ff], i.ff});
				dt[i.ff] = dt[u] + i.ss;
				cntt[i.ff] = 0;
				st.insert({dt[i.ff], i.ff});
			}
			if (dt[i.ff] == dt[u] + i.ss)
				(cntt[i.ff] += cntt[u]) %= mod;
		}

	}
}


int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s >> t;
	for (int i = 1; i <= m; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		adj[v].pb({u, w});
		adj[u].pb({v, w});
		edge[i] = {{u, v}, w};

	}
	dijs();
	dijt();
	if (cnts[t] == 0)
		return cout << 0 << endl, 0;
	ans = (cnts[t] * cntt[s]) % mod;
	for (int i = 1; i <= m; i++) {
		int x = edge[i].ff.ff, y = edge[i].ff.ss;
		if (ds[x] + dt[y] + edge[i].ss == ds[t] && abs(ds[x] - dt[y]) < edge[i].ss)
			(ans -= (((cnts[x] * cntt[y]) % mod) * ((cnts[x] * cntt[y]) % mod)) % mod) %= mod;
		if (ds[y] + dt[x] + edge[i].ss == ds[t] && abs(ds[y] - dt[x]) < edge[i].ss)
			(ans -= (((cnts[y] * cntt[x]) % mod) * ((cnts[y] * cntt[x]) % mod)) % mod) %= mod;
	}
	for (int i = 1; i <= n; i++)
		if (ds[i] + dt[i] == ds[t] && ds[i] == dt[i])
			(ans -= (((cnts[i] * cntt[i]) % mod) * ((cnts[i] * cntt[i]) % mod)) % mod) %= mod;
	ans += mod;
	ans %= mod;
	cout << ans << endl;
	return 0;
}
