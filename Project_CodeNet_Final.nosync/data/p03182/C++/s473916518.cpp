#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MAXN = 210000;
const ll INF = 1e18;

vector<int> ad[MAXN];
vector<int> dl[MAXN];
int lb[MAXN];
int rb[MAXN];
ll a[MAXN];

ll rmq[MAXN * 4];
ll dd[MAXN * 4];
int n, m;

ll ans;


void add(int v, int tl, int tr, int l, int r, ll d) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		dd[v] += d, rmq[v] += d;
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, d);
	add(v * 2 + 2, m, tr, l, r, d);
	rmq[v] = max(rmq[v * 2 + 1], rmq[v * 2 + 2]) + dd[v];
}

ll get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return -INF;
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return max(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r)) + dd[v];
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> lb[i] >> rb[i] >> a[i];
		++rb[i];
		ad[lb[i]].push_back(i);
		dl[rb[i]].push_back(i);
	}
	++n;
	for (int i = 1; i < n; ++i) {
		for (int x: ad[i])
			add(0, 0, n, 0, lb[x], a[x]);
		for (int x: dl[i])
			add(0, 0, n, 0, lb[x], -a[x]);
		ll x = get(0, 0, n, 0, i);
		ans = max(ans, x);
		add(0, 0, n, i, i + 1, x);
	}
	cout << ans << "\n";
	return 0;
}


