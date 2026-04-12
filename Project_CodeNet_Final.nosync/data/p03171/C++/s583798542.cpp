#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{	
	int n;
	vector<ll> v;
	cin >> n;
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0) );

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (i == j) {
				dp[i][j] = v[i]; 
			} else {
				dp[i][j] = max(v[i] - dp[i + 1][j], v[j] - dp[i][j - 1]);	
			}
		}
	}

	cout << dp[0][n -1];
	return 0;	
}