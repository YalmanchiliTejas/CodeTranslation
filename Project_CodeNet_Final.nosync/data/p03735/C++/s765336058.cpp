#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

const ll INF = 100000000000;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> x(n), y(n);
	ll rmax = 0, rmin = INF, bmax = 0, bmin = INF;
	vector<P> hoge;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		if (x[i] > y[i]) swap(x[i], y[i]);
		hoge.emplace_back(x[i], i);
		rmax = max(rmax, x[i]);
		rmin = min(rmin, x[i]);
		bmax = max(bmax, y[i]);
		bmin = min(bmin, y[i]);
	}

	ll ans = (rmax - rmin) * (bmax - bmin);
	sort(hoge.begin(), hoge.end());
	ll vmax = y[hoge.front().second], vmin = y[hoge.front().second];
	ll d = hoge.back().first - hoge.front().first;
	for (int i = 1; i < n; i++) {
		d = min(d, max(vmax, hoge.back().first) - min(vmin, hoge[i].first));
		vmax = max(vmax, y[hoge[i].second]);
		vmin = min(vmin, y[hoge[i].second]);
	}
	d = min(d, vmax - vmin);
	rmax = bmax;
	ans = min(ans, (rmax - rmin) * d);
	cout << ans << endl;
	return 0;
}