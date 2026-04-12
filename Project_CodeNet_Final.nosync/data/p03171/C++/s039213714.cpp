#include "bits/stdc++.h"
#include <unordered_map>
#include <unordered_set>
using namespace std;

const int mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	vector<vector<long long>> dp(n, vector<long long>(n, 0));

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (i > j) continue;
			if (i == j) dp[i][j] = nums[i];
			else {
				dp[i][j] = max(nums[i] - (i + 1 < n ? dp[i + 1][j] : 0), nums[j] - (j - 1 >= 0 ? dp[i][j - 1] : 0 ));
			}
		}
	}

	cout << dp[0][n - 1];
}
