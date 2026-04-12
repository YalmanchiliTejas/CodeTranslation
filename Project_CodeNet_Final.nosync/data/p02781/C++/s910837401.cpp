#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:512000000")
#include<utility>
#include<iostream>
#include<fstream>
#include<vector>
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

//4Head

#define all(x) x.begin(), x.end()
#define mp make_pair
#define X first
#define Y second

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 gen(time(NULL));

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

ll const maxn = 3e5 + 5;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	ll k; cin >> k;
	ll n = s.size();
	string kek = "";

	ll scd = n, trd = n;
	for (ll i = 1; i < n; i++) {
		if (s[i] != '0') {
			scd = i;
			break;
		}
	}

	for (ll i = scd + 1; i < n; i++) {
		if (s[i] != '0') {
			trd = i;
			break;
		}
	}

	for (ll i = 0; i < n; i++) {
		kek += '0';
	}
	ll ans = 0;
	if (k == 3) {
		for (ll i = 0; i < n; i++) {
			for (ll j = i + 1; j < n; j++) {
				for (ll k = j + 1; k < n; k++) {
					if (i == 0) ans += (s[0] - '1') * 9 * 9;
					else ans += 9 * 9 * 9;
				}
			}
		}
		for (ll j = scd; j < n; j++) {
			for (ll k = j + 1; k < n; k++) {
				if (j == scd) ans += (s[scd] - '1') * 9;
				else ans += 9 * 9;
			}
		}
		for (ll k = trd; k < n; k++) {
			if (k == trd) ans += (s[trd] - '0');
			else ans += 9;
		}
	} else if (k == 2) {
		for (ll i = 0; i < n; i++) {
			for (ll j = i + 1; j < n; j++) {
				if (i == 0) ans += (s[0] - '1') * 9;
				else ans += 9 * 9;
				
			}
		}
		for (ll j = scd; j < n; j++) {
			if (j == scd) ans += (s[scd] - '0');
			else ans += 9;
		}
	} else {
		for (ll i = 0; i < n; i++) {
			if (i == 0) ans += s[0] - '0';
			else ans += 9;
		}
	}
	cout << ans << endl;
	return 0;
}

/*
3
0 1
3 0
1 0
*/