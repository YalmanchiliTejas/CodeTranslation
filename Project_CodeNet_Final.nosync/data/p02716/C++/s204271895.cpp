#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <cassert>
#include <random>
using namespace std;
using ll = long long;


int main() {
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<vector<ll>> dp(n + 2, vector<ll>(3));
	for (int i = 0; i < n; i++) {
		dp[i][0] = (i >= 2 ? dp[i - 2][0] : 0) + a[i];
		dp[i][1] = max({
			(i >= 2 ? dp[i - 2][1] : 0) + a[i],
			(i >= 3 ? dp[i - 3][0] : 0) + a[i]
		});
		dp[i][2] = max({
			(i >= 2 ? dp[i - 2][2] : 0) + a[i],
			(i >= 3 ? dp[i - 3][1] : 0) + a[i],
			(i >= 4 ? dp[i - 4][0] : 0) + a[i]
		});
	}
	if (n & 1)
		cout << max({ dp[n - 1][0] - min(a[0], a[n - 1]), dp[n - 1][1], dp[n - 1][2],
			dp[n - 2][0], dp[n - 2][1] }) << endl;
	else
		cout << max({ dp[n - 1][0], dp[n - 1][1], dp[n - 2][0] }) << endl;
	return 0;
}