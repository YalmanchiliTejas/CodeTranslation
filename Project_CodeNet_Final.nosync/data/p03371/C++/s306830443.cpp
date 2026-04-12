#include<bits/stdc++.h>
using namespace std;

int a, b, c, x, y;
int ans = 0;
int main() {
	cin >> a >> b >> c >> x >> y;
	if(a + b > c + c)	 {
		int d = min(x, y);
		y -= d;
		x -= d;
		ans += c * 2 * d;
	}
	int res = a * x + b * y;
	res = min(res, c * 2 * max(x, y));
	cout << ans + res;
}