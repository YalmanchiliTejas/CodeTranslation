#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a, b, c;
	int x, y;

	cin >> a >> b >> c >> x >> y;

	int sum = 0;
	if (a + b < c * 2) {
		sum += a * x + b * y;
	}
	else {
		sum += min(x, y) * 2 * c;

		int d;
		if (x == min(x, y)) {
			d = b;
		}
		else {
			d = a;
		}

		if (d < c * 2) {
			sum += d * (max(x, y) - min(x, y));
		}
		else {
			sum += c * 2 * (max(x, y) - min(x, y));
		}
	}
	cout << sum << endl;
}