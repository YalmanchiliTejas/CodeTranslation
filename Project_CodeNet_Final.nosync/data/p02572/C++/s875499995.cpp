#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=200010;
const int mod=1e9+7;
#define int long long
int n,a[maxn],sum=0;

signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
		sum%=mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		( ans+=a[i]*( ((sum=sum-a[i])+mod)%mod ) )%=mod,(sum+=mod)%=mod;
	printf("%lld\n",ans%mod);
}
