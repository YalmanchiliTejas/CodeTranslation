#include <iostream>

using namespace std;

int N, S, A[3030];

long long int MOD = 998244353;

long long int dp[5000][7000];

int main(void) {

	cin >> N >> S;
	for (int i = 1; i <= N; i++) { cin >> A[i]; }

	for (int i = 0; i <= N; i++) { dp[i][0] = 1; }

	long long int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= S; j++) {
			dp[i][j + A[i]] += dp[i - 1][j];
			dp[i][j + A[i]] %= MOD;
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= MOD;
		}
		ans += dp[i][S];
		ans %= MOD;
	}

	/*for (int i = 1; i <= 3; i++) {
		for (int j = 0; j <= 4; j++) {
			cout << "dp[" << i << "][" << j << "]= " << dp[i][j] << endl;
		}
	}*/

	cout << ans << endl;

	return 0;
}