#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
using namespace std;

typedef long long ll;

ll dp[1003][1003];
int n;
ll A, B, C, D;
ll mod = 1e9 + 7;
ll fact[1003], inv[1003];

ll mpow(ll a, ll b) {
	if (b == 0) return 1;
	ll res = mpow(a, b / 2);
	res *= res;
	res %= mod;
	if (b%2LL == 1) {
		res *= a;
		res %= mod;
	}
	return res;
}

ll comb(ll a, ll b) {
	ll res = fact[a];
	res *= inv[b];
	res %= mod;
	res *= inv[a - b];
	return res%mod;
}

int main() {
	cin >> n >> A >> B >> C >> D;
	fact[0] = inv[0] = 1;
	for (ll i = 1; i < 1003; ++i) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		inv[i] = mpow(fact[i], mod - 2);
	}
	for (ll i = 0; i <= B; ++i) dp[i][0] = 1;
	for (ll i = A; i <= B; ++i) {
		for (ll j = 1; j <= n; ++j) {
			dp[i][j] = dp[i - 1][j];
			for (ll t = C; t <= D; ++t) {
				if (j - i*t < 0) break;
				ll w = dp[i - 1][j - i*t];
				w *= fact[n - j + i*t]*inv[n - j] % mod;
				w %= mod;
				w *= inv[t];
				w %= mod;
				w *= mpow(inv[i], t);
				w %= mod;
				dp[i][j] += w;
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[B][n] << endl;
	return 0;
}