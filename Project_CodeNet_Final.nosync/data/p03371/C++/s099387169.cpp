#include <bits/stdc++.h>
using namespace std;
int main() {
	int64_t a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int64_t ans = 0;
	int64_t merged = min(x, y);
	if (2 * c < (a + b)) {
		ans += merged * 2 * c;
	}
	else {
		ans += merged * (a + b);
	}
	if (x == y) {}
	else if (x > y){
		if (2 * c < a) {
			ans += (x - y) * 2 * c;
		}
		else {
			ans += (x - y) * a;
		}
	}
	else{
		if (2 * c < b) {
			ans += (y - x) * 2 * c;
		}
		else {
			ans += (y - x) * b;
		}
	}
	cout << ans << endl;
}