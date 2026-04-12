#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

int n;
int a[MAX_N];
map<int, ll> dp[MAX_N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	dp[0][0] = 0;
	dp[1][1] = a[1];
	for (int i = 1; i <= n; ++i) {
		for (int k = max(0, i / 2 - 5); k <= min(n / 2, i / 2 + 5); ++k) {
			if (dp[i - 1].count(k)) {
				dp[i][k] = dp[i - 1][k];
			}
			for (int p = max(0, i - 4); p < i - 1; ++p) {
				if (dp[p].count(k - 1)) {
					if (dp[i].count(k)) {
						dp[i][k] = max(dp[i][k], dp[p][k - 1] + a[i]);
					} else {
						dp[i][k] = dp[p][k - 1] + a[i];
					}
				}
			}
		}
	}
	cout << dp[n][n / 2] << "\n";
	return 0;
}