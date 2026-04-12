#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll solve(vector<int> a, int k) {
	int n = (int) a.size();
	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1'000'000'000'000'000LL));

	dp[0][0] = a[0];
	dp[1][0] = a[1];
	dp[0][1] = dp[1][1] = 0;

	for (int i = 2; i < n; i += 2) {
		dp[i][0] = dp[i - 2][0] + a[i];
		dp[i][1] = dp[i - 2][1];

		dp[i + 1][0] = max(dp[i - 1][0], dp[i - 2][0]) + a[i + 1];
		dp[i + 1][1] = max(dp[i - 1][1], dp[i - 2][1]);

		if (i >= 4) {
			dp[i][1] = max(dp[i][1], max(dp[i - 4][0], dp[i - 3][0]));
			dp[i + 1][1] = max(dp[i + 1][1], max(dp[i - 4][0], dp[i - 3][0]));
		}

		dp[i][1] += a[i];
		dp[i + 1][1] += a[i];
	}

	if (n % 2 == 1) {
		return max(dp[n - 3][0], max(dp[n - 2][0], dp[n - 1][1]));
	}

	return max(dp[n - 2][k], dp[n - 1][k]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);

	for (int &x : a) {
		cin >> x;
	}

	if (n == 3) {
		cout << *max_element(a.begin(), a.end());
		return 0;
	}

	if (n % 2 == 0) {
		cout << solve(a, 0);
	} else {
		cout << solve(a, 1);
	}

	return 0;
}