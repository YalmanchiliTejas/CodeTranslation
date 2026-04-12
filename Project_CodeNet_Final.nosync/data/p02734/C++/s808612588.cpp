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
#endif

//4Head

#define all(x) x.begin(), x.end()
#define mp make_pair
#define X first
#define Y second

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 gen(time(nullptr));

ll const mod = 998244353;

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

ll dp[3005][3005];
ll dp1[3005][3005];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	ll s; cin >> s;
	vector<ll>a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0][0] = 0;
	dp1[0][0] = 0;
	for (ll i = 1; i <= n; i++) {
		ll x = a[i - 1];
		dp[i][x] = i;
		for (ll sum = 0; sum <= s; sum++) {
			(dp[i][sum] += (sum >= x ? dp1[i - 1][sum - x] : 0)) %= mod;
			dp1[i][sum] = (dp1[i - 1][sum] + dp[i][sum]) % mod;
		}
	}


	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		(ans += dp[i][s] * (n - i + 1)) %= mod;
	}
	cout << ans << endl;
	return 0;
}

/*
5
2 6 15 5 10

4
2 6 15 5

*/