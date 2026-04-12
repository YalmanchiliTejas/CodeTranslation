#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	int ans = 0;
	if (a + b <= 2 * c) {
		ans = x * a + y * b;
	}
	else { // 2 * c < a + b
		ans += 2 * c * min(x, y);
		if (x <= y) {
			if (2 * c < b) {
				ans += (y - x) * 2 * c;
			}
			else {
				ans += (y - x) * b;
			}			
		}
		else { // y < x
			if (2 * c < a) {
				ans += (x - y) * 2 * c;
			}
			else {
				ans += (x - y) * a;
			}
		}
	}
	cout << ans << endl;
	return 0;
}