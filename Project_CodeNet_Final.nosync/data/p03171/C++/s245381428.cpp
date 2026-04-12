#include <vector>
#include <iostream>

using namespace std;
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

#define ff first
#define ss second

int main() {

	int n; cin >> n;
	vector<int> a(n); for (int i = 0; i <= n - 1; i++) cin >> a[i];

	vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(n, {0, 0}));

	for (int dist = 0; dist <= n - 1; dist++) {
		for (int i = 0; i + dist <= n - 1; i++) {
			int j = i + dist;

			if (i == j) {
				if ((j - i + 1) % 2 == (n % 2)) dp[i][j] = {a[i], 0};
				else dp[i][j] = {0, a[i]};
			}
			else {
				if ((j - i + 1) % 2 == (n % 2)) {
					if (dp[i + 1][j].ff + a[i] - dp[i + 1][j].ss > dp[i][j - 1].ff + a[j] - dp[i][j - 1].ss)
						dp[i][j] = {dp[i + 1][j].ff + a[i], dp[i + 1][j].ss};
					else
						dp[i][j] = {dp[i][j - 1].ff + a[j], dp[i][j - 1].ss};
				}
				else {
					if (dp[i + 1][j].ff - dp[i + 1][j].ss - a[i] < dp[i][j - 1].ff - dp[i][j - 1].ss - a[j])
						dp[i][j] = {dp[i + 1][j].ff, dp[i + 1][j].ss + a[i]};
					else
						dp[i][j] = {dp[i][j - 1].ff, dp[i][j - 1].ss + a[j]};
				}
			}
		}
	}
	cout << dp[0][n - 1].ff - dp[0][n - 1].ss;

	return 0;
}