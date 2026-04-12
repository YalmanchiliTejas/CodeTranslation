#include <bits/stdc++.h>
using namespace std;

signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int64_t n, x, m;
	cin >> n >> x >> m;
	deque <int> cycle;
	map <int, int> seen;
	while (seen[x] < 2) {
		cycle.push_back(x);
		++seen[x];
		(x *= x) %= m;
	}
	int64_t ans = 0, took = 0;
	while (took < n && seen[cycle.front()] < 2) {
		ans += cycle.front();
		cycle.pop_front();
		++took;
	}
	n -= took;
	if (n) {
		cycle.resize(cycle.size() / 2);
		int64_t s = 0;
		for (size_t i = 0; i < cycle.size(); ++i)
			s += cycle[i];
		ans += s * (n / int64_t(cycle.size()));
		n %= int64_t(cycle.size());
		for (int64_t i = 0; i < n; ++i)
			ans += cycle[i];
	}
	cout << ans << '\n';
}
