#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define inlld2(x, y) scanf("%lld%lld", &x, &y)
#define inlld3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define ind2(x, y) scanf("%d%d", &x, &y)
#define ind3(x, y, z) scanf("%d%d%d", &x, &y, &z)

const int N=2e5+5;
const int MOD=1e9+7;

typedef long long ll;
typedef long double ld;

using namespace std;

ll n, arr[N], alternate_forward[N], alternate_backwards[N], ans[N];

// ll togo[100][100];

// ll get_ans(ll i, ll taken)
// {
// 	if(i > n && taken == n/2)
// 	{
// 		// printf("%lld %lld\n", i, taken);
// 		return 0;
// 	}
// 	if(i > n)
// 		return -1e18;
// 	ll anshere = get_ans(i + 1, taken);
// 	ll x = get_ans(i + 2, taken + 1) + arr[i];
// 	if(x > anshere)
// 	{
// 		anshere = x;
// 		togo[i][taken] = 2;
// 	}
// 	else
// 		togo[i][taken] = 1;
// 	return anshere;
// }

int main()
{
	inlld(n);
	for(ll a = 1; a <=n; a++)
		inlld(arr[a]);
	alternate_forward[1] = arr[1];
	alternate_forward[2] = arr[2];
	for(ll a = 3; a <= n; a++)
		alternate_forward[a] = alternate_forward[a - 2] + arr[a];
	ans[1] = 0;
	ans[2] = max(arr[1], arr[2]);
	ans[3] = max(arr[1], max(arr[2], arr[3]));
	for(ll a = 4; a <= n; a++)
	{
		if(a % 2 == 0)
			ans[a] = max(ans[a - 2] + arr[a], alternate_forward[a - 1]);
		else
			ans[a] = max(ans[a - 1], ans[a - 2] + arr[a]);
	}
	printf("%lld\n", ans[n]);
	// printf("%lld\n", get_ans(1, 0));
	// ll i = 1, taken = 0, lmao = 0;
	// while(i <= n)
	// {
	// 	if(togo[i][taken] == 1)
	// 		i++;
	// 	else
	// 	{
	// 		printf("%lld ", i);
	// 		i += 2;
	// 		taken++;
	// 	}
	// }
	// printf("\n%lld\n", taken);
	// if(n % 2 == 0)
	// {
	// 	ll ans1 = 0, ans2 = 0;
	// 	for(ll a = 1; a <= n; a += 2)
	// 	{
	// 		ans1 += arr[a];
	// 		ans2 += arr[a + 1];
	// 	}
	// 	printf("%lld\n", max(ans1, ans2));
	// 	return 0;
	// }
	// ll ans1 = 0;
	// for(ll a = 2; a <= n; a += 2)
	// 	ans1 += arr[a];
	// alternate_forward[1] = arr[1];
	// alternate_forward[2] = arr[2];
	// for(ll a = 3; a <= n; a++)
	// 	alternate_forward[a] = alternate_forward[a - 2] + arr[a];
	// alternate_backwards[n] = arr[n];
	// alternate_backwards[n - 1] = arr[n - 1];
	// for(ll a = n - 2; a >= 1; a--)
	// 	alternate_backwards[a] = alternate_backwards[a + 2] + arr[a];
	// ll ans2 = ans1;
	// for(ll a = 1; a < n; a++)
	// {
	// 	if(a % 2 == 0)
	// 	{
	// 		if(n + 3 <= n)
	// 			ans2 = max(ans2, alternate_forward[a - 1] + max(alternate_backwards[a + 2], alternate_backwards[a + 3]));
	// 		else if(n + 2 <= n)
	// 			ans2 = max(ans2, alternate_forward[a - 1] + alternate_backwards[a + 2]);
	// 		else
	// 			ans2 = max(ans2, alternate_forward[a - 1]);
	// 		// ans2 = max(ans2, alternate_forward[a - 1] + max(alternate_backwards[a + 2], alternate_backwards[min(n, a + 3)]));
	// 	}
	// 	else
	// 	{
	// 		if(a - 2 >= 1)
	// 			ans2 = max(ans2, max(alternate_forward[a - 1], alternate_forward[a - 2]) + alternate_backwards[a + 2]);
	// 		else if(a - 1 >= 1)
	// 			ans2 = max(ans2, alternate_forward[a - 1] + alternate_backwards[a + 2]);
	// 		else
	// 			ans2 = max(ans2, alternate_backwards[a + 2]);
	// 	}
	// }
	// printf("%lld\n", ans2);
	// // printf("%lld %lld\n", ans1, ans2);
	// printf("%lld\n", max(ans1, ans2));
    return 0;
}