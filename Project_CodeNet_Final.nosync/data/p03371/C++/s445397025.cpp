#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int money = 0;
	if (c <= (a + b) / 2) {
		if (x <= y) {
			money = 2 * c * x + (y - x) * b;
			if (money > 2 * c * y) money = 2 * c * y;
		}
		else {
			money = 2 * c * y + (x - y) * a;
			if (money > 2 * c * x) money = 2 * c * x;
		}
	}
	else {
		money = a * x + b * y;
	}
	cout << money << endl;
	return 0;
}