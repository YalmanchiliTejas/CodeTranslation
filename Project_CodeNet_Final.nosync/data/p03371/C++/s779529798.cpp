#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <numeric>


int main() {
	int a, b, c, x, y;

	std::cin >> a >> b >> c >> x >> y;

	if (a + b < 2 * c) {
		std::cout << a * x + b * y;
	}
	else {
		int ans = std::min(x, y) * c * 2;
		if (x < y) {
			if (b < 2 * c) {
				ans += (y - x) * b;
			}
			else {
				ans += (y - x) * c * 2;
			}
		}
		else {
			if (a < 2 * c) {
				ans += (x - y) * a;
			}
			else {
				ans += (x - y) * c * 2;
			}
		}
		std::cout << ans;
	}

	return 0;
}