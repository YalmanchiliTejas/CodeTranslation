#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

signed main(void)
{
	ll k, a, b, cnt;
	cin >> k >> a >> b;
	k -= a;
	if (k <= 0)
		cnt = 1;
	else
	{
		if (a > b)
		{
			cnt = k / (a - b);
			if (k % (a - b) != 0)
				cnt++;
			cnt *= 2;
			cnt++;
		}
		else
			cnt = -1;
	}
	cout << cnt << endl;
	return 0;
}
