#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N],dp[N],sum[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=(i>2?sum[i-2]:0)+a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(i&1) dp[i]=max(dp[i-1],dp[i-2]+a[i]);
		else dp[i]=max(sum[i-1],dp[i-2]+a[i]);
	}
	printf("%lld\n",dp[n]);
	return 0;
}