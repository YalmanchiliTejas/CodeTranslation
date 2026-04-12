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
using namespace std;

int INF = 1000000007;
int n;
int a[100000];
int dp[100001];

signed main() {
	int i;
	
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) a[i] *= -1;
	
	rep(i, n + 1) dp[i] = INF;
	dp[0] = -INF;
	
	rep(i, n) {
		dp[upper_bound(dp, dp + n + 1, a[i]) - dp] = a[i];
	}
	
	for (i = n; i >= 0; i--) if (dp[i] != INF) break;
	cout << i << endl;
	return 0;
}