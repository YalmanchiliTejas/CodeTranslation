#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
using ll = long long;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
#define reps(i, S, E) for (ll i = (S); i <= (E); i++)
#define rep(i, N) reps(i, 0, N-1)
#define deps(i, E, S) for (ll i = (E); i >= (S); i--)
#define dep(i, N) deps(i, N-1, 0)
const ll MOD = 1000000007;
const ll INF = 1LL << 60;
const int INF_INT = 1 << 30;

//AtCoder Beginner Contest 127 - E
vector<vector<ll>> comb(ll n, ll r) {
	vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
	for (ll i = 0; i < (ll)v.size(); i++) {
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (ll j = 1; j < (ll)v.size(); j++) {
		for (ll k = 1; k < j; k++) {
			v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
		}
	}
	return v;
}

//�g�p(num1 / num2) % m : (num1 * modinv(num2, m)) % m
ll modinv(ll a, ll m) {
	ll b = m, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

ll combMOD(ll n, ll r, ll mod) {
	ll num = 1;
	for (ll i = 1; i <= r; i++) {
		num = num * (n - i + 1);
		num = num % mod;
		num = (num * modinv(i, mod)) % mod;
	}
	return num;
}

int main() {
	ll N;
	scanf("%lld", &N);
	ll M;
	scanf("%lld", &M);
	ll K;
	scanf("%lld", &K);

	ll sum = 0;
	rep(i, N) { 
		ll temp = 0;
		ll row = i;
		temp += (row * (row + 1) / 2);
		row = N - i - 1;
		temp += (row * (row + 1) / 2);

		rep(j, M) {
			sum += temp * M;
			sum %= MOD;
			ll col = j;
			sum += N * (col * (col + 1) / 2);
			sum %= MOD;
			col = M - j - 1;
			sum += N * (col * (col + 1) / 2);
			sum %= MOD;
		}
	}

	//�g�p(num1 / num2) % m : (num1 * modinv(num2, m)) % m
	//sum = (sum / 2) % MOD
	sum = (sum * modinv(2, MOD)) % MOD;

	//ll result = sum * combMOD(N * M, K, MOD) * combMOD(K, 2, MOD) / combMOD(N * M, 2, MOD);
	ll result = sum * combMOD(N * M, K, MOD);
	result %= MOD;
	result *= combMOD(K, 2, MOD);
	result %= MOD;
	result = (result * modinv(combMOD(N * M, 2, MOD), MOD)) % MOD;

	printf("%lld\n", result);
}
