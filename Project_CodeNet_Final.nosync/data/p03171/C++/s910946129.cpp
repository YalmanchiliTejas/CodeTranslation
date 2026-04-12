#include <bits/stdc++.h>
using namespace std;
						
#define fast_cin() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define int long long

const int N = 3005;

int dp[N][N][2];
int n, a[N];

int32_t main() {
	fast_cin();  

	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < n; i++) {
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i + len <= n; i++) {
			int j = i + len - 1;
			dp[i][j][0] = max(dp[i + 1][j][1] + a[i], dp[i][j - 1][1] + a[j]);
			dp[i][j][1] = min(dp[i + 1][j][0] - a[i], dp[i][j - 1][0] - a[j]);
		}
	}
	cout << dp[0][n - 1][0] << endl;
	
	return 0;
}