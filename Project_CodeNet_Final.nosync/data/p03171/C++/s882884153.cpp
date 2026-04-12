#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MOD 1000000007
#define ar array
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int32_t main() {
	fast_io;

	// int t; cin >> t;
	// while (t--) {
		
	// }
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<pair<int, int>>> player_score(n, vector<pair<int, int>> (n, {0, 0}));
	for (int i = 0; i < n; i++) {
		player_score[i][i].first = a[i];
		player_score[i][i].second = 0;
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i < n - len + 1; i++) {
			int j = i + len - 1;
			player_score[i][j].first = a[j] + player_score[i][j - 1].second;
			player_score[i][j].second = player_score[i][j - 1].first;
			if (a[i] + player_score[i + 1][j].second > player_score[i][j].first) {
				player_score[i][j].first = a[i] + player_score[i + 1][j].second;
				player_score[i][j].second = player_score[i + 1][j].first;
			}
		}
	}
	cout << player_score[0][n - 1].first - player_score[0][n - 1].second << endl;

	return 0;
}