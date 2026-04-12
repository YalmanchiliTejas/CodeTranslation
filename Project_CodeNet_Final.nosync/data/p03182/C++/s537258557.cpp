#pragma GCC optimize ("Ofast")
#include "bits/stdc++.h"
	
#define PI 3.141592653589793
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
// Use for file I/O;
#define FIN string _fname = ""; \
			string _is = _fname + ".in", _os = _fname + ".out"; \
			freopen(_is.c_str(), "r", stdin); \
			freopen(_os.c_str(), "w", stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e9 + 10;
const ll INF2 = 1e18 + 10;
const int MOD = 1e9 + 7;
const ld EPS = 1e-4;

const int LOGN = 19;
const int MAXN = 2e5;

ll t[MAXN * 4], lp[MAXN * 4];

void update(int v, int tl, int tr, int l, int r, ll x) {
	if (l >= r) return;
	else if (tl == l && tr == r) {
		lp[v] += x;
		t[v] += x;
	} else {
		int tm = (tl + tr) / 2;
		update(2*v + 1, tl, tm, l, min(r, tm), x);
		update(2*v + 2, tm, tr, max(l, tm), r, x);
		t[v] = min(t[2*v + 1], t[2*v + 2]) + lp[v];
	}
}

ll query(int v, int tl, int tr, int l, int r) {
	if (l >= r) return INF2;
	else if (tl == l && tr == r) return t[v];
	else {
		int tm = (tl + tr) / 2;
		ll r1 = query(2*v + 1, tl, tm, l, min(r, tm));
		ll r2 = query(2*v + 2, tm, tr, max(l, tm), r);
		return min(r1, r2) + lp[v];
	}
}


int main() {
	FAST;

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll>>> a(n + 2);

	for (int i = 0; i < m; i++) {
		int l, r;
		ll v;
		cin >> l >> r >> v;
		a[r].emplace_back(l, v);
	}


	vector<ll> dp(n + 2);

	ll ans = 0;
	for (int i = 1; i <= n + 1; i++) {
		dp[i] = query(0, 0, n + 2, 0, i);
		update(0, 0, n + 2, i, i + 1, dp[i]);
		for (auto p: a[i]) {
			update(0, 0, n + 2, 0, p.first, p.second);
			ans += p.second;
		}
	}

	cout << ans - dp[n + 1];
}

