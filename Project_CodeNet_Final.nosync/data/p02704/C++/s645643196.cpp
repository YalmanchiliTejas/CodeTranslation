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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
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

ll mod = 1e9 + 7;

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

ll const maxn = 3e5 + 5;

ull a[505][505][64];

ull ans[505][505];
bool ok = true;

void gg() {
	ok = false;
	cout << -1;
	exit(0);
}

bool is_row[505][2][64];
bool is_col[505][2][64];
bool used[505][505][64];


void relax(ll i, ll j, ll k, ll bit) {
	if (!used[i][j][k]) {
		is_row[i][bit][k] = 1;
		is_col[j][bit][k] = 1;
		a[i][j][k] = bit;
		used[i][j][k] = 1;
	} else if (a[i][j][k] != bit) {
		gg();
	}
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	ll n; cin >> n;
	vector<ull> s(n), t(n), u(n), v(n);
	for (ll i = 0; i < n; i++) cin >> s[i];
	for (ll i = 0; i < n; i++) cin >> t[i];
	for (ll i = 0; i < n; i++) cin >> u[i];
	for (ll i = 0; i < n; i++) cin >> v[i];

	//for (ll i = 0; i < n; i++) {
	//	for (ll j = 0; j < n; j++) {
	//		for (ll k = 0; k < 64; k++) {
	//			a[i][j][k] = -1;
	//		}
	//	}
	//}


	auto check = [&](ll k) {
		for (ll i = 0; i < n; i++) {
			ll and_sum = 1, or_sum = 0;
			for (ll j = 0; j < n; j++) {
				and_sum &= a[i][j][k];
				or_sum |= a[i][j][k];
			}
			ll bit = (u[i] & (1ULL << k));
			bit = (bit != 0);
			if (s[i] == 0) {
				if (and_sum != bit) gg();
			} else {
				if (or_sum != bit) gg();
			}
		}

		for (ll i = 0; i < n; i++) {
			ll and_sum = 1, or_sum = 0;
			for (ll j = 0; j < n; j++) {
				and_sum &= a[j][i][k];
				or_sum |= a[j][i][k];
			}
			ll bit = (v[i] & (1ULL << k));
			bit = (bit != 0);

			if (t[i] == 0) {
				if (and_sum != bit) gg();
			} else {
				if (or_sum != bit) gg();
			}
		}


	};

	for (ll k = 0; k < 64; k++) {
		// rows

		vector<ll>rows;

		for (ll i = 0; i < n; i++) {
			bool f = false;
			if (s[i] == 0) {
				if ((u[i] & (1ULL << k))) {
					f = true;
					for (ll j = 0; j < n; j++) {
						relax(i, j, k, 1);
					}
				}
			} else {
				if (!(u[i] & (1ULL << k))) {
					f = true;
					for (ll j = 0; j < n; j++) {
						relax(i, j, k, 0);
					}
				}
			}
			if (!f) {
				rows.push_back(i);
			}
		}

		vector<ll>cols;

		for (ll i = 0; i < n; i++) {
			bool f = false;
			if (t[i] == 0) {
				if ((v[i] & (1ULL << k))) {
					f = true;
					for (ll j = 0; j < n; j++) {
						relax(j, i, k, 1);
					}
				}
			} else {
				if (!(v[i] & (1ULL << k))) {
					f = true;
					for (ll j = 0; j < n; j++) {
						relax(j, i, k, 0);
					}
				}
			}
			if (!f) {
				cols.push_back(i);
			}
		}

		if (rows.empty() or cols.empty()) {
			check(k);
			continue;
		}
		if (rows.size() > 1 and cols.size() > 1) {
			for (ll i = 0; i < rows.size(); i++) {
				for (ll j = 0; j < cols.size(); j++) {
					relax(rows[i], cols[j], k, (i + j) % 2);
				}
			}
			check(k);
			continue;
		}

		if (rows.size() == 1) {
			ll i = rows[0];
			if (is_row[i][s[i]][k]) {
				for (ll j : cols) {
					relax(i, j, k, t[j]);
				}
			} else {
				for (ll j : cols) {
					if (is_col[j][t[j]][k]) {
						relax(i, j, k, s[i]);
					} else {
						relax(i, j, k, t[j]);
					}
				}
			}
		} else {
			ll j = cols[0];
			if (is_col[j][t[j]][k]) {
				for (ll i : rows) {
					relax(i, j, k, s[i]);
				}
			} else {
				for (ll i : rows) {
					if (is_row[i][s[i]][k]) {
						relax(i, j, k, t[j]);
					} else {
						relax(i, j, k, s[i]);
					}
				}
			}
		}
	}

	for (ll k = 0; k < 64; k++) {
		check(k);
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				ans[i][j] |= (a[i][j][k] << k);
			}
		}
	}

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}


	return 0;
}

/*

*/