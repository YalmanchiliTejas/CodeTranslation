#include <cstdio>
#include <algorithm>
#define maxn 200010
#define LL long long
using namespace std;
int a[maxn];
LL dp[maxn],sum[maxn];
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		if(i%2)sum[i]=sum[i-1]+a[i];
		else sum[i]=sum[i-1];
	for(i=2;i<=n;i++)
		if(i&1)dp[i]=max(dp[i-2]+a[i],dp[i-1]);//i是奇数,i/2==(i-1)/2
		else dp[i]=max(dp[i-2]+a[i],sum[i-1]);//i是偶数
	printf("%lld\n",dp[n]);
	return 0;
}