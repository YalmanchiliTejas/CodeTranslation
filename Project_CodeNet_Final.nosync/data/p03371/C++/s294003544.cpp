#include<iostream>
using namespace std;
using ll = long long;

int main() {
	ll a, b, c, x, y, ans;
	cin >> a >> b >> c >> x >> y;
	ans = min(x, y) * min(a + b, 2 * c);
	if (x < y) {
		ll n = y - x;
		ans += n * min(b, 2 * c);
	} else {
		ll n = x - y;
		ans += n * min(a, 2 * c);
	}
	cout << ans << endl;
}