#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long ll;

int main () {
	ll N;
	ll X, M;
	pair <int, ll> p[100001];
	cin >> N >> X >> M;
	for (int m=0; m<M; m++) {
		p[m].first = p[m].second = -1;
	}
	ll tmp = 0, ans;
	bool flag = true;
	ll i;
	for (i=0; i<N&&flag; i++) {
		tmp += X;
		p[X].first = i;
		p[X].second = tmp;
		X = X*X;
		X %= M;
		flag = (p[X].first == -1);
	}
	if (i==N) {
		ans = tmp;
	} else {
		ll steps = i - p[X].first;
		ll cnts = (N-i)/steps;
		ll v = (N-i)%steps;
		ll diff = tmp - p[X].second + X;
		for (ll j=0; j<v; j++) {
			tmp += X;
			X = X*X;
			X %= M;
		}
		ans = tmp + diff*cnts;
	}
	cout << ans << endl;
	return 0;
}