#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N];
ll sum[N];
const ll mod=1e9+7;
int main(){
	ll n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=n;i>=1;i--){
		sum[i]=(sum[i+1]+a[i])%mod;
	}
	ll ans=0;
	for(int i=1;i<=n-1;i++){
		ans=(ans+a[i]*sum[i+1]%mod)%mod;
	}
	printf("%lld",ans);
	return 0;
}