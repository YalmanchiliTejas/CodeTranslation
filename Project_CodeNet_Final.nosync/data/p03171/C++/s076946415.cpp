#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int N=3e3+5;
ll a[N],dp[N][N];
int main()
{
	int n,i,j,L,R;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(L=n;L>=1;L--)
	{
		for(R=L;R<=n;R++)
		{
			dp[L][R]=max(a[L]-dp[L+1][R],a[R]-dp[L][R-1]);
		}
	}
	printf("%lld\n",dp[1][n]);
	return 0;
}