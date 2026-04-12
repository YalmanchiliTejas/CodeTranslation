#include <bits/stdc++.h>

using namespace std;

int n;
int a[200010];
long long dp[3][200010];
long long ans = -1e18;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; i++) cin >> a[i];


	for(int i = 0; i <= n; i++) dp[0][i] = dp[1][i] = dp[2][i] = -1e18;

	dp[0][0] = 0;
	dp[0][1] = a[1];
	dp[0][2] = a[2];

	for(int i = 3; i <= n; i++){
		dp[0][i] = dp[0][i - 2] + a[i];
		dp[1][i] = max(dp[0][i - 3], dp[1][i - 2]) + a[i];
		dp[2][i] = max(dp[1][i - 3], dp[2][i - 2]) + a[i];

		if(i >= 4) dp[2][i] = max(dp[2][i], dp[0][i - 4] + a[i]);
	}

	if(n % 2 == 0){
		ans = max(max(dp[0][n - 1], dp[0][n]), dp[1][n]);
	} else {
		ans = max(dp[2][n], max(max(dp[1][n], dp[1][n - 1]), max(dp[0][n - 1], dp[0][n - 2])));
	}

	cout << ans << endl;
	
	return 0;
}