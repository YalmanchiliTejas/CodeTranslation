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
	string n;
	cin >> n;
	for (auto &ch : n) {
		ch -= '0';
	}
	int d;
	cin >> d;
	int k = szof(n);
	vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(d, vector<int>(2)));
	dp[0][0][0] = 1;
	auto add = [](int &x, int y) {
		x += y;
		if (x >= MOD) {
			x -= MOD;
		}
	};
	for (int l = 1; l <= k; l++) {
		for (int rem = 0; rem < d; rem++) {
			for (int digit = 0; digit < 10; digit++) {
				if (digit < n[l - 1]) {
					add(dp[l][(rem + digit) % d][1], dp[l - 1][rem][0]);
					add(dp[l][(rem + digit) % d][1], dp[l - 1][rem][1]);
				} else if (digit == n[l - 1]) {
					add(dp[l][(rem + digit) % d][0], dp[l - 1][rem][0]);
					add(dp[l][(rem + digit) % d][1], dp[l - 1][rem][1]);
				} else {
					add(dp[l][(rem + digit) % d][1], dp[l - 1][rem][1]);
				}
			}
		}
	}
	cout << ((dp[k][0][0] + dp[k][0][1]) % MOD + MOD - 1) % MOD << "\n";
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
