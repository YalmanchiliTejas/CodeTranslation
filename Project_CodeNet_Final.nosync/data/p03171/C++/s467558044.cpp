#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> a;
vector<vector<bool> > used;
vector<vector<long long> > dp;

long long solve(int l, int r) {
	if (l > r) return 0;
	if (used[l][r]) return dp[l][r];
	used[l][r] = true;
	return dp[l][r] = max(a[r] - solve(l, r - 1), a[l] - solve(l + 1, r));
}

int main() {
	cin >> n;
	a.resize(n);
	used.assign(n, vector<bool>(n));
	dp.assign(n, vector<long long>(n));
	for (int i = 0; i < n; ++i) cin >> a[i];
	cout << solve(0, n - 1) << endl;

	return 0;
}