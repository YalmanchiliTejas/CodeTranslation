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
#define MOD (ll)1000000007

ll a[200001], sum[200001];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		sum[i] = (a[i] + sum[i - 1]) % MOD;
	}

	ll ans = 0;
	for (int i = n; i >= 1; i--)
		ans = (ans + a[i] * sum[i - 1]) % MOD;
	printf("%lld", ans);
	return 0;
}