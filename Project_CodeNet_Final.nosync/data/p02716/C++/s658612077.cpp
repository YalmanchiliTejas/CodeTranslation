#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cout << setprecision(10) << fixed;
	int n;
	cin >> n;
	vector<long long> a(n + 1), dp(n + 1, 0), pre(n + 1, 0);
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	pre[1] = a[1];
	for (int i = 2; i <= n; ++i){
		pre[i] = pre[i - 2] + a[i];
	}
	dp[1] = 0;
	for (int i = 2; i <= n; ++i){
		if (i & 1){
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		}
		else{
			dp[i] = max(dp[i - 2] + a[i], pre[i - 1] );
		}
	}
	cout << dp[n];
	return 0;
}

