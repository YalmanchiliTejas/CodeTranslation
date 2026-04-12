#include <bits/stdc++.h>
using namespace std;

const int N = 4e3;
pair<long long, long long> dp[N][N];
int a[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> a[i];

	for (int l = 1; l <= n; l++)
		for (int i = 0, j = l; j <= n; i++, j++) {
			dp[i][j] = { dp[i + 1][j].second + a[i] , dp[i + 1][j].first };
			dp[i][j] = max(dp[i][j], { dp[i][j - 1].second + a[j - 1], dp[i][j - 1].first });
		}

	cout << dp[0][n].first - dp[0][n].second << endl;
	cin >> n;
	return  0;
}