#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int mn_r = INF;
	int mx_r = 0;
	int mn_b = INF;
	int mx_b = 0;

	vector<pair<int, int>> balls(n);
	for (auto& [a, b] : balls) {
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}

		mn_r = min(mn_r, a);
		mx_r = max(mx_r, a);
		mn_b = min(mn_b, b);
		mx_b = max(mx_b, b);
	}

	long long ans = 1LL * (mx_r - mn_r) * (mx_b - mn_b);

	mx_r = mx_b;
	set<pair<int, int>> blue;
	for (int i = 0; i < n; ++i) {
		auto& [a, b] = balls[i];
		if (a == mn_r && b == mx_r) {
			goto done;
		}
		if (a != mn_r && a < b) {
			swap(a, b);
		}

		blue.emplace(b, i);
	}

	while (!blue.empty()) {
		int ndx = blue.begin()->second;

		ans = min(ans, 1LL * (mx_r - mn_r) * (blue.rbegin()->first - blue.begin()->first));
		if (balls[ndx].first == mn_r || balls[ndx].first == mx_r || balls[ndx].first <= balls[ndx].second) {
			goto done;
		}

		blue.erase(blue.begin());
		swap(balls[ndx].first, balls[ndx].second);
		blue.emplace(balls[ndx].second, ndx);
	} done:

	cout << ans << "\n";
    return 0;
}