#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> P;
typedef vector<P> vP;
int main() {
	int n;
	cin >> n;
	vl X(n), Y(n);
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		X[i] = min(x, y);
		Y[i] = max(x, y);
	}
	ll MIN = X[0], MAX = 0;
	ll xmax = 0;
	ll ymin = Y[0];
	for (int i = 0; i < n; i++) {
		MIN = min(MIN, X[i]);
		MAX = max(MAX, Y[i]);
		xmax = max(xmax, X[i]);
		ymin = min(ymin, Y[i]);
	}
	ll ans = (xmax - MIN)*(MAX - ymin);
	vP xy(n);
	for (int i = 0; i < n; i++) {
		xy[i] = P(X[i], Y[i]);
	}
	sort(xy.begin(), xy.end());
	ll yl = MAX;
	ll yr = MIN;
	ll mlen = min(xmax - MIN,MAX-ymin);
	for (int i = 0; i < n-1; i++) {
		yl = min(yl, xy[i].second);
		yr = max(yr, xy[i].second);
		mlen = min(mlen, max(yr, xmax) - min(xy[i + 1].first, yl));
	}
	ans = min(ans, mlen*(MAX - MIN));
	cout << ans << endl;
}