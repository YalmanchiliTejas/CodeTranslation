#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1000000007;
const ll mod998 = 998244353;
const ll intmax = 2147483647;
const ll llmax = 9223372036854775807;
const char sp = ' ';

ll res, f[10000001], t;
int N;

ll pw(ll x, int y) {
	ll a = 1;
	while (y) {
		if (y & 1) {
			a = a*x%mod998;
		}
		x = x*x%mod998;
		y /= 2;
	}
	return a;
}

ll modinv(ll x) {
	return pw(x, mod998 - 2);
}

ll comb(int n, int r) {
	return f[n] * modinv(f[r] * f[n - r] % mod998) % mod998;
}

int main() {
	cin >> N;
	f[0] = 1;
	for (int i = 1; i <= 10000000; i++) {
		f[i] = f[i - 1] * i%mod998;
	}
	res = pw(3, N);
	for (int i = N / 2 + 1; i <= N; i++) {
		t += comb(N, i)*pw(2, N - i) % mod998;
		t %= mod998;
	}
	t *= 2;
	t %= mod998;
	res += mod998 - t;
	res %= mod998;
	cout << res << endl;
}