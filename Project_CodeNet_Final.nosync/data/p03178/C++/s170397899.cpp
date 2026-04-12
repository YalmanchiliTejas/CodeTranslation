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

ll dp[maxn][101][2];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	ll d; cin >> d;
	ll n = s.size();
	dp[0][0][0] = 1;
	for (ll i = 0; i < n; i++) {
		ll digit = s[i] - '0';
		for (ll ost = 0; ost < d; ost++) {
			// 1
			for (ll c = 0; c < 10; c++) {
				(dp[i + 1][(ost + c) % d][1] += dp[i][ost][1]) %= mod;
			}
			// 0
			(dp[i + 1][(ost + digit) % d][0] += dp[i][ost][0]) %= mod;
			for (ll c = 0; c < digit; c++) {
				(dp[i + 1][(ost + c) % d][1] += dp[i][ost][0]) %= mod;
			}
		}
	}
	
	cout << ((dp[n][0][1] + dp[n][0][0] - 1) % mod + mod) % mod << endl;


	return 0;
}

/*
5
2 6 15 5 10

4
2 6 15 5

*/