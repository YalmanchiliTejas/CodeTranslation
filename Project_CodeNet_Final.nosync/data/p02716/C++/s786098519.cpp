#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <math.h>
#include <cassert>
#include <unordered_map>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;



int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<vector<ll>> dp(n + 20, vector<ll>(4, -1e18));
	dp[0][0] = 0;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	int sz = 1;
	sz += n % 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sz + 1; j++) {
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
			ll add = dp[i][j];
			if ((i + j) % 2 == 0) add += a[i];
			dp[i + 1][j] = max(add, dp[i + 1][j]);
		}
	}
	cout << dp[n][sz];
}