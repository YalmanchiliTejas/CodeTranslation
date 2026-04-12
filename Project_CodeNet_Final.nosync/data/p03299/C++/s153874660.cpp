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
std::pair<ll, ll> work(int l, int r, int d)
{
	int pos = l;
	for (int i = l; i <= r; i++)
	{
		if (arr[i] < arr[pos])
			pos = i;
	}
	ll val = quick_pow(2, arr[pos] - d);
	if (l == r)
		return {val, val};
	if (pos == l)
	{
		auto res = work(l + 1, r, arr[pos]);
		return {(2 * res.first + (val - 1) * res.second) % MOD, val * res.second % MOD};
	}
	if (pos == r)
	{
		auto res = work(l, r - 1, arr[pos]);
		return {(2 * res.first + (val - 1) * res.second) % MOD, val * res.second % MOD};
	}
	auto x = work(l, pos - 1, arr[pos]), y = work(pos + 1, r, arr[pos]);
	return {4 * x.first % MOD * y.first % MOD + (val - 1) * x.second % MOD * y.second % MOD
		, val * x.second % MOD * y.second % MOD};
}
int main()
{
	// freopen("AGC026-D.in", "r", stdin);
	int n; 
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		arr[i]--;
	}
	printf("%lld\n", work(0, n - 1, 0).first * 2 % MOD);
	return 0;
}
