#include <iostream>
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int d = x - y;
	int t = 0;
	if (y - x >= 0) {
	    d = y - x;
	    t = 1;
	}
	int price = 0;
	if (t == 0) {
	    if (a <= c * 2) price = a * d;
	    else price = d * c * 2;
	} else {
	    if (b <= c * 2) price = b * d;
	    else price = d * c * 2;
	}
	if (a + b <= c * 2) price = price + (a + b) * (x + y - d) / 2;
	else price = price + (c * 2) * (x + y - d) / 2;
	cout << price;
}
