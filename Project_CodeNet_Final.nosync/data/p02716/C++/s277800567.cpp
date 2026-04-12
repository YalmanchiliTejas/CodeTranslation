#include<bits/stdc++.h>
#define int long long
#define mod 100000000000000000
#define for1(i, n) for(int i = 1; i <= (n);i++)
using namespace std;
int n, a[234567], dp[234567][5][5];//i,num,last
signed main() {
	cin >> n;
	dp[0][0][0] = 0;
	dp[0][0][1] = -mod;
	dp[0][1][0] = -mod;
	dp[0][1][1] = -mod;
	dp[0][2][0] = -mod;
	dp[0][2][1] = -mod;
	for1(i, n) {
		cin >> a[i];
		dp[i][0][0] = dp[i - 1][0][1];
		dp[i][0][1] = dp[i - 1][0][0] + a[i];
		dp[i][1][0] = max(dp[i - 1][0][0], dp[i - 1][1][1]);
		dp[i][1][1] = dp[i - 1][1][0] + a[i];
		dp[i][2][0] = max(dp[i - 1][1][0], dp[i - 1][2][1]);
		dp[i][2][1] = dp[i - 1][2][0] + a[i];
	}
	if (n % 2)cout << max({ dp[n - 2][0][1],dp[n - 1][1][1],dp[n][2][1] }) << endl;
	else cout << max({ dp[n - 1][0][1], dp[n][1][1] }) << endl;
}