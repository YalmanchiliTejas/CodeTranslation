#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9+7;
int n, a, b, c, d;
long long cache[1001][1001];
long long fac[1001];

long long inv(long long val)
{
	long long ret = 1, temp = INF-2;
	while(temp)
	{
		if(temp%2)
			ret = (ret * val) % INF;
		temp /= 2;
		val = (val*val) % INF;
	}
	return ret;
}

long long f(int idx, int remain)
{
	if(idx == b+1)
	{
		if(remain == 0)	return 1;
		else	return 0;
	}

	long long& result = cache[idx][remain];
	if(result != -1)	return result;

	result = f(idx+1, remain);
	if(remain < (long long)c * idx)
		return result;

	long long bunja = 1, bunmo = 1;

	for(int i = 0; i < c; i++)
		bunmo = (bunmo * fac[idx]) % INF;

	for(int i = c; i <= d; i++)
	{
		if(remain < (long long)i*idx)	break;
		bunja = (fac[remain] * inv(fac[remain-i*idx])) % INF;

		long long cur = f(idx+1, remain-i*idx);
		cur = (cur*bunja) % INF;
		cur = (cur*inv(bunmo)) % INF;
		cur = (cur*inv(fac[i])) % INF;
		result = (result + cur)%INF;
		
		bunmo = (bunmo * fac[idx]) % INF;
	}
	return result;
}

int main(void)
{
	fac[0] = 1;
	for(int i = 1; i <= 1000; i++)
		fac[i] = (fac[i-1]*i) % INF;

	memset(cache, -1, sizeof(cache));
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	printf("%lld\n", f(a, n));
	return 0;
}