#include<bits/stdc++.h>
using namespace std;

long dp[3000][3000][2];

long solve(int start, int end, int minimize, long a[]) {
	if(start > end) return 0;
	if(dp[start][end][minimize] != -1) return dp[start][end][minimize];
	if(minimize) {
		return dp[start][end][minimize] = 
				min(solve(start + 1, end, minimize ^ 1, a) - a[start],
					solve(start, end - 1, minimize ^ 1, a) - a[end]);
	}
	return dp[start][end][minimize] = 
				max(solve(start + 1, end, minimize ^ 1, a) + a[start],
					solve(start, end - 1, minimize ^ 1, a) + a[end]);
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	long a[n];
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	cout<<solve(0, n - 1, 0, a);
	return 0;
}