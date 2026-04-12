#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
	int x, y, z, ans;
	cin >> x >> y >> z;

	x -= z;
	ans = x / (y + z);
	cout << ans << endl;
  	return 0;
}
