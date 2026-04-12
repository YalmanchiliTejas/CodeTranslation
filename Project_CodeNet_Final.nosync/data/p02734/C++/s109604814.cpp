#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long
using namespace std;

int mod = 998244353;
int n, s;
int a[3000];
int dp[3001][3001];

signed main() {
	int i, j;
	
	cin >> n >> s;
	rep(i, n) cin >> a[i];
	
	rep(i, n) dp[i][0] = 1;
	rep(i, n) {
		rep(j, s + 1) {
			dp[i + 1][j] += dp[i][j];
			dp[i + 1][j] %= mod;
			
			if (j + a[i] <= s) {
				dp[i + 1][j + a[i]] += dp[i][j];
				dp[i + 1][j + a[i]] %= mod;
			}
		}
	}
	
	int ans = 0;
	rep(i, n + 1) {
		ans += dp[i][s];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}