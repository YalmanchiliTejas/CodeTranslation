#include <stdio.h>
#define maxn 3010
#define mod 998244353
#define LL long long
LL a[maxn],f[maxn],ans;
int main(){
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++){
		for(j=m;j>=a[i];j--)f[j]=(f[j]+f[j-a[i]])%mod;
		f[a[i]]=(f[a[i]]+i)%mod;
		ans=(ans+f[m]*(n-i+1))%mod;
		f[m]=0;
	}
	printf("%lld\n",ans);
	return 0;
}