#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll sum[200001], a[200001], dp[200001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		sum[i] = (i > 2 ? sum[i-2] : 0) + a[i];
	}

	for(int i=2;i<=n;i++) {
		if(i&1) dp[i] = max(dp[i-1], dp[i-2]+a[i]);
		else    dp[i] = max(sum[i-1], dp[i-2]+a[i]);
	}
	cout << dp[n];
}