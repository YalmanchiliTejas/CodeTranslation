#include<cstdio>
typedef long long ll;
int n;
ll X;
ll len[64], patties[64];
ll f(int n, ll m)
{
	if (n == 0) // single patty
		return (m > 0) ? 1 : 0;
	ll ret = 0;
	if (m == 0) return ret;
	m--; // bun
	if (m >= len[n - 1]) // n-1 level
	{
		ret += patties[n - 1];
		m -= len[n - 1];
	}
	else return ret + f(n - 1, m);
	if (m == 0) return ret;
	m--; ret++; //patty
	if (m >= len[n - 1]) // n-1 level
	{
		ret += patties[n - 1];
		m -= len[n - 1];
	}
	else return ret + f(n - 1, m);
	return ret;
}
int main()
{
	len[0] = 1; patties[0] = 1;
	for (int i = 1; i <= 50; i++)
	{
		len[i] = len[i - 1] * 2 + 3;
		patties[i] = patties[i - 1] * 2 + 1;
	}
	scanf("%d%lld", &n, &X);
	printf("%lld\n", f(n, X));
	return 0;
}
