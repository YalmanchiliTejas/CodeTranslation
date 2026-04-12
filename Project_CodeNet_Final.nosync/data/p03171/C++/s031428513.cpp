#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin>>a[i];
	vector<vector<long long>> dp(n, vector<long long>(n));
	for (int i = 0; i < n; i++) dp[i][i] = a[i];
	for (int i = 0; i < n-1; i++) dp[i][i+1] = max(a[i], a[i+1]);
	for (int g = 2; g < n; g++) {
		for (int i = 0, j = g; j < n; i++, j++) {
			dp[i][j] = max(a[i] + min(dp[i+1][j-1], dp[i+2][j]), a[j] + min(dp[i][j-2], dp[i+1][j-1]));
		}
	}
	long long s = 0;
	for (int i : a) s += i;
	long long x = dp[0][n-1], y = s - x;
	cout<<x-y<<endl;
	return 0;
}
