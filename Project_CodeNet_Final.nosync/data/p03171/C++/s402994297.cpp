#include<bits/stdc++.h>

#ifdef LOCAL
#include "prabh.hpp"
#endif

#define int long long
#define pb push_back
#define range(v) v.begin(),v.end()
#define rrange(v) v.rbegin(), v.rend()
#define mod (int)(1e9 + 7)
#define inf (int)(5e18)
#define N (int)(2e5 + 10)

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &i : a) cin >> i;
	vector<vector<int>> dp(n, vector<int>(n));

	for (int l = n - 1; l >= 0; l--) {
		for (int r = l; r < n; r++) {
			if (l == r) dp[l][r] = a[l];
			else if (l + 1 == r) dp[l][r] = max(a[l], a[r]);
			else {
				int &ans = dp[l][r];
				ans = a[l] + min(dp[l + 2][r], dp[l + 1][r - 1]),
				ans = max(ans, a[r] + min(dp[l + 1][r - 1], dp[l][r - 2]));
			}
		}
	}

	int tot = accumulate(range(a), 0ll);
	int ans = 2 * dp[0][n - 1] - tot;
	cout << ans << endl;

}
// Remember to clear the global containers



// Got stuck and want to leave ? look at the bottom once..
int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cin.tie(nullptr);
	int t_c = 1;
	// cin >> t_c;
	while (t_c--)
		solve();
}
/* Come on Dude .. Dont get up until u get the solution
 * Giving up not gonna help ryt ? So get ur lazy ass to code already
 * You can do it ... Stay Calm and Dont Panic :)
 */
