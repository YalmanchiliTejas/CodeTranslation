#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	ll a, b, c,x, y;
	cin >> a >> b >> c >> x >> y;
	ll ans = 0;
	if (a + b > c * 2) {
		ans += min(x, y) * 2*c;
		if (x >= y) {
			ans += min((x - y) * a, (x - y) * 2 * c);
		}
		else {
			ans += min((y - x) * b, (y - x) * 2 * c);
		}

	}
	else {
		ans += x * a + b * y;
	}
	cout << ans << endl;
	return 0;
}