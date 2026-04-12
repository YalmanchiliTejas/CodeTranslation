#include <iostream>
#include <algorithm>
using namespace std;

int	main() {
	int	a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (2 * c >= a + b) {
		cout << x * a + y * b << endl;
		return 0;
	}
	if (x > y && a <= 2 * c) {
		cout << (x - y) * a + y * 2 * c << endl;
		return 0;
	}
	if (x < y && b <= 2 * c) {
		cout << x * 2 * c + (y - x) * b << endl;
		return 0;
	}
	cout << max(x, y) * 2 * c << endl;
	return 0;
}
