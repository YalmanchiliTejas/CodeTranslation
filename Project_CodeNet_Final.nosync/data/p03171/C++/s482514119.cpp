#include <bits/stdc++.h> // Tomasz Nowak
using namespace std;     // XIII LO Szczecin
using L = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int &ai : a)
		cin >> ai;

	vector<vector<L>> dp(n, vector<L>(n));
	for(int len = 1; len <= n; ++len)
		for(int l = 0; l <= n - len; ++l) {
			int r = l + len - 1;
			if(l == r)
				dp[l][r] = a[l];
			else
				dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
		}
	cout << dp[0][n - 1] << '\n';
}
