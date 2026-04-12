#pragma GCC optimize("Ofast")
#include<stdio.h>
#include<algorithm>
using namespace std;
long long num[200005],pre[200005],mod=1000000007;
int main(){
	long long i,n;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&num[i]);
	pre[0]=num[0];
	for(i=1;i<n;i++)
		pre[i]=(pre[i-1]+num[i])%mod;
	long long ans=0;
	for(i=0;i<n-1;i++){
		ans=((ans+num[i]*(pre[n-1]-pre[i]))%mod+mod)%mod;
	}
	printf("%lld\n",ans);
}
