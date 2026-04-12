#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

long long bfac[100003];
long long pref[100003];
void precompute()
{
	for(int i = 1; i <= 100000; i++)
	{
		for(int j = 1; j <= sqrt(i); j++)
		{
			if(i%j == 0)
			{
				bfac[i]+=2;
				bfac[i]-=(long long)(j*j == i);
			}
		}
	}
	for(int i = 1; i <= 100000; i++)
		pref[i] = pref[i-1]+bfac[i];
}

int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.in", "r", stdin);
	long long n, k; scanf("%lld %lld", &n, &k);
	if(k == 0)
	{
		printf("%lld\n", n*n);
		return 0;
	}
	long long res = 0;
	for(long long i = k+1; i <= n; i++)
	{
		long long cyc = (n)/i;
		res += (cyc)*(i-k);
		res += max(0LL,(n%i)-(k-1));
	//	printf("i : %lld cyc : %lld res %lld\n", i, cyc, res);
	}
	printf("%lld\n", res);
}



