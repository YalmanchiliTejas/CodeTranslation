/* In the name of Allah */
#include<bits/stdc++.h>
using namespace std;
 
const int N = 3e3 + 5;
long long dp[N][N][2];
int n, a[N];
 
inline void readInput() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
 
inline void solve() {
	for (int i = n - 1; ~i; i--)
		for (int j = i; j < n; j++) {
			dp[i][j][0] = max(dp[i][j - 1][1] + a[j], dp[i + 1][j][1] + a[i]);
			dp[i][j][1] = min(dp[i][j - 1][0] - a[j], dp[i + 1][j][0] - a[i]);
		}
	cout << dp[0][n - 1][0] << endl;
}
 
int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	readInput(), solve();
	return 0;
}
