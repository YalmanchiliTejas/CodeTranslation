#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	cout << min({ a * x + b * y, c * 2 * x + b * max(0, y - x), a * max(0, x - y) + c * 2 * y }) << endl;
	return 0;
}