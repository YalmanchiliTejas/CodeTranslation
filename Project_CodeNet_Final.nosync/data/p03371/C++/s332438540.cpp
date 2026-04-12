#include <iostream>
using namespace std;
int main(void) {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int min_price = 1e9;
	for (int i = 0; i <= 100000; ++i) {
		int price = i * 2 * c + max(0, x - i) * a + max(0, y - i) * b;
		min_price = min(min_price, price);
	}
	cout << min_price << endl;
	return 0;
}