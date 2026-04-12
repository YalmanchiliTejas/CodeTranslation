#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
using namespace std;

typedef long long ll;

int vmax, vmin;
int xmax, xmin, ymax, ymin;
int x[200003], y[200003];
bool ched[200003];

int main() {
	int n; cin >> n;
	vmin = 1e9;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		vmax = max(vmax, max(x[i], y[i]));
		vmin = min(vmin, min(x[i], y[i]));
	}
	xmin = vmin; ymax = vmax;
	xmax = 0; ymin = 1e9;
	for (int i = 0; i < n; ++i) {
		xmax = max(xmax, min(x[i], y[i]));
		ymin = min(ymin, max(x[i], y[i]));
	}
	ll ans = (ll)(xmax - xmin)*(ll)(ymax - ymin);
	ymin = vmin; ymax = vmax;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	for (int i = 0; i < n; ++i) {
		if (y[i] < x[i]) swap(x[i], y[i]);
		que.push({ x[i], i });
		xmin = min(xmin, x[i]);
		xmax = max(xmax, x[i]);
	}
	bool flag = false;
	while (!que.empty()) {
		int v = que.top().first, pos = que.top().second; que.pop();
		if (ched[pos]) {
			flag = true;
			continue;
		}
		ched[pos] = true;
		xmax = max(xmax, y[pos]);
		que.push({ y[pos], pos });
		if (!flag) xmin = que.top().first;
		ans = min(ans, (ll)(xmax - xmin)*(ll)(ymax - ymin));
	}
	cout << ans << endl;
	return 0;
}