#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

int main() {
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll sum = 0, z = min(x, y);
	for (ll i = 0; i < z; i++) {
		sum += min(2 * c, a + b);
	}
	ll m = max(x, y);
	if (m == x) {
		for (ll i = 0; i < abs(x - y); i++) {
			sum += a;
		}
	}
	else {
		for (ll i = 0; i < abs(x - y); i++) {
			sum += b;
		}
	}
	ll sum2 = 0;
	for (ll i = 0; i < m; i++) {
		sum2 += min(2 * c, a + b);
	}

	cout << min(sum, sum2) << endl;

	return 0;
}