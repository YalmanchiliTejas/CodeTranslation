/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10, mod = 1e9 + 7;

ll dp[N], pref[N][2];

ll solve(int n, int bound, bool parity);

int main() {
	fast_cin();
	int n, m; string s;
	cin >> n >> m >> s;
	s += (s.back() ^ 'R' ^ 'B');
	vector<int> parts;
	int cur = 1;
	for (int i = 1; i <= m; ++i) {
		if (s[i] != s[i - 1]) {
			parts.pb(cur);
			cur = 1;
		} else {
			++cur;
		}
	}
	int bound = parts[0] + (1 - (parts[0] & 1));
	for (int i = 2; i + 1 < parts.size(); i += 2) {
		if (parts[i] & 1) {
			bound = min(bound, parts[i]);
		}
	}
	if (parts.size() == 1) {
		cout << (solve(n, n, false) + 1) % mod << '\n';
	} else {
		cout << solve(n, bound, true) << '\n';
	}
}

ll solve(int n, int bound, bool parity) {
	dp[0] = 1;
	pref[0][0] = 1;
	if (!parity) {
		pref[0][1] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		int lo = max(0, i - bound - 1), hi = i - 2;
		if (lo <= hi) {
			dp[i] = pref[hi][hi & 1] - (lo > 0 ? pref[lo - 1][hi & 1] : 0);
			dp[i] += mod;
			dp[i] %= mod; 
		}
		pref[i][0] = pref[i - 1][0];
		pref[i][1] = pref[i - 1][1];
		pref[i][i & 1] += dp[i];
		pref[i][i & 1] %= mod;
		if (!parity) {
			pref[i][(i + 1) & 1] = pref[i][i & 1];
		}
		// cout << i << ' ' << dp[i] << '\n';
	}
	ll ans = dp[n];
	for (int i = 1; i < n and i <= bound; ++i) {
		int lo = max(i, n + (i - 1) - bound) - i, hi = n - i - 1;
		if (lo <= hi) {
			ans += pref[hi][n & 1] - (lo > 0 ? pref[lo - 1][n & 1] : 0);
			ans += mod;
			ans %= mod;
		}
	}
	return ans;
}