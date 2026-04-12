#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 1234567890




vector<ll> inv,fact,invfact;
void Mod_build(int n=201010){
	fact.resize(n+1);
	inv.resize(n+1);
	invfact.resize(n+1);
	fact[0]=inv[0]=invfact[0]=1;
	inv[1]=1;
	for(ll i=0;i<n;i++){
		fact[i+1]=fact[i]*(i+1)%Mod;
		if(i>0)inv[i+1]=Mod-inv[Mod%(i+1)]*(Mod/(i+1))%Mod;
		invfact[i+1]=invfact[i]*inv[i+1]%Mod;
	}
}
ll perm(int n,int k){
	if(n<0||k<0||k>n)return 0;
	return fact[n]*invfact[n-k]%Mod;
}
ll comb(int n,int k){
	if(n<0||k<0||k>n)return 0;
	return (fact[n]*invfact[n-k]%Mod)*invfact[k]%Mod;
}
ll powMod(ll n,ll k){
	k%=Mod-1;
	if(k<0)k+=Mod-1;
	ll ret=1;
	while(k){
		if(k&1)ret=ret*n%Mod;
		n=n*n%Mod;
		k>>=1;
	}
	return ret;
}



int main(){
    ll i,j;
    Mod_build();

    ll n,m,k;
    cin>>n>>m>>k;

    ll ans1=(n-1)*n*(n+1)/6;
    ans1%=Mod;
    ans1*=(m*m);
    ans1%=Mod;

    ll ans2=(m-1)*m*(m+1)/6;
    ans2%=Mod;
    ans2*=(n*n);
    ans2%=Mod;

    ll ans=(ans1+ans2)%Mod;
    
    ans*=comb(n*m-2,k-2);
    ans%=Mod;
    cout<<ans<<endl;
    
    return 0;
}