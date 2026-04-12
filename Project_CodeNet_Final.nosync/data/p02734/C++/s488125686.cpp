#include <iostream>
using namespace std;

long long N, S, A[1 << 19];
long long dp[3009];
long long mod = 998244353;

int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];

	dp[0] = 1; long long ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = S - A[i]; j >= 0; j--) {
			if (j == 0) dp[j + A[i]] += 1LL * i * dp[j];
			else dp[j + A[i]] += dp[j];
		}
		for (int j = 0; j <= S; j++) dp[j] %= mod;
		ans += 1LL * dp[S];
		ans %= mod;
	}

	cout << ans << endl;
	return 0;
}