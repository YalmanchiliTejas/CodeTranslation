#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	double a, b, ans;
	cin >> a >> b;
	ans = (a * b) / (a + b);
	cout << fixed << setprecision(20) << ans << endl;
	return 0;
}
