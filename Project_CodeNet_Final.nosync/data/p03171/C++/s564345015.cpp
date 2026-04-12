#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;

const long long MAX_N = 3e3 + 9, MAX_K = 1e5 + 5;
long long n;
long long a[MAX_N];
long long dp[MAX_N][MAX_N][2];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (long long i = 0; i < n; i++)
		cin >> a[i];

	for (long long i = 0; i < n; i++) {
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
	}

	for (long long i = 1; i < n; i++)
		for (long long j = 0; j + i < n; j++) {
			dp[j][j + i][0] = max(a[j] + dp[j + 1][j + i][1], a[j + i] + dp[j][j + i - 1][1]);	
			dp[j][j + i][1] = min(-a[j] + dp[j + 1][j + i][0], -a[j + i] + dp[j][j + i - 1][0]);
		}

	cout << dp[0][n - 1][0] << "\n";
	return 0;
}