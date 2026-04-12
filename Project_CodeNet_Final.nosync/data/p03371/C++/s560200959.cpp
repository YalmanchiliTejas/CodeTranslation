#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int INF = 1e9 + 7, MOD = 1e9 + 7;
const long long LINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	long long ans = 0;
	if (a + b > c * 2) {
		while (x > 0 && y > 0) {
			x--, y--;
			ans += c * 2;
		}
		if (x > 0) {
			if (a < c * 2) {
				while (x > 0) {
					x--, ans += a;
				}
			} else {
				while (x > 0) {
					x--, ans += c * 2;
				}
			}
		}
		if (y > 0) {
			if (b < c * 2) {
				while (y > 0) {
					y--, ans += b;
				}
			} else {
				while (y > 0) {
					y--, ans += c * 2;
				}
			}
		}
	} else {
		while (x > 0) {
			x--, ans += a;
		}
		while (y > 0) {
			y--, ans += b;
		}
	}
	cout << ans << endl;
	return 0;
}