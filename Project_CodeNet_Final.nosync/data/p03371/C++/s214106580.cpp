#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	long long ret = 0;
	long long minxy = min(x, y);

	ret += min(minxy * 2 * c, minxy * a + minxy * b);
	if (x < y) {
		ret += min((y - x) * b, (y - x) * 2 * c);
	}
	else {
		ret += min((x - y) * a, (x - y) * 2 * c);
	}

	cout << ret << endl;

	return 0;
}