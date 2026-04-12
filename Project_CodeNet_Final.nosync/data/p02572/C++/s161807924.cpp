#include<cstdio>
using namespace std;
const int mod=1e9+7;
const int N=2e5+5;
int n;
long long a[N],sum,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		sum=(sum+a[i])%mod;
	}
	for (int i=1;i<n;i++){
		sum=(sum+mod-a[i]%mod)%mod;
		ans=(ans+a[i]*sum%mod)%mod;
	}
	printf("%lld",ans);
	return 0;
}