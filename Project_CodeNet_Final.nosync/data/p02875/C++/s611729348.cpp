#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modInv(ll a, ll b = MOD - 2) {
	if (b & 1) return a * modInv(a, b ^ 1) % MOD;
	if (b == 0) return 1;
	return modInv(a*a % MOD, b >> 1);
}

const int N = 1e7;
ll fact[N+1];

ll choose(ll a, ll b) {
	if (a < b) return 0;
	ll dv = fact[b] * fact[a - b] % MOD;
	return fact[a] * modInv(dv) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = i * fact[i-1] % MOD;

	ll res = modInv(3, n);
	for (int k = n/2 + 1; k <= n; ++k) {
		ll add = choose(n, k) * modInv(2, n - k) % MOD;
		res -= 2*add;
	}
	res %= MOD;
	if (res < 0) res += MOD;
	cout << res << '\n';
}
