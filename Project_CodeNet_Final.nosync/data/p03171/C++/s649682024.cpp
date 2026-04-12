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

int sign(int p) {
	if (p == 0) return 1;
	return -1;
}

int n;
int a[3000];
int dp[3000][3000];	//dp[区間] = 先手の得点, playerは区間の長さから定まるので記録しなくてOK
bool used[3000][3000];

int dfs(int l, int r, int p) {
	if (l > r) return 0;
	if (used[l][r]) return dp[l][r];
	
	int x = dfs(l + 1, r, !p) + a[l] * sign(p);
	int y = dfs(l, r - 1, !p) + a[r] * sign(p);
	if (p == 0) return dp[l][r] = max(x, y);
	used[l][r] = true;
	return dp[l][r] = min(x, y);
}

signed main() {
	int i;
	
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i];
	cout << dfs(0, n - 1, 0) << endl;
	return 0;
}