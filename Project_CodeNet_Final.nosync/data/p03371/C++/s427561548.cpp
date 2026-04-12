#include <iostream>
using namespace std;
int main() {
	int a, b, c, x, y;
	long ans, sum1, sum2;
	cin >> a >> b >> c >> x >> y;
	ans = a * x + b * y;
	sum1 = 2 * c * max(x, y);
	if (x > y) sum2 = 2 * c * y + (x - y) * a;
	else sum2 = 2 * c * x + (y - x) * b;
	ans = min(min(ans, sum1), sum2);
	cout << ans;
} 