#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

constexpr ll mod = 1000000007LL;

ll fact(ll k, int sgn = 0) {
	static vector<ll> fac(2, 1LL);
	static vector<ll> inv(2, 1LL);
	static vector<ll> finv(2, 1LL);
	static ll nx = 2LL;
	while (nx <= k) {
		fac.push_back(fac[nx - 1] * nx % mod);
		inv.push_back(mod - inv[mod % nx] * (mod / nx) % mod);
		finv.push_back(finv[nx - 1] * inv[nx] % mod);
		++nx;
	}
	if (sgn == 0)
		return fac[k];
	return finv[k];
}

ll comb(ll a, ll b) {
	if (b < 0 || b > a) return 0;
	return fact(a) * fact(b, 1) % mod * fact(a - b, 1) % mod;
}


int main(void){
    int N, M, K; cin >> N >> M >> K;
    ll tmp1 = 0;
    for (ll x = 0; x < N; ++x){
        tmp1 += (x * (x - N) % mod - ((x + N - 1) * (x - N)) / 2 % mod + mod) % mod;
        tmp1 %= mod;
    }
    ll tmp2 = 0;
    for (ll y = 0; y < M; ++y){
        tmp2 += (y * (y - M) % mod - ((y + M - 1) * (y - M)) / 2 % mod + mod) % mod;
        tmp2 %= mod;
    }
    ll res = (ll)M * M % mod * tmp1 % mod + (ll)N * N % mod * tmp2 % mod;
    res %= mod;
    res = res * comb(N * M - 2, K - 2) % mod;
    cout << res << endl;
    return 0;
}