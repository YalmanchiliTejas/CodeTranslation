#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int main()
{
	int n;
	cin>>n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	vector< vector<int> > memo(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++) {
		int idx = i + 2;
		for (int j = i + 1; j < n; j++) {
			while (idx < n) {
				if (a[idx] == 2 * a[j] - a[i]) {
					memo[i][j] = idx;
					break;
				} else if (a[idx] > 2 * a[j] - a[i]) {
					break;
				}
				idx++;
			}
			if (idx >= n) break;
		}
	}

	vector< vector<int> > dp(n, vector<int>(n, 2));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (memo[i][j] == -1) continue;
			dp[j][memo[i][j]] = max(dp[j][memo[i][j]], dp[i][j] + 1);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}
