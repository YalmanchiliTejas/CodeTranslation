#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, maxi, cnt; cin >> n;
	vector<int> h(n);

	rep(i, n) cin >> h[i];
	maxi = h[0];
	cnt = 1;
	rep(i, n - 1)
	{
		if (maxi <= h[i + 1])
		{
			cnt++;
			maxi = h[i + 1];
		}
	}
	cout << cnt << endl;
	return 0;
}
