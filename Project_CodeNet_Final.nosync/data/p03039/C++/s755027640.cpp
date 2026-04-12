#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;

ll mp(ll a,ll b) {
	ll ans = 1;
	while (b) {
		if (b % 2)
			ans *= a;
		a *= a;
		a %= MOD;
		ans %= MOD;
		b /= 2;
	}
	return ans;
}

ll modwari(ll a,ll b) {
	a %= MOD;
	return (a*mp(b, MOD - 2)) % MOD;
}

ll nCk(ll n, ll k) {
	ll ans = 1;
	for (int i = 0;i < k;i++) {
		ans *= n - i;
		ans = modwari(ans, i + 1);
		ans %= MOD;
	}
	return ans;
}

int main() {
	ll N, M, K;
	cin >> N >> M >> K;
	ll N2 = (N * N) % MOD;
	ll M2 = (M * M) % MOD;
	ll q = nCk(N*M - 2, K - 2);
	ll x = 0, y = 0;
	for (ll i = 1;i < M;i++) {
		x += ((i * (i + 1) / 2)%MOD*N2)%MOD;
		x %= MOD;
	}
	for (ll i = 1;i < N;i++) {
		y += ((i * (i + 1) / 2)%MOD*M2)%MOD;
		y %= MOD;
	}
	cout << ((x + y) % MOD * q) % MOD << endl;
}