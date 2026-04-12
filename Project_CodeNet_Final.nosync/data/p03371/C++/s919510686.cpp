#include <bits/stdc++.h>
using namespace std;

int a, b, c, x, y;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> a >> b >> c >> x >> y;
	if (2 * c >= (a + b))
		return cout << x * a + y * b,0;
	int res = min(x, y) * 2 * c;
	if (x < y) {
		if (2 * c < b) {
			res += (y - min(x, y)) * 2 * c;
		}
		else
			res += (y - min(x, y)) * b;
	}
	else {
		if (2 * c < a) {
			res += (x - min(x, y)) * 2 * c;
		}
		else
			res += (x - min(x, y)) * a;
	}
	cout << res;
}
