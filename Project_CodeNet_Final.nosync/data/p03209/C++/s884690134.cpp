#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll a[60], p[60];
ll f(ll n, ll x)
{
	if (n == 0) return 1;
	if (x == 1) return 0;
	else if (x <= a[n - 1] + 1)
		return f(n - 1, x - 1);
	else if (x <= a[n - 1] + 2)
		return p[n - 1] + 1; 
	else if (x <= a[n] - 1)
		return f(n - 1, x - a[n - 1] - 2) + p[n - 1] + 1;
	else if (x <= a[n])
		return   p[n];
}

signed main(void)
{
	ll n, x, ans;

	cin >> n >> x;
	a[0] = p[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		a[i] += 2 * a[i - 1] + 3; 
		p[i] += 2 * p[i - 1] + 1; 
	}
	ans = f(n, x);
	cout << ans << endl;
	return 0;
}
