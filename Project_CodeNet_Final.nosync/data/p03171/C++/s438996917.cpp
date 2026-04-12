#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<bool> vb;
#define MOD 1000000007

int main() {
	int n; 
	cin >> n;
	vll seq(n);
	for (int i = 0; i < n; ++i) 
		cin >> seq[i];
	vector<vll> dp(n, vll(n, 0));
	for (int i = 0; i < n; ++i) 
		dp[i][i] = seq[i];
	for (int interval = 1; interval < n; ++interval) {
		for (int i = 0; i < n-interval; ++i) {
			int j = i+interval;
			dp[i][j] = max ( seq[i] - dp[i+1][j],
											 seq[j] - dp[i][j-1]);
		}
	}
	cout << dp[0][n-1];
	return 0;
}