#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll minv(ll a, ll m = MOD) {
	return a == 1 ? 1 : m - minv(m % a, a) * m / a;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll X, Y, K; cin >> X >> Y >> K;
	ll binom = 1;
	for (ll i = 0; i < K-2; i++) {
		binom = binom * minv(i+1) % MOD * (X * Y - 2 - i) % MOD;
	}
	ll sum = 0;
	for (ll x = 1; x < X; x++) {
		sum += x * (X-x) * Y % MOD * Y % MOD;
	}
	for (ll y = 1; y < Y; y++) {
		sum += y * (Y-y) * X % MOD * X % MOD;
	}
	ll ans = sum % MOD * binom % MOD;
	cout << ans << endl;

	return 0;
}