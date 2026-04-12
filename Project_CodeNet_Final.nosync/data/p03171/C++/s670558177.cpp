#include<bits/stdc++.h>

using namespace std;
using ll = long long int;


int main() {
		int n;
		cin>>n;
		ll arr[n];
		for(int i = 0; i < n; i++) cin>>arr[i];
		ll dp[n][n];
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++) {
			dp[i][i] = arr[i];
		}
		for(int len = 2; len <= n; len++) {
			for(int i = 0; i < n && i + len-1 < n ; i++) {
				int j = i + len-1;
				dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
			}
		}
		cout<<dp[0][n-1]<<"\n";
}
