#include <iostream>
#define MAXN 3005
using namespace std;

long long n, a[MAXN], dp[MAXN][MAXN][2];

int main() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
	}
	for (int i=1; i<n; i++) {
		for (int j=0; j<n-i; j++) {
			dp[j][j + i][0] = max(dp[j + 1][j + i][1] + a[j], dp[j][j + i - 1][1] + a[j + i]);
			dp[j][j + i][1] = min(dp[j + 1][j + i][0] - a[j], dp[j][j + i - 1][0] - a[j + i]);
		}
	}
	cout << dp[0][n - 1][0] << "\n";
}
