#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	ll n,s=0,ans=0;
	ll MOD =1e9+7;
	scanf("%lld",&n);
	ll a[n];
	for(auto& k:a){
		scanf("%lld",&k);
		s+=k;
	}
	for(int i=0;i<n-1;i++){
		s-=a[i];
		ans+=((s)%MOD*(a[i])%MOD)%MOD;
		ans%=MOD;
	}
	ans%=MOD;
	printf("%lld",ans);
	return 0;
}
