#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<ll>> dp(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		dp[i][i] = ((n - 1) % 2 == 0 ? a[i] : -a[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if ((j - i) % 2 != (n - 1) % 2) {
				dp[i][j] = min(-a[i] + dp[i + 1][j], -a[j] + dp[i][j - 1]);
			}
			else {
				dp[i][j] = max(a[i] + dp[i + 1][j], a[j] + dp[i][j - 1]);
			}
		}
	}
	cout << dp[0][n - 1];
}
