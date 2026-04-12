#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int maxNum = x <= y ? y : x;
	int ans = INT_MAX;
	for (int i = 0; i <= maxNum; i++)
	{
		ans = min(ans, i * 2 * c + max(0, x - i) * a + max(0, y - i) * b);
	}
	cout << ans << endl;
}