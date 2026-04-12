/* به نام یزدان */
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3000 + 3;
long long n, a[MAX_N], dp[MAX_N][MAX_N][2];

void read_input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void solve() {
	for (int dif = 0; dif < n; dif++)
		for (int i = 0; i + dif < n; i++) {
			int j = i + dif;
			dp[i][j][0] = max(dp[i + 1][j][1] + a[i], dp[i][j - 1][1] + a[j]);
			dp[i][j][1] = min(dp[i + 1][j][0] - a[i], dp[i][j - 1][0] - a[j]);
		}
}

void print_output() {
	cout << dp[0][n - 1][0];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	read_input();
	solve();
	print_output();
}
