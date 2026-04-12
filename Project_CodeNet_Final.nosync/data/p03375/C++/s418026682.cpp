#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
const int maxn=3e3+5;
typedef long long ll;
inline ll fpm(ll a,ll p,ll mod){
	ll res=1;
	while(p){
		if (p&1) res=res*a%mod;
		a=a*a%mod;
		p/=2;
	}
	return res;
}
int n;
int mod;
ll s[maxn][maxn];
ll fac[maxn],inv[maxn];
inline void init(){
	s[0][0]=1;
	for (int i=1;i<=n+1;i++){
		for (int j=1;j<=i;j++){
			s[i][j]=(s[i-1][j-1]+1ll*j*s[i-1][j]%mod)%mod;
		}
	}
	fac[0]=inv[0]=1;
	for (int i=1;i<=n;i++){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=fpm(fac[i],mod-2,mod);
		//cout<<"print fac inv "<<fac[i]<<' '<<inv[i]<<endl;
	}
}
inline ll getc(ll n,ll m){
	if (n<m||n<0||m<0) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
inline ll f(int i){
	ll cur=1,a=fpm(2,n-i,mod);
	ll b=fpm(2,fpm(2,n-i,mod-1),mod);
	ll ans=0;
	for (int k=0;k<=i;k++){
		ans=(ans+s[i+1][k+1]*cur%mod*b%mod)%mod;
		cur=cur*a%mod;
	}
	return ans;
}
int main(){
	cin>>n>>mod;
	init();
	ll ans=0;
	for (int i=0;i<=n;i++){
		ll tp=getc(n,i)*f(i)%mod;
		//cout<<"print getc f "<<getc(n,i)<<' '<<f(i)<<endl;
		if (i%2==0) ans=(ans+tp)%mod;
		else ans=(ans+mod-tp)%mod;
	}
	cout<<ans<<endl;
}