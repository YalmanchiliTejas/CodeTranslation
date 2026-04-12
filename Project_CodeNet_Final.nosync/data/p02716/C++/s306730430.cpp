#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll dp[200010][5];
const ll INF = -1e16;
ll a[200010],n;
ll func(ll here, ll ch) {
	if (here >= n)
	{
		if (ch == 0)
			return 0;
		else
			return INF;
	}
	if (ch < 0)return INF;
	ll& ret = dp[here][ch];
	if (ret != -1)return ret;
	ret = INF;

	ret = max(ret, func(here + 2, ch) + a[here]);
	ret = max(ret, func(here + 1, ch - 1));
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	ll sum = 0;
	sum = n / 2;
	sum += sum;
	if (n % 2)
		a[n] = -1e10;
	n++;
	printf("%lld", func(0, n-sum));
}