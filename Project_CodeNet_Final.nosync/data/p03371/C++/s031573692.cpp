#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int a1 = (x * a + y * b);
	int a2 = max(x, y) * c * 2;
	int a3 = (min(x, y) * c * 2);
	if (x > y)
		a3 += (x - y) * a;
	else
		a3 += (y - x) * b;
	int ans = min(a1, a2);
	ans = min(ans, a3);
	cout << ans;
 	return 0;
}
