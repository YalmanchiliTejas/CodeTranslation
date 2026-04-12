#include <bits/stdc++.h>
using namespace std;

int main()
{
	int64_t a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int64_t inf = (1LL << 60);

	int64_t ans = inf;

	for (int64_t i = 0; i <= 2 * max(x, y); i += 2)
	{
		ans = min(ans, c * i + a * max<int64_t>(0, (x - i / 2)) + b * max<int64_t>(0, (y - i / 2)));
	}

	cout << ans << endl;

	return 0;
}