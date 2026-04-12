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

int dp[10005][100][2];
string s;
int n, d;

int digitSum(int pos, int mo, bool tight) {
	if (pos == n) return !mo;
	int &ans = dp[pos][mo][tight];
	if (ans != -1) return ans;

	ans = 0;
	int lim = tight ? s[pos] - '0' : 9;
	for (int i = 0; i <= lim; i++) {
		ans += digitSum(pos + 1, (mo + i) % d, tight and (i == lim));
		ans %= mod;
	}

	return ans;
}

void solve() {
	cin >> s >> d;
	n = s.length();
	memset(dp, -1, sizeof(dp));
	cout << (digitSum(0, 0, 1) - 1 + mod) % mod << endl;
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
