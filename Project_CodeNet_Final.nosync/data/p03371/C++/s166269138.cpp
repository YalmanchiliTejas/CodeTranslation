#include <iostream>
using namespace std;

int main() {
	int a, b, c, x, y;
	int i, ans = 1000000000, temp, max;

	cin >> a >> b >> c >> x >> y;

	if (x > y)	max = x;
	else max = y;

	int nx, ny;
	for (i = 0; i <= max; i++) {
		nx = x - i;	ny = y - i;
		if (nx < 0)	nx = 0;
		if (ny < 0)	ny = 0;
		temp = a * nx + b * ny + c * 2 * i;
		if (ans > temp)	ans = temp;
	}

	cout << ans << endl;

	return 0;
}