//さすが解説は天才的ですねー
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
//#include<bits/stdc++.h>
#include<cstdio>
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

const int mod = 998244353;
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
int ifac[IMAX + 1];

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N;
	scanf("%d", &N);

	ll facN = 1;
	rep1(i, N) facN = facN * i % mod;
	ifac[N] = modpow(facN, mod - 2);
	for (int i = N; i > 0; i--) ifac[i - 1] = (ll)ifac[i] * i % mod;

	ll kotae = modpow(3, N);

	ll hiku = 0;
	int k = 1;
	rep(i, N / 2) {
		hiku += (ll)ifac[i] * ifac[N - i] % mod * k % mod;
		k = k * 2 % mod;
	}
	hiku = hiku % mod * facN * 2 % mod;
	printf("%lld", (kotae - hiku + mod) % mod);

	Would you please return 0;
}