/* be name Khoda */
#include <bits/stdc++.h>
using namespace std;

// VJUDGE

const int N = 3006;
int n, a[N];
long long dp[N][N], sum[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = n; 0 <= i; i--)
		for (int j = i; j < n; j++) {
			if (i == j)
				dp[i][j] = a[i];
			else {
				dp[i][j] = a[i] + (sum[j] - sum[i] - dp[i + 1][j]);
				dp[i][j] = max(dp[i][j], a[j] + (sum[j - 1] - sum[i - 1] - dp[i][j - 1]));
			}
//			cout << i << "  " << j << " == " << dp[i][j] << endl;
		}
//	cout << dp[0][n - 1] << endl;
	cout << 2 * dp[0][n - 1] - sum[n - 1] << endl;
}
