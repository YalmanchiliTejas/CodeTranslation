#include <bits/stdc++.h>
using namespace std;

int a, b, c, x, y, ans;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> a >> b >> c >> x >> y;
	a = min(a, 2 * c);
	b = min(b, 2 * c);
	while(x + y) {
		if(x && y) {
			ans += min(a + b, 2 * c);
			x--;
			y--;
		}
		else if(x) {
			ans += a;
			x--;
		}
		else {
			ans += b;
			y--;
		}
	}
	cout << ans;
	return 0;
}