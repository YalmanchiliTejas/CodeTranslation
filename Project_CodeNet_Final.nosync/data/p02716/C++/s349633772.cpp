#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>
#include <functional>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, m, n) for(int i = m; i < n; ++i)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define RREP(i, m, n) for(int i = n; i >= m; --i)
#define llrep(i, n) for(ll i = 0; i < n; ++i)
#define llREP(i, m, n) for(ll i = m; i < n; ++i)
#define llrrep(i,n) for(ll i = n; i >= 0; --i)
#define llRREP(i, m, n) for(ll i = n; i >= m; --i)

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;

using namespace std;

const long long _MOD = 1000000007;
const long long MOD = 998244353;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	ll* a = new ll[n];
	rep(i, n) cin >> a[i];

	ll** dp = new ll*[n/2];
	rrep(i, n / 2 - 1) {
		dp[i] = new ll[2 + (n&1)];

		rep(j, 2 + (n & 1)) {
			if (i == n / 2 - 1) {
				dp[i][j] = a[i * 2 + j];
			}
			else {
				dp[i][j] = dp[i + 1][j] + a[i * 2 + j];
				REP(k, j + 1, 2 + (n & 1)) {
					dp[i][j] = max(dp[i][j], dp[i + 1][k] + a[i * 2 + j]);
				}
			}
		}
	}

	ll ans = max(dp[0][0], dp[0][1]);
	if (n & 1) ans = max(ans, dp[0][2]);
	cout << ans << "\n";

	return 0;
}
