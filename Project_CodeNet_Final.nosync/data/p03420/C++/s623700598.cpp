#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, a, ans;
int main()
{
	scanf("%lld%lld", &n, &k);
	for (ll i = k+1; i <= n; i++)
	{
		// imagine it is b
		a = n/i;
		ll b = i-k;
		ans += a * (b);
		ans += max((ll)0, n-(a*i)-k+(!!k));

		//printf("%lld %lld\n", i, ans);
	}
	printf("%lld\n", ans);
}