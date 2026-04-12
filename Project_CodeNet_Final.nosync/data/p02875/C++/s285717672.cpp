
//TJ
#include<bits/stdc++.h>
using namespace std;

const int N=1e7+10;
typedef long long ll;
ll n,fac[N],invf[N],mi2[N],ans;//fac 阶乘，invf 阶乘得逆元 
const ll mod=998244353;

ll qpow(ll a,ll b) {
	ll ans=1ll;
	while(b) {
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return ans;
}

ll C(int x,int y) {
	return fac[x]*invf[y]%mod*invf[x-y]%mod;
}

int main() {
	scanf("%d",&n);
	fac[0]=mi2[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=1ll*fac[i-1]*i%mod,mi2[i]=mi2[i-1]*2%mod;//fac阶乘，ci 2^2; 
	invf[n]=qpow(fac[n],mod-2);
	for(int i=n-1; i>=0; i--)
		invf[i]=1ll*invf[i+1]*(i+1)%mod;
	for(int i=n/2+1; i<=n; i++)
		ans=(ans+C(n,i)*mi2[n-i]%mod)%mod;
	ans=((qpow(3,n)-ans*2)%mod+mod)%mod;
	printf("%lld\n",ans);
}
