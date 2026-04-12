#include<iostream>
using namespace std;
typedef long long ll;
int main() {
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (x > y) {
		if (a > c * 2)cout << x * c * 2 << endl;
		else if (a + b > c * 2)cout << c * 2 * y + a * (x-y) << endl;
		else cout << a * x + b * y << endl;
	}
	else {
		if (b > c * 2)cout << y * c * 2 << endl;
		else if (a + b > c * 2)cout << c * 2 * x + b * (y-x) << endl;
		else cout << a * x + b * y << endl;
	}
	return 0;
}