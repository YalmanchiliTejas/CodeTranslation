#include <iostream>
#include <algorithm>
using namespace std;

long long mod = 1000000007;
long long H, W, K, S1, S2;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 30; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

int main() {
	cin >> H >> W >> K;
	for (int i = 0; i <= H - 1; i++) {
		long long r = W * W; if (i == 0) r = W * (W - 1) / 2LL;
		r %= mod; r *= (H - i); r %= mod;
		S1 += 1LL * i * r; S1 %= mod;
	}
	for (int i = 0; i <= W - 1; i++) {
		long long r = H * H; if (i == 0) r = H * (H - 1) / 2LL;
		r %= mod; r *= (W - i); r %= mod;
		S2 += 1LL * i * r; S2 %= mod;
	}
	long long I = (H * W) * (H * W - 1) / 2LL; I %= mod;
	S1 = Div(S1, I, mod);
	S2 = Div(S2, I, mod);

	long long EXP1 = (S1 + S2) % mod;
	long long EXP2 = K * (K - 1) / 2; EXP2 %= mod;
	long long EXP = EXP1 * EXP2 % mod;

	long long VAL = 1;
	for (int i = H * W - K + 1; i <= H * W; i++) { VAL *= (long long)i; VAL %= mod; }
	for (int i = 1; i <= K; i++) { VAL = Div(VAL, i, mod); }

	cout << (EXP * VAL) % mod << endl;
	return 0;
}