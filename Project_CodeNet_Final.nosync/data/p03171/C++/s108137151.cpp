#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e3 + 5;
ll dp[N][N][2];
int n;
int a[N];

void go(int l, int r, int turn){

	if(r - l < 1)
		return;
	ll &ans = dp[l][r][turn];
	if(ans != -1)
		return;

	ans = 0;

	if(r - l == 1){
		ans = max(a[r], a[l]);
		dp[l][r][turn^1] = min(a[l], a[r]);
		 // cout << l << "\t" << r << "\t" << turn << "\t" << ans << "\n";
		return;
	}

	go(l + 1, r, turn^1);
	go(l, r - 1, turn^1);

	if(a[l] + dp[l + 1][r][turn] > a[r] + dp[l][r - 1][turn]){
		ans = a[l] + dp[l + 1][r][turn];
		dp[l][r][turn^1] = dp[l + 1][r][turn^1];
	}
	else{
		ans = a[r] + dp[l][r - 1][turn];
		dp[l][r][turn^1] = dp[l][r - 1][turn^1];
	}
	// cout << l << "\t" << r << "\t" << turn << "\t" << ans << "\t" << dp[l][r][turn^1] << "\n";
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}

	if(n == 1)
		return cout << a[1] << "\n", 0;

	go(1, n, 0);
	cout << dp[1][n][0] - dp[1][n][1] << "\n";
}