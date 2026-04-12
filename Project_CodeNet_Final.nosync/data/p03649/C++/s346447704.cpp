#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll a[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int pos;
	ll ans = 0, d;
	bool p = true;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	while (p)
	{
		pos = 1;
		if (a[pos] < n) p = false;
		for (int i = 2; i <= n; ++i)
		{
			if (a[i] > a[pos])
			{
				pos = i;
			}
		}
		if (a[pos] >= n) p = true;
		if (p)
		{
			d = a[pos] / n;
			ans += d;
			a[pos] %= n;
			for (int i = 1; i <= n; ++i)
			{
				if (i != pos) a[i] += d;
			}
		}
	}
	cout << ans << endl;
	return 0;
}