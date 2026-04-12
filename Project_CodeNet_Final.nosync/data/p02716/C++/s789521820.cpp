#include "bits/stdc++.h"
#define FI first.first
#define SE first.second
#define TH second
#define fi first
#define se second
#define th second

using namespace std;

class DebugStream {}LOG;
template <typename T>DebugStream &operator<<(DebugStream &s, const T&) { return s; }
#ifdef DEBUG
#define LOG clog
#endif

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 2e5 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20, bs = 29;

ll arr[maxN], dp[maxN][2];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	dp[1][0] = LLONG_MIN / 3;
	dp[1][1] = arr[1];
	for(int i = 2; i <= n; i++) {
		if(i & 1) {
			dp[i][0] = arr[i] + max(dp[i - 2][0], (i > 2? dp[i - 3][0]: LLONG_MIN / 3));
			dp[i][1] = arr[i] + dp[i - 2][1];
		} else {
			dp[i][0] = arr[i] + max(dp[i - 2][0], (i > 2? dp[i - 3][1]: LLONG_MIN / 3));
		}
	}
	//for(int i = 0; i < n; i++) LOG << dp[i][0] << ' ' << dp[i][1] << '\n';
	ll ans = dp[n][0];
	int x = 0;
	if(n % 2 == 0) x = 1;
	ans = max(ans, dp[n - 1][x]);
	cout << ans << '\n';
}

