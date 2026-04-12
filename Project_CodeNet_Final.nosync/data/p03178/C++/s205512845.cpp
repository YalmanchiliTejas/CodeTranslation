#include <bits/stdc++.h>
using namespace std;

#define INF (INT64_MAX)
#define MOD (1000000000+7)
#define MAX 10000

string K;
int D;

long long dp[MAX + 1][2][100];

int main() {
	cin >> K >> D;

	int n = K.size();
	dp[0][0][0] = 1;
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < 2; j++ ) {
			for( int k = 0; k < D; k++ ) {
				int d = K[i] - '0';
				if( j ) {
					d = 9;
				}
				for( int l = 0; l <= d; l++ ) {
					dp[i + 1][j || l < d][(k + l) % D] += dp[i][j][k];
					dp[i + 1][j || l < d][(k + l) % D] %= MOD;
				}
			}
		}
	}
	long long ans = (dp[n][0][0] + dp[n][1][0] - 1 + MOD) % MOD;

	cout << ans << endl;

	return 0;
}
