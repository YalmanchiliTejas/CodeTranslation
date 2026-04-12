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
using pil = std::pair<int, long long>;
using pli = std::pair<long long, int>;
using plpii = std::pair<long long, std::pair<int, int>>;
using pdd = std::pair<double, double>;

using namespace std;

const long long INF = 1e18;
const long long _MOD = 1000000007;
const long long MOD = 998244353;
const int ALPHABET = 27;
const double pi = 3.14159265358979;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, s;
	cin >> n >> s;
	int* a = new  int[n];
	rep(i, n) cin >> a[i];

	ll* dp = new ll[s + 1];
	memset(dp, 0, sizeof(ll)*(s + 1));

	ll ans = 0;
	rep(i, n) {
		RREP(j, a[i], s) {
			dp[j] += dp[j - a[i]];
			dp[j] %= MOD;
		}

		++dp[0];
		++dp[a[i]];

		ans += dp[s];
		ans %= MOD;
	}

	cout << ans << "\n";

	return 0;
}

