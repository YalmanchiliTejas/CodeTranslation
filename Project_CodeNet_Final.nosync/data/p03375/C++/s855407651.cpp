#include <iostream>
using namespace std;
int N, M, fact[3009], inv[3009], factinv[3009], dp[3009][3009], pw[9000009], fermat[3009];
int main() {
	cin >> N >> M;
	fact[0] = 1;
	for (int i = 1; i <= N; i++) fact[i] = 1LL * fact[i - 1] * i % M;
	inv[1] = 1;
	for (int i = 2; i <= N; i++) inv[i] = 1LL * inv[M % i] * (M - M / i) % M;
	factinv[0] = 1;
	for (int i = 1; i <= N; i++) factinv[i] = 1LL * inv[i] * factinv[i - 1] % M;
	pw[0] = 1;
	for (int i = 1; i <= N * N; i++) pw[i] = 2 * pw[i - 1] % M;
	fermat[0] = 2;
	for (int i = 1; i <= N; i++) fermat[i] = 1LL * fermat[i - 1] * fermat[i - 1] % M;
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + 1LL * j * dp[i - 1][j]) % M;
		}
	}
	int ret = 0;
	for (int i = 0; i <= N; i++) {
		int val = 1LL * fact[N] * factinv[i] % M * factinv[N - i] % M * fermat[N - i] % M;
		if (i & 1) val = (val == 0 ? 0 : M - val);
		for (int j = 0; j <= i; j++) {
			ret = (ret + 1LL * val % M * dp[i][j] % M * pw[(N - i) * j]) % M;
			ret = (ret + 1LL * (j + 1) * val % M * dp[i][j + 1] % M * pw[(N - i) * j]) % M;
		}
	}
	cout << ret << "\n";
	return 0;
}