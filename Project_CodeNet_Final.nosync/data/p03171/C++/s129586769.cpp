#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str(x) to_string(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;
const ll MOD998 = 998244353;
const int INF = 1e9;
const ll LLINF = 1e18;

mt19937_64 rng((uint) chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T rnd(T l, T r) {
	return uniform_int_distribution<T>(l, r)(rng);
}

void run() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) {
		cin >> x;
	}
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2)));
	vector<vector<bool>> used(n, vector<bool>(n));
	function<void(int, int)> rec = [&](int l, int r) {
		if (used[l][r]) {
			return;
		}
		if (l == r) {
			dp[l][r][0] = a[l];
			dp[l][r][1] = -a[l];
		} else {
			rec(l + 1, r);
			rec(l, r - 1);
			dp[l][r][0] = max(a[l] + dp[l + 1][r][1], a[r] + dp[l][r - 1][1]);
			dp[l][r][1] = min(dp[l + 1][r][0] - a[l], dp[l][r - 1][0] - a[r]);
		}
		used[l][r] = 1;
	};
	rec(0, n - 1);
	cout << dp[0][n - 1][0] << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}
