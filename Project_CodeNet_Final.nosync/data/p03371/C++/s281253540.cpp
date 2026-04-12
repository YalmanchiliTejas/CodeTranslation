#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
#include <math.h>
#include <map>
#include <vector>
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int min_mai = min(x, y);
	long long ans = 0;
	if (a + b > 2 * c) {
		ans += c * 2 * min_mai;
		if (x >= y) {
			if (a < 2 * c) {
				ans += a*(x - y);
			}
			else {
				ans += 2 * c*(x - y);
			}
		}
		else {
			if (b < 2 * c) {
				ans += b*(y - x);
			}
			else {
				ans += 2 * c*(y - x);
			}
		}
	}
	else {
		cout << a*x + b*y << endl;
		return 0;
	}
	cout << ans << endl;

	return 0;
}