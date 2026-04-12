#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:512000000")
#include<utility>
#include<iostream>
#include<fstream>
#include<vector>
#include<array>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<functional>
#include<random>
#include<climits>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<cassert>
#include<ccomplex>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#define int128 __int128
#else
#define int128 long long
#endif

#define all(x) x.begin(), x.end()
#define mp make_pair
#define X first
#define Y second

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 gen(time(nullptr));

ll const mod = 1e9 + 7;

namespace {
	ll mul(ll a, ll b) {
		ll val = a * b - (ll)((ld)a * b / mod) * mod;
		if (val < 0) val += mod;
		if (val >= mod) val -= mod;
		return val;
	}

	ll poww(ll a, ll b) {
		ll val = 1;
		a %= mod;
		while (b > 0) {
			if (b % 2) val = mul(a, val);
			a = mul(a, a);
			b >>= 1;
		}
		return val % mod;
	}

	ll inv(ll a) {
		return poww(a, mod - 2);
	}
}

int const maxn = 3e5 + 5;

struct segtree {
	// 4Head
	struct node {
		node(ll x) : val_mx(x) {};
		node() : val_mx(LLONG_MIN) {}; // neutral
		ll val_mx = LLONG_MIN; // neutral
		ll lazy = 0; // -1
		void apply(int tl, int tr, ll add) {
			val_mx += add; // = add
			lazy += add; // = add
		}
	};
	void push(int u, int tl, int tr) {
		if (t[u].lazy != 0 /*-1*/) {
			int tm = (tl + tr) / 2;
			t[u * 2].apply(tl, tm, t[u].lazy);
			t[u * 2 + 1].apply(tm + 1, tr, t[u].lazy);
			t[u].lazy = 0; //-1
		}
	}
	node merge(const node& a, const node& b) const {
		return node(max(a.val_mx, b.val_mx));
	}
	// 4Head
	node get(int u, int tl, int tr, int l, int r) {
		if (r < l || tl > r || tr < l) {
			return neutral;
		}
		if (l <= tl && tr <= r) {
			return t[u];
		} else {
			push(u, tl, tr);
			int tm = (tl + tr) / 2;
			return merge(get(u * 2, tl, tm, l, r), get(u * 2 + 1, tm + 1, tr, l, r));
		}
	}
	template<typename... M>
	void upd(int u, int tl, int tr, int l, int r, const M&... m) {
		if (r < l || tl > r || tr < l) {
			return;
		}
		if (l <= tl && tr <= r) {
			t[u].apply(tl, tr, m...);
		} else {
			push(u, tl, tr);
			int tm = (tl + tr) / 2;
			upd(u * 2, tl, tm, l, r, m...);
			upd(u * 2 + 1, tm + 1, tr, l, r, m...);
			t[u] = merge(t[u * 2], t[u * 2 + 1]);
		}
	}
	template<class T>
	void build(int u, int tl, int tr, vector<T>& v) {
		if (tl == tr) {
			node tmp(v[tl]);
			t[u] = tmp;
		} else {
			int tm = (tl + tr) / 2;
			build(u * 2, tl, tm, v);
			build(u * 2 + 1, tm + 1, tr, v);
			t[u] = merge(t[u * 2], t[u * 2 + 1]);
		}
	}
	void casual_build(int u, int tl, int tr) {
		if (tl == tr) {
			return;
		} else {
			int tm = (tl + tr) / 2;
			casual_build(u * 2, tl, tm);
			casual_build(u * 2 + 1, tm + 1, tr);
			t[u] = merge(t[u * 2], t[u * 2 + 1]);
		}
	}
	segtree(ll n) : n(n) {
		t.resize(4 * n);
		casual_build(1, 0, n - 1);
	}
	template<class T>
	segtree(vector<T>& v) : n(v.size()) {
		t.resize(4 * n);
		build(1, 0, n - 1, v);
	}
	node get(int l, int r) {
		return get(1, 0, n - 1, l, r);
	}
	template<typename... M>
	void upd(int l, int r, const M&... m) {
		upd(1, 0, n - 1, l, r, m...);
	}
	int n;
	vector<node>t;
	node neutral;
};

vector<pair<ll, ll>> b[maxn], e[maxn];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m; cin >> n >> m;
	for (ll i = 0; i < m; i++) {
		ll l, r, x; cin >> l >> r >> x;
		e[r].push_back({ l, x });
		b[l].push_back({ r, x });
	}

	vector<ll>tmp(maxn + 1);
	segtree st(tmp);


	ll best = 0;
	for (ll i = 1; i <= n; i++) {
		for (auto p : b[i]) {
			ll l = p.X, x = p.Y;
			st.upd(0, i - 1, x);
		}
		ll kek  = st.get(0, i - 1).val_mx;
		st.upd(i, i, kek);
		best = max(best, kek);
		for (auto p : e[i]) {
			ll l = p.X, x = p.Y;
			st.upd(0, l - 1, -x);
		}
	}
	cout << best << '\n';

	return 0;
}

/*
8 6

4 5 1 2 3 5 3 3

*/