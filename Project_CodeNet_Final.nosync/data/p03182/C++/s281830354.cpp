#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
 
#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;
 
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
  
#define pb push_back
#define mp make_pair
#define in insert
#define f first
#define s second
#define ll long long
#define int long long
#define dd double
  
const int mod = 1e9 + 7;
const int N = 2e5 + 7;
const int inf = 2e9;
const ll INF = 1e18;

ll dp[N], t[4*N], c[4*N], p[N];
vector<ll> la[N];
vector<pair<ll, ll>> ra[N];

void push (int v, int tl, int tr) {
	t[v] += c[v];
	if (tl != tr){
		c[v + v] += c[v];
		c[v + v + 1] += c[v];
	}
	c[v] = 0;
}

void update (int v, int tl, int tr, int l, int r, int val) {
	push (v, tl, tr);
	if (tl >= l && tr <= r) {
		c[v] += val;
		push(v, tl, tr);
		return;
	}
	if (tl > r || tr < l) {
		return;
	}

	int mid = (tl + tr) / 2;
	update (v + v, tl, mid, l, r, val);
	update (v + v + 1, mid + 1, tr, l, r, val);
	t[v] = max(t[v + v], t[v + v + 1]);
}

ll get (int v, int tl, int tr, int l, int r) {
	push (v, tl, tr);
	if (tl >= l && tr <= r) {
		return t[v];
	}
	if (tl > r || tr < l) {
		return -INF;
	}
	int mid = (tl + tr) / 2;
	return max(get(v + v, tl, mid, l, r), get(v + v + 1, mid + 1, tr, l, r));
}

main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// freopen("*.in", "r", stdin);freopen("*.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		la[l].pb(x);
		ra[r].pb({l - 1, x});
	}

	ll ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < la[i].size(); j++)
			update (1, 0, n, 0, i - 1, la[i][j]);

		dp[i] = get(1, 0, n, 0, i - 1);
		ans = max(ans, dp[i]);
		update (1, 0, n, i, i, dp[i]);

		for (int j = 0; j < ra[i].size(); j++)
			update (1, 0, n, 0, ra[i][j].f, -ra[i][j].s);
	}

	cout << ans;
}