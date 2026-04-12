#include<iostream>

using namespace std;

#define SIZE 200001

const long long P = 1000000007;

long long fac[SIZE + 1];
long long ifac[SIZE + 1];

long long mod_pow(long long a, long long p) {
	long long ans = 1;

	while (p != 0) {
		if (p & 1) {
			ans = ans * a % P;
		}
		a = a * a % P;
		p = p >> 1;
	}
	return ans;
}

void init_fac_table(void) {
	fac[0] = 1;
	ifac[0] = 1;
	for (int i = 0; i < SIZE; i++) {
		fac[i + 1] = fac[i] * (i + 1) % P;
		ifac[i + 1] = ifac[i] * mod_pow(i + 1, P - 2) % P;
	}
}

long long nCr(long long n, long long r) {
	if (n == 0 && r == 0) {
		return 1;
	}
	if (n < r || n < 0) {
		return 0;
	}
	long long t = ifac[n - r] * ifac[r] % P;
	return t * fac[n] % P;
}

int main(int argc, char *argv[])
{
	long long N, M, K;

	cin >> N >> M >> K;
	init_fac_table();
	long long ans = 0;
	for (long long i = 0; i < M; i++) {
		ans += nCr(M * N - 2, K - 2) * i * (M - i) * N * N % P;
	}

	for (long long i = 0; i < N; i++) {
		ans += nCr(M * N - 2, K - 2) * i * (N - i) * M * M % P;
	}
	cout << ans % P << "\n";
	return 0;
}
