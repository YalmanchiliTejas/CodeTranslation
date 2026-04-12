#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while (cin >> n) {
		vector<int> a(n * 3);
		for (int &x : a) {
			cin >> x;
			x--;
		}
		vector<vector<int>> dp(n, vector<int>(n, -1e9));
		vector<int> mid(n, -1e9);
		dp[a[0]][a[1]] = dp[a[1]][a[0]] = 0;
		mid[a[0]] = mid[a[1]] = 0;
		int ans = 0, add = 0;
		for (int i = 2; i + 2 < n * 3; i += 3) {
			vector<int> b = {a[i], a[i + 1], a[i + 2]};
			sort(b.begin(), b.end());
			if (b[0] == b[2]) {
				add++;
				continue;
			}
			vector<tuple<int, int, int>> v;
			if (b[0] == b[1]) {
				for (int j = 0; j < n; j++) {
					v.emplace_back(j, b[2], dp[b[0]][j] + 1);
				}
			} else if (b[1] == b[2]) {
				for (int j = 0; j < n; j++) {
					v.emplace_back(j, b[0], dp[b[2]][j] + 1);
				}
			}
			v.emplace_back(b[0], b[1], max(ans, dp[b[2]][b[2]] + 1));
			v.emplace_back(b[0], b[2], max(ans, dp[b[1]][b[1]] + 1));
			v.emplace_back(b[1], b[2], max(ans, dp[b[0]][b[0]] + 1));
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 3; k++) {
					v.emplace_back(j, b[k], mid[j]);
				}
			}
			for (auto &[x, y, z] : v) {
				dp[x][y] = max(dp[x][y], z);
				dp[y][x] = max(dp[y][x], z);
				mid[x] = max(mid[x], z);
				mid[y] = max(mid[y], z);
				ans = max(ans, z);
			}
		}
		ans = max(ans, dp[a.back()][a.back()] + 1);
		cout << ans + add << '\n';
	}
	return 0;
}
