#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i = (a);i <= (b);++i)
typedef long long ll;
const int maxn = 2e5+5;
const int mod = 1e9+7;
ll qpow(ll a,ll b){ll res = 1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll sum[maxn];
int a[maxn];
int main()
{

	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;++i){
		scanf("%d",&a[i]);
		sum[i] = sum[i-1]+a[i];
		sum[i]%=mod;
	}
	ll ans = 0;
	for(int i = 1;i <= n;++i){
		ans = ans+1ll*a[i]*(sum[n]-sum[i]+mod)%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}