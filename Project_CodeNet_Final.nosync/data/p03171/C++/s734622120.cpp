#include<bits/stdc++.h>
#define int int64_t
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n;
	int a[n+2] = {0};
	for(int i = 1; i <= n; i++) cin >> a[i];
	int dp[n+1][n+1];
	memset(dp , 0 , sizeof(dp));
	for(int i = 1; i <= n; i++) dp[i][i] = a[i];
	if(n % 2 == 0) for(int i = 0; i <= n; i++) dp[i][i] = -dp[i][i];
	for(int l = 2; l <= n; l++) {
		for(int i = 1; i <= n-l+1; i++) {
			if(n & 1) {
				if(l & 1) dp[i][i+l-1] = max(dp[i+1][i+l-1]+a[i] , dp[i][i+l-2]+a[i+l-1]);
				else dp[i][i+l-1] = min(dp[i+1][i+l-1]-a[i] , dp[i][i+l-2]-a[i+l-1]);
			}
			else {
				if(l & 1) dp[i][i+l-1] = min(dp[i+1][i+l-1]-a[i] , dp[i][i+l-2]-a[i+l-1]);
				else dp[i][i+l-1] = max(dp[i+1][i+l-1]+a[i] , dp[i][i+l-2]+a[i+l-1]);
			}
		}
	}
	cout << dp[1][n] << "\n";

    return 0;
}
