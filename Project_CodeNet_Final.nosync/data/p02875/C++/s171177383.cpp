// FUCKED UP FUCKED UP FUCKED UP FUCKED UP FUCKED UP
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define MP make_pair

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=1e7+10, maxm=5e4+10, lg=21, mod=998244353, inf=1e18;

ll pwm(ll a,ll b){ll ret=1;for(;b;b>>=1,(a*=a)%=mod)if(b&1)(ret*=a)%=mod;return ret;}
ll fac[maxn],inv[maxn];
ll C(ll n,ll r){return fac[n]*inv[r]%mod*inv[n-r]%mod;}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	fac[0]=inv[0]=1; for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod, inv[i]=pwm(fac[i],mod-2);
	ll n,c=0; cin>>n;
	for(int i=n/2+1;i<=n;i++) (c+=C(n,i)*pwm(2,n-i)%mod)%=mod;
	cout<<(pwm(3,n)-2*c%mod+mod)%mod;
	
	return 0;
}



 
