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

unordered_map<ll, ll> d[maxn];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("output.txt", "w", stdout);

	ll n; cin >> n;
	vector<ll>a(n+ 1);
	ll sm = 0;
	for (ll i = 1; i <= n; i++) cin >> a[i], sm += a[i];

	ll k = (n + 1) / 2;

	d[0][0] = 0;
	
	for (ll i = 0; i <= n; i++) {
		ll ost = n - i;
		ll ost1 = max(0LL, i - 1);
		ll left = max({ k - ost, ost1 / 2, 0LL });
		ll right = (k - ost / 2);

		assert(right - left < 7);

		for (ll cnt = left; cnt <= right; cnt++) {
			if (d[i].find(cnt) == d[i].end()) continue;
			if (ost / 2 + cnt > k) continue;
			if (ost + cnt < k) continue;
			for (ll j = i + 1; j <= min(i + 2, n); j++) {
				if (d[j].find(cnt + 1) == d[j].end()) {
					d[j][cnt + 1] = d[i][cnt] + a[j];
				} else {
					d[j][cnt + 1] = min(d[j][cnt + 1], d[i][cnt] + a[j]);
				}
			}
		}
	}

	cout << sm - min(d[n][k], d[n - 1][k]);
	
	return 0;
}

/*

*/
