#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int n; 
ll arr[55]; 
inline bool chk(ll num)
{
	ll res = 0; 
	for (int i = 0; i < n; i++)
		res += (arr[i] + num) / (n + 1); 
	return res >= num; 
}
int main()
{
	// freopen("ARC079-E.in", "r", stdin); 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i); 
	ll ans = 1e18; 
	for (int i = 0; i <= n; i++)
	{
		ll l = 0, r = 1e16, res; 
		while (l <= r)
		{
			ll m = l + r >> 1; 
			if (chk(m * (n + 1) + i))
				l = m + 1; 
			else
			{
				res = m; 
				r = m - 1; 
			}
		}
		// cout << i << " " << res << endl; 
		ans = min(ans, res * (n + 1) + i); 
	}
	printf("%lld\n", ans - 1);
	return 0; 
}
