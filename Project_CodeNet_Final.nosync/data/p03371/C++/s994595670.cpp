#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int f = a*x + b*y;
	int g = 0;
	if (x > y) {
		g = c * 2 * y + a*(x - y);
	}
	if (x == y) {
		g = c * 2 * y;
	}
	if (x < y) {
		g = c * 2 * x + b*(y - x);
	}
	int h = 2 * c*max(x, y);
	cout << min(f, min(g,h)) << endl;
	system("pause");
	return 0;
}