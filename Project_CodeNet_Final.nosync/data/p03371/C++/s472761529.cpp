#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ab = c * 2;
	int ans = 0;
	while (x > 0 || y > 0)
	{
		if (x > 0 && y > 0)
		{
			if (ab <= a + b)
			{
				ans += ab;
				x--; y--;
			}
			else
			{
				ans += a+b;
				x--; y--;
			}
		}
		else if (x > 0)
		{
			ans += min(ab, a);
			x--;
		}
		else
		{
			ans += min(ab, b);
			y--;
		}
	}
	cout << ans << endl;
}

