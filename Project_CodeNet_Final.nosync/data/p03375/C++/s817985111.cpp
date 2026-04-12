#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3050;
ll n;
ll power(ll base,ll b,ll mod){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return ans;
}
ll s[N][N],c[N][N];
void second_stl(ll mod){
	s[0][0]=c[0][0]=1;
	for(int i=1;i<=n+1;++i){
		c[i][0]=1;
		for(int j=1;j<=i;++j)
			s[i][j]=s[i-1][j-1]+s[i-1][j]*j%mod,s[i][j]%=mod,c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
			//是否建立一个新集合 
	}
}
void solve(ll mod){
	ll ans=0;
	for(int i=0;i<=n;++i){
		ll sum=0,p1=power(2,power(2,n-i,mod-1),mod),p2=power(2,n-i,mod),p=1;	
		for(int j=0;j<=i;++j){
			ll tmp=s[i+1][j+1]*p1%mod*p%mod;
			sum=(sum+tmp)%mod;
			p=p*p2%mod;
		}
		if(i&1)ans=(ans-c[n][i]*sum%mod+mod)%mod;
		else ans=(ans+c[n][i]*sum%mod)%mod;
	}
	printf("%lld\n",(ans%mod+mod)%mod);
}
int main(){
//	freopen("s.in","r",stdin);
	ll mod;
	scanf("%lld%lld",&n,&mod);
	second_stl(mod); 
	solve(mod);
	return 0;
}