#include <stdio.h>
#define maxn 200010
#define LL long long
#define mod 1000000007
LL a[maxn],sum,ans;//防int溢出，long long最方便。
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=2;i<=n;i++)sum=(sum+a[i])%mod;
	for(i=1;i<n;i++)ans=(ans+a[i]*sum)%mod,sum=((sum-a[i+1])%mod+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}
