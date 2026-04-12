#include<iostream>
#include<algorithm>
#include <math.h>
#include <cmath>
using namespace std;
#define ll long long

int main()
{
	ll a, b, c, x, y;
	ll ans = 0;
	cin >> a >> b >> c >> x >> y;

	if (a + b <= 2 * c) {
		cout << a * x + b * y << endl;
		return 0;
	}
	
	if (x == y) {
		cout << c * x * 2 << endl;
		return 0;
	}
	
	if (x > y) {
		ans += c * y * 2;
		x -= y;
		if (a <= c * 2) {
			ans += a * x;
		}
		else {
			ans += c * x * 2;
		}
	}
	else {
		ans += c * x * 2;
		y -= x;
		if (b <= c * 2) {
			ans += b * y;
		}
		else {
			ans += c * y * 2;
		}
	}

	cout << ans << endl;
	return 0;
	
}
