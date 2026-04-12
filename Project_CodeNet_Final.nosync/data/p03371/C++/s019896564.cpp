#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	long a, b, c, x, y, sum = 0;
	cin >> a >> b >> c >> x >> y;

	if (a + b > 2 * c) {
		int mi = min(x, y);
		x -= mi;
		y -= mi;
		sum = c * 2 * mi;

		if (x && a > 2*c) {
			sum += c * 2 * x;
			x = 0;
		}
		else if (y && b > 2*c) {
			sum += c * 2 * y;
			y = 0;
		}
	}

	sum += a * x + b * y;

	cout << sum << endl;

    return 0;
}

