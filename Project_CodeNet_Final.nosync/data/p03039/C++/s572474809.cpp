#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:256000000")
#include<utility>
#include<iostream>
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

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define X first
#define Y second

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 gen(time(NULL));

int const mod = 1e9 + 7;
namespace {
	ll mul(ll a, ll b) {
		ll val = a * b - (ll)((ld)a * b / mod) * mod;
		if (val < 0) val += mod;
		if (val >= mod) val -= mod;
		return val;
	}
	ll poww(ll a, ll b){
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


int const maxn = 2e5 + 5;

ll fact[maxn];

ll C(ll n, ll k) {
	if (n < k) return 0;
	return mul(fact[n], inv(mul(fact[n - k], fact[k])));
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fact[0] = 1;
	for (ll i = 1; i < maxn; i++) fact[i] = (fact[i - 1] * i) % mod;
	ll n, m, k; cin >> n >> m >> k;
	ll sum_xs = 0;
	for (ll dl = 0; dl <= n; dl++) {
		ll cnt_pairs = max(0LL, n - dl);
		cnt_pairs = mul(cnt_pairs, mul(m, m));
		(sum_xs += mul(cnt_pairs, dl)) %= mod;
	}
	ll sum_ys = 0;
	for (ll dl = 0; dl <= m; dl++) {
		ll cnt_pairs = max(0LL, m - dl);
		cnt_pairs = mul(cnt_pairs, mul(n, n));
		(sum_ys += mul(cnt_pairs, dl)) %= mod;
	}
	ll ans = mul((sum_xs + sum_ys) % mod, C(n * m - 2, k - 2));
	cout << ans;
	return 0;
}
/*

*/