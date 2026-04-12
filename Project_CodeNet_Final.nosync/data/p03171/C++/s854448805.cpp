#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 3005
#define INF 0x3f3f3f3f
#define p 1000000007
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, a[MAXN];
LL f[MAXN][MAXN];

LL solve(int l, int r, int op)
{
	if(f[l][r]!=-1) return f[l][r];
	LL temp=0;
	if(l==r) return f[l][l]=(op==1?a[l]:-a[l]);
	if(op==1)
	{
		temp=max(a[l]+solve(l+1, r, 1-op), a[r]+solve(l, r-1, 1-op));
		return f[l][r]=temp;
	}
	else
	{
		temp=min(solve(l+1, r, 1-op)-a[l], solve(l, r-1, 1-op)-a[r]);
		return f[l][r]=temp;
	}
}

int main()
{
	memset(f, -1, sizeof(f));
	scanf("%d", &n);
	for(rint i=1; i<=n; ++i) scanf("%d", &a[i]);
	printf("%lld\n", solve(1, n, 1));
	return 0;
}