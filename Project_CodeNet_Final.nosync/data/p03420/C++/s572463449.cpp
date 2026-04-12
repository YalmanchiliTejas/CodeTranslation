#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int lli;

int main(void)
{
	lli n, k, res = 0;
	scanf("%lld%lld", &n, &k);
	for(lli i = k+1;i <= n;i++)
	{
		for(lli j = i;;j += i)
		{
			if(k+j-i > n) break;
			pair<lli, lli> rng = {max(1ll, k+j-i), min(n, j-1)};
			res += rng.second-rng.first+1;
			if(j > n) break;
		}
	}
	printf("%lld\n", res);
}