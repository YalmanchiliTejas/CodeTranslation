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

int ifac[5000001];

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N;
	scanf("%d", &N);

	int N2 = N / 2;
	ll facN = 1;
	rep1(i, N) facN = facN * i % mod;
	ifac[0] = modpow(facN, mod - 2);
	rep(i, N2) ifac[i + 1] = (ll)ifac[i] * (N - i) % mod;

	ll kotae = modpow(3, N);
	const int inv2 = 499122177;

	ll hiku = 0;
	ll ima = ifac[N2];
	ll k = modpow(2, N2 - 1);
	rep(i, N2) {
		ima = ima * (N2 - i) % mod;
		hiku += ima * ifac[N2 - i - 1] % mod * k % mod;
		k = k * inv2 % mod;
	}
	hiku = hiku % mod * facN * 2 % mod;
	printf("%lld", (kotae - hiku + mod) % mod);

	Would you please return 0;
}