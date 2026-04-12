#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = 2000000000;
	for (int i = 0; i <= max(x, y) * 2; i += 2)
		ans = min(ans, a * max(0, x - i / 2) + b * max(0, y - i / 2) + c * i);
	cout << ans << endl;

	return 0;
}
