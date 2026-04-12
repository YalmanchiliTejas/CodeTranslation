#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for(int n, m; cin >> n >> m && (n | m);) {
		vector<int> times{0};
		times.reserve(n + m + 1);

		for(int i = 0; i < n; ++i) {
			int t;
			cin >> t;
			times.emplace_back(t);
		}

		for(int j = 0; j < m; ++j) {
			int t;
			cin >> t;
			times.emplace_back(t);
		}

		sort(times.begin(), times.end());

		int ans = 0;
		for(unsigned i = 1; i < times.size(); ++i) {
			ans = max(ans, times[i] - times[i - 1]);
		}

		cout << ans << endl;
	}

	return 0;
}