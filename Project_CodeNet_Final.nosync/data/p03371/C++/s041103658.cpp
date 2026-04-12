#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int n, m, l, cnt, ans;
	n = min(x, y);
	l = max(x, y);
	m = min(c * 2, a + b);
	ans = l * m;
	cnt = n * m;
	x -= n; y -= n;
	cnt += x * a + y * b;
	ans = min(ans, cnt);
	cout << ans << endl;
	return 0;
}
