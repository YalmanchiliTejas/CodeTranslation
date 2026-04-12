#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int main()
{
	int a, b, c;
	int x, y;
	cin >> a >> b >> c >> x >> y;

	int ans = 0;

	if (a + b > 2 * c)
	{
		ans += min(x, y) * c * 2;

		int sa = abs(x - y);

		if (x - y > 0)
		{
			if (a > 2 * c)
			{
				ans += sa * c * 2;
			}
			else
			{
				ans += sa * a;
			}
		}
		else
		{
			if (b > 2 * c)
			{
				ans += sa * c * 2;
			}
			else
			{
				ans += sa * b;
			}
		}
	}
	else
	{
		ans += a * x;
		ans += b * y;
	}

	cout << ans << endl;

	return 0;
}