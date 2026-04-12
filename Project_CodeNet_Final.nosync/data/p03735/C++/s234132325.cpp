#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 100000000000;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<P> a(n);
	ll rmax = 0, rmin = INF, bmax = 0, bmin = INF;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		rmax = max(rmax, x);
		rmin = min(rmin, x);
		bmax = max(bmax, y);
		bmin = min(bmin, y);
		a[i].first = x;
		a[i].second = y;
	}
	sort(a.begin(), a.end());

	ll ans = (rmax - rmin) * (bmax - bmin);

	rmax = bmax;
	ll d = a.back().first - a.front().first;
	ll ymin = a.front().second, ymax = a.front().second;
	for (int i = 1; i < n; i++) {
		d = min(d, max(ymax, a.back().first) - min(ymin, a[i].first));
		ymin = min(ymin, a[i].second);
		ymax = max(ymax, a[i].second);
	}
	d = min(d, ymax - ymin);
	ans = min(ans, (rmax - rmin) * d);
	cout << ans << endl;
	return 0;
}