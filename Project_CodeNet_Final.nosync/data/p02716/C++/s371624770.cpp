// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

int n;
long long a[N], dp[N][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	
	for(int i = 0; i < n; i++) cin >> a[i];
	
	for(int i = n - 1; i >= 0; i--) {
		dp[i][0] = dp[i][1] = -1e18;

		int t = (n - i - 1) / 2;
		if(t == 0) dp[i][0] = a[i];	
		else {
			for(int j = i + 2; j < min(i+25, n); j++) {
				int k1 = (n - j - 1) / 2;
				int k2 = (n - j - 2) / 2;

				if(k1 == t - 1) dp[i][0] = max(dp[i][0], a[i] + dp[j][0]);
				if(k2 == t - 1) dp[i][0] = max(dp[i][0], a[i] + dp[j][1]);
			}
		}

		t = (n - i - 2) / 2;

		if(t == 0) dp[i][1] = a[i];
		else {
			for(int j = i + 2; j < min(i+25, n); j++) {
				int k1 = (n - j - 1) / 2;
				int k2 = (n - j - 2) / 2;
				if(k1 == t - 1) dp[i][1] = max(dp[i][1], a[i] + dp[j][0]);
				if(k2 == t - 1) dp[i][1] = max(dp[i][1], a[i] + dp[j][1]);
			}
		}
		
	}

	long long ans = -1e18;
	for(int i = 0; i < n; i++) {
		if((n-1-i)/2 + 1 == n/2) ans = max(ans, dp[i][0]);
		if((n-2-i)/2 + 1 == n/2) ans = max(ans, dp[i][1]);
	}
	cout << ans;
	return 0;
}
