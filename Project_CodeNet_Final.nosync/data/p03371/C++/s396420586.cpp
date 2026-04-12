#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c, x, y, price;
	cin >> a >> b >> c >> x >> y;

	int min_price = x * a + y * b;

	for (int i = 0; i <= 100000; i++) {
		price = 2 * c * i + a * max(0, x - i) + b * max(0, y - i);
		if (price < min_price) min_price = price;
	}

	cout << min_price << endl;

	return 0;
}
