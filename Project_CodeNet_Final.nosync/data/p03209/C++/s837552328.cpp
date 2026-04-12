#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;

ll func(ll l, ll x, vector<ll>& len, vector<ll>& d) {
	if (l >= x) { 
		ll res = 0;
		return res; 
	}
	if (l == 1) {
		ll res = x - 1LL;
		if (x == len[l]) { return 3LL; }
		return x - 1;
	}

	ll res;
	if (len[l] / 2 > x) {
		res = func(l - 1, x - 1, len, d);
	} else if (len[l] / 2 == x) {
		res = d[l - 1];
	} else if ((len[l] / 2 + 1) == x) {
		res = 1 + d[l - 1];
	} else if (len[l] - l > x) {
		res = func(l - 1, x - len[l] / 2 - 1, len, d) + 1 + d[l - 1];
	} else if (len[l] - l <= x) {
		res = d[l];
	}

	return res;
}

int main() {
	ll N, X;
	cin >> N >> X;
	vector<ll> len(N + 1, 0);
	vector<ll> d(N + 1, 0);
	len[0] = 1;
	d[0] = 1;
	for (int i = 1; i <= N; ++i) {
		len[i] = 2 * len[i - 1] + 3;
		d[i] = 2 * d[i - 1] + 1;
	}

	ll res = func(N, X, len, d);
	cout << res << endl;

	return 0;
}
