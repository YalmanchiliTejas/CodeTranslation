#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define int long long

const int N = 1001;
const int MOD = 1e9 + 7;

int add(int a, int b) {
	return (a + b) % MOD;
}

int mul(int a, int b) {
	return (a * b) % MOD;
}

int binpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int divv(int a, int b) {
	return mul(a, binpow(b, MOD - 2));
}

int f[N];
int C[N][N];

void init() {
	for (int n = 0; n < N; n++) {
		C[n][0] = 1;
		C[n][n] = 1;
		for (int k = 1; k + 1 <= n; k++) {
			C[n][k] = add(C[n - 1][k], C[n - 1][k - 1]);
		}
	}
	f[0] = 1;
	for (int i = 1; i < N; i++) {
		f[i] = mul(f[i - 1], i);
	}
}

int dp[N][N];

int solve(int n, int cnt, int sz) {
	int sel = C[n][cnt * sz];
	//
	int all = sz * cnt;
	int c = 1;
	while (all > 0) {
		c = mul(c, C[all][sz]);
		all -= sz;
	}
	c = divv(c, f[cnt]);
	//
	return mul(sel, c);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	dp[0][n] = 1;
	for (int i = 1; i <= n; i++) {
		for (int tk = 0; i * tk <= n; tk++) {
			if (tk > 0 && (i < a || i > b)) continue;
			if (tk > 0 && (tk < c || tk > d)) continue;
			// if (i == 1 && tk == 1) {
			// 	cerr << -1 << endl;
			// }
			for (int prev = 0; prev + i * tk <= n; prev++) {
				if (dp[i - 1][prev + i * tk] == 0) continue;
				// += dp[i - 1][prev] * prob
				int prob = solve(prev + i * tk, tk, i);
				// cerr << prev + i * tk << endl;
				// if (i == 1 && tk == 1 && prev + i * tk == n) {
				// 	cerr << "hr " << endl;
				// } 
				dp[i][prev] = add(dp[i][prev], mul(dp[i - 1][prev + i * tk], prob));
			}
		}
	}
	cout << dp[n][0] << endl;
	// cout << dp[1][n - 1] << endl;
	// cout <
}
