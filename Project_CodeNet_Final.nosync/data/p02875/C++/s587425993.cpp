#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
ll N;
const ll MOD=998244353,MAX_N=1e7;
ll fact[MAX_N+1],ifact[MAX_N+1];
ll cmb(ll n,ll m){
	return fact[n]*ifact[m]%MOD*ifact[n-m]%MOD;
}
ll mpw(ll n,ll m){
	ll r=1;
	while(m){
		if(m&1){
			r*=n;
			r%=MOD;
		}
		n*=n;
		n%=MOD;
		m>>=1;
	}
	return r;
}
ll minv(ll n){
	return mpw(n,MOD-2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	fact[0]=1;
	REP(i,N){
		fact[i+1]=fact[i]*(i+1)%MOD;
	}
	ifact[N]=minv(fact[N]);
	for(ll i=N-1;i>=0;i--){
		ifact[i]=ifact[i+1]*(i+1)%MOD;
	}
	ll ans=0,pw2=1;
	for(ll k=N;k>N/2;k--){
		ans+=cmb(N,k)*pw2%MOD;
		pw2*=2;
		pw2%=MOD;
	}
	ans*=2;
	ans%=MOD;
	ans=MOD-ans;
	ans%=MOD;
	ans+=mpw(3,N);
	ans%=MOD;
	cout<<ans<<endl;
}
