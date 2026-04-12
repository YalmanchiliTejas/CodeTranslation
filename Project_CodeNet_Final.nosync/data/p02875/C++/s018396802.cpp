#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

const ll mod = 998244353;
ll modpow(ll A, ll B) {
	ll kotae = 1;
	while (B > 0) {
		if (B & 1) kotae = kotae * A % mod;
		A = A * A % mod;
		B >>= 1;
	}
	return kotae;
}

const int IMAX = 10000001;
ll fac[IMAX + 1], ifac[IMAX + 1], inv[IMAX + 1];
inline ll comb(int A, int B) {
	return fac[A] * ifac[B] % mod * ifac[A - B] % mod;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;

	fac[0] = 1;
	rep1(i, IMAX) fac[i] = fac[i - 1] * i % mod;
	ifac[IMAX] = modpow(fac[IMAX], mod - 2);
	for (int i = IMAX; i > 0; i--) ifac[i - 1] = ifac[i] * i % mod;
	inv[0] = 1;
	rep1(i, IMAX) inv[i] = ifac[i] * fac[i - 1] % mod;


	ll kotae = 1;
	ll k = 1;
	rep1(i, N) {
		ll tmp = comb(N, i);
		k = k * 2 % mod;
		if (i > N / 2) {
			k = (k - comb(i - 1, i - 1 - N / 2) * 2 + mod * 2) % mod;
		}
		kotae += tmp * k % mod;
		kotae %= mod;
	}
	co(kotae% mod);

	Would you please return 0;
}