#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <functional>
using namespace std;

typedef long long ll;

pair<ll, int> x[100003], y[100003];
vector<pair<ll, int>> edg[100003];
bool used[100003];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> x[i].first >> y[i].first, x[i].second = y[i].second = i;
	sort(x, x + n); sort(y, y + n);
	for (int i = 0; i < n - 1; ++i) {
		edg[x[i].second].push_back({ abs(x[i].first - x[i + 1].first), x[i + 1].second });
		edg[x[i + 1].second].push_back({ abs(x[i].first - x[i + 1].first), x[i].second });
		edg[y[i].second].push_back({ abs(y[i].first - y[i + 1].first), y[i + 1].second });
		edg[y[i + 1].second].push_back({ abs(y[i].first - y[i + 1].first), y[i].second });
	}
	priority_queue<pair<ll, int>> que;
	used[0] = true;
	for (int i = 0; i < (int)edg[0].size(); ++i) que.push({ -edg[0][i].first, edg[0][i].second });
	ll ans = 0;
	while (!que.empty()) {
		ll d = -que.top().first; int pos = que.top().second; que.pop();
		if (used[pos]) continue;
		used[pos] = true;
		ans += d;
		for (int i = 0; i < (int)edg[pos].size(); ++i) {
			if (used[edg[pos][i].second]) continue;
			que.push({ -edg[pos][i].first, edg[pos][i].second });
		}
	}
	cout << ans << endl;
	return 0;
}