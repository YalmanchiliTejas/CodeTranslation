#include <cstdio>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD (ll)998244353

int l[200001], r[200001];
map<ll, ll> ma;
vector<int> v;


ll a[100001];

int main(void)
{
	ll n, x, m;
	scanf("%lld %lld %lld", &n, &x, &m);
	a[1] = x;
	ma[a[1]] = 1LL;
	ll period, start;
	ll sum = 0;
	for (ll i = 2; i <= 500000LL; i++)
	{
		a[i] = (a[i - 1] * a[i - 1]) % m;
		if (ma.find(a[i]) != ma.end())
		{
			period = i - ma[a[i]];
			start = ma[a[i]];
			break;
		}
		ma[a[i]] = i;
	}
	for (ll i = start; i < start + period; i++)
		sum += a[i];

	ll ans = 0;

	ll rotate = max(0LL, (n - start + 1LL) / period);
	ans += rotate * sum;

	n -= rotate * period;

	for (ll i = 1; i <= n; i++)
		ans += a[i];

	printf("%lld", ans);
	return 0;
}