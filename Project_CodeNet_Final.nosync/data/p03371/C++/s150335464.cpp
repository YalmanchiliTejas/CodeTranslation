#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long a, b, c, x, y, m;

	cin >> a >> b >> c >> x >> y;

	m = a * x + b * y;

	if (c * 2 <= a + b) {
		m -= (a + b - c * 2) * min(x, y);
		m = min(m, 2 * c * max(x, y));
	}

	cout << m << endl;

	return 0;
}