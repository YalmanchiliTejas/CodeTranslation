#include <iostream>
using namespace std;
const int mod = 1000000007;
int N, A, B, C, D, dp[1009][1009], comb[1009][1009], inv[1009];
int main() {
	comb[0][0] = 1;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j <= i; j++) {
			comb[i][j] = comb[i - 1][j];
			if (j >= 1) {
				comb[i][j] += comb[i - 1][j - 1];
				if (comb[i][j] >= mod) comb[i][j] -= mod;
			}
		}
	}
	inv[1] = 1;
	for (int i = 2; i <= 1000; i++) inv[i] = 1LL * inv[mod % i] * (mod - mod / i) % mod;
	cin >> N >> A >> B >> C >> D; dp[0][0] = 1;
	for (int i = 0; i <= B - A; i++) {
		int num = i + A;
		for (int j = 0; j <= N; j++) {
			dp[i + 1][j] = dp[i][j];
			int mul = 1;
			for (int k = 1; k < C && j - num * k >= 0; k++) mul = 1LL * mul * comb[j - num * (k - 1)][num] % mod * inv[k] % mod;
			for (int k = C; k <= D && j - num * k >= 0; k++) {
				mul = 1LL * mul * comb[j - num * (k - 1)][num] % mod * inv[k] % mod;
				dp[i + 1][j] = (dp[i + 1][j] + 1LL * dp[i][j - num * k] * mul) % mod;
			}
		}
	}
	cout << dp[B - A + 1][N] << endl;
	return 0;
}