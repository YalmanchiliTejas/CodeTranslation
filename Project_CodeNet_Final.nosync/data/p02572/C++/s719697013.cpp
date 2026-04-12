#include<iostream>
#include<algorithm>
#include<vector>
using LL =    long long;
using namespace std;

LL pow_l(LL x, LL n) {
	LL mod = 1e9 + 7;

	LL res = 1, x_n = x;
	while (n > 0) {
		if ((n & 1) == 1) {
			res *= x_n;
			res = res % mod;
		}
		n = n >> 1;
		x_n = x_n * x_n % mod;
		if (x_n == 0) {
			return 0;
		}
	}

	return res;
}
// mod. m での a の逆元 a^{-1} を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
int main() {
	LL N;
	cin >> N;
	vector<LL>A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	LL sum = 0, s_sum = 0;
	LL mod = 1e9 + 7;

	for (int i = 0; i < N; i++) {
		sum += A[i] % mod;
		sum = sum % mod;
		s_sum += A[i] * A[i] % mod;
		s_sum = s_sum % mod;
	}

	LL ans = (sum * sum % mod - s_sum);
	while (ans < 0) {
		ans += mod;
	}
	ans %= mod;
	LL temp1 = (mod + 1) / 2;
	LL temp2 = modinv(2, mod);
	ans = ans * (modinv(2, mod) % mod);
	//ans = ans + 9223372036854775807 % mod;
	
	ans = ans % mod;
	cout << ans << endl;
	return 0;
}