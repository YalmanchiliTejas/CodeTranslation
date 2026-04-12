#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int M=3005;
const LL NINF=0x8080808080808080;
int a[M];

LL dp[M][M];
LL getdp(int l,int r)
{
	if(l==r) return a[l];
	LL &ans=dp[l][r];
	if(ans!=NINF) return ans;
	ans=max(a[l]-getdp(l+1,r),a[r]-getdp(l,r-1));
	return ans;
}

int main()
{
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(dp,0x80,sizeof(dp));
	printf("%lld\n",getdp(1,n));
	return 0;
}