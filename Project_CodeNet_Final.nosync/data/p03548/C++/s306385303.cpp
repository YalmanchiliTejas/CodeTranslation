#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int x, y, z;

	cin >> x >> y >> z;
	int ans = 0;

	x -= z;
	while (x >= 0)
	{
		x -= (y + z);
		ans++;
	}
	cout << ans - 1 << endl;
}

