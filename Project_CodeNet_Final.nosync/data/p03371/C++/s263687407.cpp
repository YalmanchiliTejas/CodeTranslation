#include<iostream>
#include<string>

using namespace std;

int main() {
	int a, b, c, x, y, g, h, m, n;

	cin >> a >> b >> c >> x >> y;

	g = a * x; //純粋にAを必要枚数買った場合のAの金額
	h = b * y; //純粋にBを必要枚数買った場合のBの金額

	if (x > y) {
		m = c *2* x;
	}
	else {
		m = c * 2*y;
	}					//純粋にABを必要枚数分買った場合のABの金額

	if (x > y) {
		n = c * 2*y + a*(x-y);
	}
	else {
		n = c * 2*x + b*(y-x);
	}					//少ない方の枚数に合わせてABを買った場合のABの金額

	if (g + h < m) {
		if (n < g + h) {
			if (x > y) {
				cout << n << endl;
			}
			else {
				cout << n << endl;
			}
		}
		else {
			cout << g + h << endl;
		}
	}
	else {
		if (n < m) {
			if (x > y) {
				cout << n << endl;
			}
			else {
				cout << n << endl;
			}
		}
		else {
			cout << m << endl;
		}
	}
	return 0;
}