#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 60;
int n;
ll ans;
ll a[maxn];
void force()
{
	while(a[1] >= n)
	{
		a[1] -= n;
		for(int i = 2; i <= n; ++i) ++a[i];
		sort(a + 1, a + n + 1, greater<ll>());
		++ans;
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1, greater<ll>());
	while(a[1] >= n)
	{
		int r = 1;
		while(r <= n && a[1] - a[r] <= n) ++r;
		--r;
		if(r == n)
		{
			if(a[n] >= n)
			{
				ll c = a[n] - n + 1;
				ans += c * r;
				for(int i = 1; i <= n; ++i) a[i] -= c;
			}
			force();
			break;
		}
		int x = n - r + 1, y = r;
		ll c = (a[1] - a[r + 1]) / (x + y);
		if(a[r] < c * x)
		{
			force();
			break; 
		}
		ans += c * r;
		for(int i = 1; i <= r; ++i) a[i] -= c * x;
		for(int i = r + 1; i <= n; ++i) a[i] += c * y;
		sort(a + 1, a + n + 1, greater<ll>());
	}
	cout << ans << endl;
	return 0;
}
/*
8
2 4 8 9 0 7 0 2
*/