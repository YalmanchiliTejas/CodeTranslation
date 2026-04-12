#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, ans;

int main()
{
	cin >> n >> k;
	for (ll r = k;r <= n-1;r++)
	{
		for (ll v = 1;v <= n-r;)
		{
			ll lo = (n-r+v+1)/(v+1);
			lo = max(lo, r+1);
			ll hi = (n-r)/v;
			if (hi >= lo) ans += (hi-lo+1)*v;
			if (lo == r+1) break;
			v = (n-r)/(lo-1);
		}
		if (r) ans += n-r;
	}
	cout << ans << endl;
	return 0;
}
