#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int ans = 2e9;

	for (int i = 0; i <= 2 * max(x, y); i += 2) {
		int tmp = a * max(0, x - i / 2) + b * max(0, y - i / 2) + c * i;
		ans = min(ans, tmp);
		// printf("%2d, %9d\n", i, tmp);
	}
	cout << ans << endl;
	return 0;
}
