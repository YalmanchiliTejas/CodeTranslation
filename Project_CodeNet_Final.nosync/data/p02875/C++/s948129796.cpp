#pragma comment(linker, "/STACK:256000000")
#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <random>
#include <map>
#include <bitset>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

#define X first
#define Y second

using namespace std;

mt19937 rng(time(NULL));

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
using vb = vector<bool>;

const ll MOD = 998244353;

ll sqr(ll a) {
	return a * a;
}

ll powmod(ll a, ll x, ll p = MOD) {
	if (x <= 0) return 1;
	if (x % 2 == 0) return sqr(powmod(a, x >> 1, p)) % p;
	else return (a * powmod(a, x - 1, p)) % p;
}

ll gcd(ll a, ll b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N;
	cin >> N;

	vector<ll> fact(1, 1);
	for (int i = 1; i <= N; i++) fact.pb((fact.back() * i) % MOD);

	vector<ll> ofact(N + 1);
	ofact[N] = powmod(fact[N], MOD - 2, MOD);
	for (int i = N - 1; i >= 0; i--) ofact[i] = (ofact[i + 1] * (i + 1)) % MOD;

	ll ans = 0;
	ll pw2 = 2;

	for (int i = 0; i < N / 2; i++) {
		ans += ((pw2 * fact[N]) % MOD) * ((ofact[i] * ofact[N - i]) % MOD);
		ans %= MOD;
		pw2 *= 2;
		if (pw2 >= MOD) pw2 -= MOD;
	}

	cout << (powmod(3, N) - ans + MOD) % MOD << endl;

	return 0;
}