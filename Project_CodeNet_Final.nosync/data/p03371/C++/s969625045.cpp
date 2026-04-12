#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;

int main()
{
	ll a, b, c, x, y;
	ll ans = 0;
	cin >> a >> b >> c >> x >> y;
	if (a + b > 2 * c) {
		ll temp = min(x, y);
		x -= temp; y -= temp;
		ans += (temp*c * 2);
		if (a > 2 * c) {
			ans += (x * 2 * c);
		}
		else
			ans += (x*a);
		if (b > 2 * c) {
			ans += (y * 2 * c);
		}
		else
			ans += (b*y);
	}
	else {
		ans += (a*x + b*y);
	}
	cout << ans << endl;
}