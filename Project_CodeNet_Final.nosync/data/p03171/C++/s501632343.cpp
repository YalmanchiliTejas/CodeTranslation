// CODE © by 𝕌𝕥𝕜𝕒𝕣𝕤𝕙 𝔾𝕒𝕣𝕘
// Copying or sharing of this code without permission of the Author is strictly prohibited!!!
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Speed ios::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define endl "\n"
int power(int x, int n, int mod) {int res = 1; x %= mod; while (n) {if (n & 1)res = (res * x) % mod; x = (x * x) % mod; n >>= 1;} return res;}
int dp[3001][3001];
int f(int arr[], int si, int ei, int ch, int t) {
	if (dp[si][ei] != INT_MIN)return dp[si][ei];
	if (ch == 0) {
		// if (ei == 0)return arr[ei];
		// if (si == t - 1)return arr[si];
		if (si == ei)return arr[si];
		int a1, a2;
		if (dp[si + 1][ei] == INT_MIN)dp[si + 1][ei] = f(arr, si + 1, ei, 1, t);
		if (dp[si][ei - 1] == INT_MIN)dp[si][ei - 1] = f(arr, si, ei - 1, 1, t);
		a1 = arr[si] + dp[si + 1][ei];
		a2 = arr[ei] + dp[si][ei - 1];
		// cout << "ans by removing " << arr[si] << " is " << a1 << endl;
		// cout << "ans by removing " << arr[ei] << " is " << a2 << endl;
		return max(a1, a2);
	}
	if (ch == 1) {
		// if (si == t - 1)return (-1 * arr[si]);
		// if (ei == 0)return (-1 * arr[ei]);
		int a1, a2;
		if (si == ei)return (-1 * arr[si]);
		if (dp[si + 1][ei] == INT_MIN)dp[si + 1][ei] = f(arr, si + 1, ei, 0, t);
		if (dp[si][ei - 1] == INT_MIN)dp[si][ei - 1] = f(arr, si, ei - 1, 0, t);
		a1 = -1*arr[si] + dp[si + 1][ei];
		a2 = -1*arr[ei] + dp[si][ei - 1];
		return min(a1, a2);
	}
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int a = 0, b = 0, c = 0, d = 0, i = 0, j = 0, k = 0, t = 0, n = 0, q = 0;
	for(int i=0;i<=3000;i++)for(int j=0;j<=3000;j++)dp[i][j]=INT_MIN;
	cin >> n;
	int arr[n];
	for (i = 0; i < n; i++) {cin >> arr[i]; }
	// for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	cout << f(arr, 0, n - 1, 0, n);
}