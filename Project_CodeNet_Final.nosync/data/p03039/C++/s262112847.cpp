#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, M, K;
ll f[200001], s[200001], t;

ll pw(ll x, int y) {
	ll a = 1;
	while (y) {
		if (y & 1) {
			a = a*x%mod;
		}
		x = x*x%mod;
		y /= 2;
	}
	return a;
}

ll modinv(ll x) {
	return pw(x, mod - 2);
}

ll ncr(ll n, ll r) {
	return f[n]*modinv(f[r]*f[n-r]%mod)%mod;
}

int main() {
	cin >> N >> M >> K;
	f[0] = 1;
	for (int i = 1; i <= 200000; ++i) {
		f[i] = f[i - 1] * i%mod;
	}
	for (int i = 1; i <= 200000; ++i) {
		s[i] = s[i - 1] + M*i;
		s[i] %= mod;
	}
	for (int i = 0; i < N; ++i) {
		t += (s[N - 1 - i] + s[i])*M;
		t %= mod;
	}
	for (int i = 1; i <= 200000; ++i) {
		s[i] = s[i - 1] + N*i;
		s[i] %= mod;
	}
	for (int i = 0; i < M; ++i) {
		t += (s[M - 1 - i] + s[i])*N;
		t %= mod;
	}
	t *= modinv(2);
	t %= mod;
	cout << t*ncr(N*M - 2, K - 2) % mod << endl;
}
