#include "bits/stdc++.h"
using namespace std;
long long a[51], b[51];
long long layer(long long x)
{
	if(!a[x])
	{
		a[x] = 1 + layer(x - 1) + 1 + layer(x - 1) + 1;
	}
	return a[x];
}
long long patty(long long x)
{
	if(!b[x])
	{
		b[x] = patty(x - 1) + 1 + patty(x - 1);
	}
	return b[x];
}
int main()
{
	a[0] = 1;
	b[0] = 1;
	long long n, x, total = 0;
	scanf("%lld%lld", &n, &x);
	for(long long i = 0, j = n; i < x && j >= 0; )
	{
		if(i + layer(j) <= x)
		{
			if(i + layer(j) + 1 <= x)
			{
				total += 1;
				++i;
			}
			total += patty(j);
			i += layer(j);
		}
		else
		{
			++i;
			--j;
		}
	}
	printf("%lld\n", total);
}