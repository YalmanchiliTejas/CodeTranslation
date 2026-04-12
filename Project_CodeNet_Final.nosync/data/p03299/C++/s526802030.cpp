#include <algorithm>
#include <utility>
#include <cstdio>
#define MOD 1000000007
typedef long long ll;
inline ll quick_pow(ll a, int n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		n >>= 1;
	}
	return res;
}
int arr[105];
std::pair<ll, ll> work(int l, int r, int h)
{
	if (l > r)
		return {1, (MOD + 1) / 2};
	int pos = std::min_element(arr + l, arr + r + 1) - arr;
	ll val = quick_pow(2, arr[pos] - h);
	if (l == r)
		return {val, val};
	auto x = work(l, pos - 1, arr[pos]), y = work(pos + 1, r, arr[pos]);
	return {val * x.first % MOD * y.first % MOD,
			4 * x.second % MOD * y.second % MOD + (val - 1) * x.first % MOD * y.first % MOD};
}
int main()
{
	// freopen("AGC026-D.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	printf("%lld\n", work(0, n - 1, 1).second * 2 % MOD);
	return 0;
}
