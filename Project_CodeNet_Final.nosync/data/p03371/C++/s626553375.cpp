#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (a + b < 2 * c) {
		cout << x*a + y*b << endl;
		return 0;
	}
	int mv = min(x, y);
	int dif = abs(x - y);
	int ans = mv * 2 * c;
	if (mv == x) {
		ans += min(b*dif, 2 * c*dif);
	}
	else {
		ans += min(a*dif, 2 * c*dif);
	}
	cout << ans << endl;
	return 0;
}