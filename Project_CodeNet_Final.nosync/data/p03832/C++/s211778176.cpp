#include <vector>
#include <iostream>
using namespace std;
const int mod = 1000000007;
int N, A, B, C, D, fact[2009], inv[2009], factinv[2009], ncr[2009][2009], dp[2009][2009];
int main() {
	fact[0] = 1;
	for (int i = 1; i <= 2005; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
	inv[1] = 1;
	for (int i = 2; i <= 2005; i++) inv[i] = 1LL * inv[mod % i] * (mod - mod / i) % mod;
	factinv[0] = 1;
	for (int i = 1; i <= 2005; i++) factinv[i] = 1LL * factinv[i - 1] * inv[i] % mod;
	ncr[0][0] = 1;
	for (int i = 1; i <= 2005; i++) {
		for (int j = 0; j <= i; j++) {
			ncr[i][j] = ncr[i - 1][j];
			if (j) {
				ncr[i][j] += ncr[i - 1][j - 1];
				if (ncr[i][j] >= mod) ncr[i][j] -= mod;
			}
		}
	}
	cin >> N >> A >> B >> C >> D;
	dp[0][0] = 1;
	for (int i = 0; i <= B - A; i++) {
		for (int j = 0; j <= N; j++) {
			dp[i + 1][j] = dp[i][j];
			int prod = 1;
			for (int k = 1; k < C && j - (i + A) * k >= 0; k++) {
				prod = 1LL * prod * ncr[N - j + (i + A) * k][i + A] % mod;
			}
			for (int k = C; k <= D && j - (i + A) * k >= 0; k++) {
				int p = j - (i + A) * k;
				int res = dp[i][p];
				prod = 1LL * prod * ncr[N - j + (i + A) * k][i + A] % mod;
				res = 1LL * res * prod % mod;
				res = 1LL * res * factinv[k] % mod;
				dp[i + 1][j] += res;
				if (dp[i + 1][j] >= mod) dp[i + 1][j] -= mod;
			}
		}
	}
	cout << dp[B - A + 1][N] << endl;
	return 0;
}