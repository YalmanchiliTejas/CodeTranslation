#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

int main() {
	int a, b, c, x, y,money=0;
	cin >> a >> b >> c >> x >> y;

	if (2 * c < a + b) {
		if (x < y) { money += (c*x * 2); if (2 * c < b) money += ((y - x)*c * 2);else money += ((y - x)*b); }
		else {money += (y*c * 2);if (2 * c <a) money += ((x - y)*c * 2);else money += ((x - y)*a);
		}
	}
	else {
		money += x * a;
		money += y * b;
	
	}

	cout << money << endl;

	return 0;
}