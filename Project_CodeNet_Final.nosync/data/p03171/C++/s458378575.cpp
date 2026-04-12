#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
vector<int> a, ra;

long long INF = 1ll << 60;
long long dp[3001][3001];

long long dfs(int left, int right) {
	if (left + right == n) return 0;
	bool check = (left + right) % 2;
	if (dp[left][right] != -INF) return dp[left][right];
	if (check) {
		return dp[left][right] = min(dfs(left + 1, right) - a[left], dfs(left, right + 1) - ra[right]);
	}
	else {
		return dp[left][right] = max(dfs(left + 1, right) + a[left], dfs(left, right + 1) + ra[right]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto&& i : a) {
		cin >> i;
	}
	ra.resize(n);
	for (int i = 0; i < n; i++) {
		ra[i] = a[n - i - 1];
	}
	fill(dp[0], dp[3001], -INF);
	cout << dfs(0, 0) << "\n";
}