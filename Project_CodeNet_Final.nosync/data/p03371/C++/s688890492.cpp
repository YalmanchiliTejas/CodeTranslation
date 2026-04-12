#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c; cin >> a >> b >> c;
	int x, y; cin >> x >> y;

	const int n = 100000;

	int ans = 2147483647;

	for (int i = 0; i <= n; i++) {

		int x_mai = max(0, x - i);
		int y_mai = max(0, y - i);

		ans = min(ans, c * 2 * i + a * x_mai + b * y_mai);

	}

	cout << ans << endl;
			
	return 0;
}