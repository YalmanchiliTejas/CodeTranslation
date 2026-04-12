#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
using namespace std;
const ll MAX_NM=2e5,MOD=1e9+7;
ll N,M,K,fact[MAX_NM+1],ifact[MAX_NM+1];
ll f(ll x){
	return (x*(x+1)*(2*x+1)/6-x*(x+1)/2*(2*x+1)+x*x*(x+1))%MOD;
}
ll mpw(ll n,ll m){
	ll ret=1;
	while(m){
		if(m&1){
			ret*=n;
			ret%=MOD;
		}
		n*=n;
		n%=MOD;
		m>>=1;
	}
	return ret;
}
ll minv(ll n){
	return mpw(n,MOD-2);
}
ll comb(ll n,ll m){
	return fact[n]*ifact[m]%MOD*ifact[n-m]%MOD;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>M>>K;
	fact[0]=1;
	REP(i,N*M){
		fact[i+1]=fact[i]*(i+1)%MOD;
	}
	ifact[N*M]=minv(fact[N*M]);
	for(ll i=N*M-1;i>=0;i--){
		ifact[i]=ifact[i+1]*(i+1)%MOD;
	}
	cout<<comb(N*M-2,K-2)*((M*M%MOD*f(N)%MOD+N*N%MOD*f(M)%MOD)%MOD)%MOD*minv(2)%MOD<<endl;
}