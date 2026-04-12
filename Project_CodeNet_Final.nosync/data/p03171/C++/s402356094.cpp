#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <stack>
#include <iomanip>
#include <set>
#include <queue>
#include <unordered_map>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int maxn = 1e5 + 7;
const int inf = 2e9 + 7;
const ll infl = 1e18 + 7;
const long double eps = 1e-9;
const ll mod = 1e9 + 7;

int main() {
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif // _DEBUG

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	bool f = true;
	if (n % 2 == 0) f = false;
	for (int j = 1; j <= n; j++) {
		for (int i = 0; i < n; i++) {
			if (i + j - 1 >= n) break;
			if (f) {
				if (j == 1) dp[i][i] = a[i];
				else if (j % 2 == 1) {
					dp[i][i + j - 1] = max(dp[i][i + j - 2] + a[i + j - 1], dp[i + 1][i + j - 1] + a[i]);
				}
				else {
					dp[i][i + j - 1] = min(dp[i][i + j - 2] - a[i + j - 1], dp[i + 1][i + j - 1] - a[i]);
				}
			}
			else {
				if (j == 1) dp[i][i] = -a[i];
				else if (j % 2 == 1) {
					dp[i][i + j - 1] = min(dp[i][i + j - 2] - a[i + j - 1], dp[i + 1][i + j - 1] - a[i]);
				}
				else {
					dp[i][i + j - 1] = max(dp[i][i + j - 2] + a[i + j - 1], dp[i + 1][i + j - 1] + a[i]);
				}
			}
		}
	}
	cout << dp[0][n - 1];
	return 0;
}
