#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<long long> points(n);
	for(long long& x : points) {
		scanf("%lld", &x);
	}
	vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(n));
	for(int i=0; i<n; ++i) {
		dp[i][i].first = points[i];
		dp[i][i].second = 0;
	}
	for(int i=2; i<=n; ++i) {
		for(int j=0; j<n-i+1; ++j) {
			int start = j, end = j+i-1;
			dp[start][end].first = max(points[end] + dp[start][end-1].second, points[start] + dp[start+1][end].second);
			if(points[end] + dp[start][end-1].second >= points[start] + dp[start+1][end].second) {
				dp[start][end].second = dp[start][end-1].first;
			} else {
				dp[start][end].second = dp[start+1][end].first;
			}
		}
	}
	printf("%lld\n", dp[0][n-1].first - dp[0][n-1].second);
	return 0;
}
		
