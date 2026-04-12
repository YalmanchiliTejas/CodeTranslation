#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e3 + 10;

int n, a[MAXN];
long long dp[MAXN][MAXN];

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		dp[i][i] = a[i];
	}

	for (int di = 1; di < n; ++di)
		for (int i = 0; i < (n - di); ++i)
			dp[i][i + di] = max((a[i] - dp[i + 1][i + di]),
				 						(a[i + di] - dp[i][i + di -1]));

	--n;
	cout << dp[0][n] << '\n';
	
	return 0;
}
