#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;

LL n, x, f[55], g[55];

LL solve(LL l, LL r, LL x)
{
	if(r-l+1>=f[x]) return g[x];
	LL temp=0;
	if(r) r--;
	if(x && r) temp+=solve(1, r, x-1);
	if(x && r>=f[x-1])
	{
		r-=f[x-1];
		if(r) r--, temp++;
		if(r) temp+=solve(1, r, x-1);
	}
	return temp;
}

int main()
{
	f[0]=g[0]=1;
	for(int i=1; i<=50; i++)
	{
		f[i]=f[i-1]*2+3;
		g[i]=g[i-1]*2+1;
	}
	scanf("%lld%lld", &n, &x);
	printf("%lld\n", solve(1, x, n));
	return 0;
}