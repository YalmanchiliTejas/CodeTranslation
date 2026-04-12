#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
const int N=1e7+1,mod=998244353;
int n,ans,fac[N],inv[N],pw[N];
I Pow(ll t,rnt x){
	ll s=1;
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
V check(int&x){x-=mod,x+=x>>31&mod;}
I C(rnt x,rnt y){return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	cin>>n,fac[0]=inv[0]=pw[0]=1;
	FOR(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=Pow(fac[n],mod-2);
	ROF(i,n-1,1)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	FOR(i,1,n)check(pw[i]=pw[i-1]<<1);
	FOR(i,n/2+1,n)check(ans+=1ll*pw[n-i]*C(n,i)%mod);
	check(ans<<=1),check(ans=Pow(3,n)+mod-ans);
	cout<<ans;
	return 0;
}