#include <iostream>

using namespace std;

int main()
{
	int a, b, c, x, y;
	int ans = 0;
	
	cin >> a >> b >> c >> x >> y;
	
	while (x > 0 && y > 0) {
		if ((a + b) >= (c * 2)) {
			ans += (c * 2);
			x--;
			y--;
		}
		else {
			ans += (a + b);
			x--;
			y--;
		}
	}
	while (x > 0) {
		if (a > (c * 2)) {
			ans += (c * 2);
			x--;
		}
		else {
			ans += a;
			x--;
		}
	}
	
	while (y > 0) {
		if (b > (c * 2)) {
			ans += (c * 2);
			y--;
		}
		else {
			ans += b;
			y--;
		}
	}
	
	cout << ans << endl;
}