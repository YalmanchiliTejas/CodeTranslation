#include<cstdio>
long long n,m,k;
signed main()
{
	return scanf("%lld%lld%lld",&n,&m,&k),m>=n?puts("1"):(k>=m?puts("-1"):printf("%lld\n",((n-m)/(m-k)+((n-m)%(m-k)>=1))<<1|1)),0;
}