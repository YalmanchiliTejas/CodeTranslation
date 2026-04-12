#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
#define REP(i,n) for (int i=1;i<=n;i++)
#define print(x) cout << x << endl;
typedef long long ll;

int main() {
	int a ,b, c, x, y, ans; string s; cin >> a >> b >> c >> x >> y;
	if (a + b < 2 * c) {
		ans = a * x + b * y;
	}
	else {
		if (x == y) ans = 2 * c * x;
		else if (x < y) {
			ans = 2 * c * x + b * (y - x);
			for (int i = 1; i <= y - x; i++) {
				ans = min(ans, 2 * c * (x + i) + b * (y - x - i));
			}
		}
		else {
			ans = 2 * c * y + a * (x - y);
			for (int i = 1; i <= x - y; i++) {
				ans = min(ans, 2 * c * (y + i) + a * (x - y - i));
			}
		}
	}
	cout << ans << endl;
	return 0;
}
