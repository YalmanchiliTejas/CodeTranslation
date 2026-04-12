#include <bits/stdc++.h>
using namespace std;
						
#define fast_cin() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define int long long

const int N = 3005;

int dp[N][N][2];
int n, a[N];

int solve(int i, int j, int cur) {
	if (i > j) return 0;
	int &ans = dp[i][j][cur];
	if (ans != -1) return ans;
	if (cur == 0) ans = max(solve(i + 1, j, 1) + a[i], solve(i, j - 1, 1) + a[j]);
	else ans = min(solve(i + 1, j, 0) - a[i], solve(i, j - 1, 0) - a[j]);
	return ans;
}
				
int32_t main() {
	fast_cin();  

	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> a[i];
	memset(dp, -1, sizeof dp);
	int ans = solve(0, n - 1, 0);
	cout << ans << endl;
	
	return 0;
}