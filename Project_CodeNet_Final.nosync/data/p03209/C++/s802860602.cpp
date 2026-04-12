#include<bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> burger[51];

ll rec(int n, ll x) {
	if (x == 0) return 0;
	ll ret;
	if (x == burger[n].first) {
		ret = burger[n].second;
	} else if (x - 1 <= burger[n - 1].first) {
		ret = rec(n - 1, x - 1);
	} else {
		ret = burger[n - 1].second + 1 + rec(n - 1, x - (2 + burger[n - 1].first));
	}
	return ret;
}

int main() {
	burger[0] = make_pair(1LL, 1LL);
	for(int i=1;i<=50;i++) {
		burger[i].first = 2 * burger[i - 1].first + 3;
		burger[i].second = 2 * burger[i - 1].second + 1;
	}

	ll N, X;
	cin >> N >> X;
	cout << rec(N, X) << endl;

	return 0;
}
