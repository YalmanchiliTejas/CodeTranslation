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
#include <iomanip>
using namespace std;

typedef long long ll;


int main() {
	int n; cin >> n;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	vector<ll> x(n), y(n);
	vector<pair<ll, ll>> xy(n);
	for (int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		x[i] = a;
		y[i] = b;
		xy[i] = { a, b };
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	ll ans = (x[n - 1] - x[0])*(y[n - 1] - y[0]);

	sort(xy.begin(), xy.end());
	ll r = xy[n - 1].first - xy[0].first, ymin = 1e18, ymax = 0;
	for (int i = 0; i < n - 1; i++) {
		ymin = min(ymin, xy[i].second);
		ymax = max(ymax, xy[i].second);
		r = min(r, max(xy[n - 1].first, ymax) - min(xy[i + 1].first, ymin));
	}
	ans = min(ans, (y[n - 1] - x[0])*r);
	cout << ans << endl;
	return 0;
}