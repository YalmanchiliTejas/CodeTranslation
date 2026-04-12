#include<iostream>

using namespace std;
typedef long long ll;

ll MOD = 1000000007;

ll K, N, M;
ll fact[200001], factinv[200001];

ll modpow(ll a, ll b) {
	ll ret = 1, kakeru = a;
	while (b > 0) {
		if (b & 1)ret *= kakeru, ret %= MOD;
		kakeru *= kakeru, kakeru %= MOD;
		b >>= 1;
	}
	return ret;
}

void setfact() {
	fact[0] = 1, fact[1] = 1;
	for (int i = 2; i <= 200000; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}
	factinv[200000] = modpow(fact[200000], MOD - 2);
	for (int i = 200000 - 1; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * (i + 1);
		factinv[i] %= MOD;
	}
}

ll comb(ll a, ll b) {
	
	ll ret = fact[a];
	ret *= factinv[b], ret %= MOD;
	ret *= factinv[a - b], ret %= MOD;
	return ret;
}

int main() {

	setfact();

	cin >> N >> M >> K;
	
	ll ans = 0;

	for (int i = 1; i <= M - 1; i++) {
		ans += (i % MOD) * ((M - i) % MOD) * modpow(N, 2);
		ans %= MOD;
	}
	for (int i = 1; i <= N - 1; i++) {
		ans += (i % MOD) * ((N - i) % MOD) * modpow(M, 2);
		ans %= MOD;
	}
	cout << (ans * comb(N * M - 2, K - 2)) % MOD << endl;
	return 0;
}