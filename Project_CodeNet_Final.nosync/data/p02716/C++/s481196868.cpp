#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long
using namespace std;

void chmax(int &a, int b) { a = max(a, b); }

int INF = 1e+15;
int n;
int a[200000];
int dp[200001][3];

int tle() {
	int i, j;
	
	int ret = -INF;
	for (i = 0; i < (1 << n); i++) {
		bool used[20] = {false};
		int ucnt = 0;
		rep(j, n) {
			if ((i >> j) & 1) {
				used[j] = true;
				ucnt++;
			}
		}
		if (ucnt != n / 2) continue;
		
		rep(j, n - 1) {
			if (used[j] && used[j + 1]) break;
		}
		if (j < n - 1) continue;
		
		int s = 0;
		rep(j, n) if (used[j]) s += a[j];
		ret = max(ret, s);
	}
	return ret;
}

int solveOdd() {
	int i, j;

	rep(i, n) rep(j, 3) dp[i][j] = -INF;
	
	dp[0][2] = a[0];
	dp[1][1] = a[1];
	dp[2][0] = a[2];
	rep(i, n) {
		rep(j, 3) {
			if (dp[i][j] <= -INF) continue;
			if (i + j >= n - 1) continue;
			
			for (int k = 0; k <= j; k++) {
				if (i + 2 + k >= n) continue;
				chmax(dp[i + 2 + k][j - k], dp[i][j] + a[i + 2 + k]);
			}
		}
	}
	
	int ans = -INF;
	rep(i, n) rep(j, 3) if (i + j == n - 1) ans = max(ans, dp[i][j]);
	return ans;
}

int solveEven() {
	int i, j;

	rep(i, n) rep(j, 2) dp[i][j] = -INF;
	
	dp[0][1] = a[0];
	dp[1][0] = a[1];
	rep(i, n) {
		rep(j, 2) {
			if (dp[i][j] <= -INF) continue;
			if (i + j >= n - 1) continue;
			
			for (int k = 0; k <= j; k++) {
				if (i + 2 + k >= n) continue;
				chmax(dp[i + 2 + k][j - k], dp[i][j] + a[i + 2 + k]);
			}
		}
	}
	
	int ans = -INF;
	rep(i, n) rep(j, 2) if (i + j == n - 1) ans = max(ans, dp[i][j]);
	return ans;
}

int solve() {
	if (n % 2 == 0) return solveEven();
	return solveOdd();
}

void stress(int ln) {
	n = ln;
	for (int t = 0; t < 100000; t++) {
		if (t % 1000 == 0) cerr << "t = " << t << endl;
		
		int i;
		rep(i, n) {
			a[i] = rand() % 100 - 50;
		}
		int res1 = tle();
		int res2 = solve();
		if (res1 != res2) {
			cout << "Wrong Answer [" << i << "]" << endl;
			cout << "res1 = " << res1 << endl;
			cout << "res2 = " << res2 << endl;
			cout << "a = " << endl;
			rep(i, n) {
				cout << a[i] << " ";
			}
			cout << endl;
			return;
		}
	}
	
	cout << "AC" << endl;
}

signed main() {
	cin >> n;
	int i; rep(i, n) cin >> a[i];
	cout << solve() << endl;
	return 0;
}