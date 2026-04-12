#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

const int MAX_N=200002;
const int mod=1000000007;
ll fact[MAX_N+1];
ll inv[MAX_N+1],finv[MAX_N+1];

int inv_init(ll n,ll p){
    inv[1]=1;
    FOR(i,2,n+1) inv[i]=p-(p/i)*inv[p%i]%p;
    fact[0]=finv[0]=1;
    FOR(i,1,n+1){
        fact[i]=fact[i-1]*i%p;
        finv[i]=finv[i-1]*inv[i]%p;
    }
    return 0;
}
ll comb_mod(ll n,ll k,ll p){
    if(k<0||n<k) return 0;
    return finv[k]*finv[n-k]%p*fact[n]%p;
}
int n,m,k;
ll sum=0;
int main(){
    cin>>n>>m>>k;
    inv_init(n*m,mod);
    rep(i,n){
        sum+=(ll)i*(n-i)*m*m;
        sum%=mod;
    }
    rep(i,m){
        sum+=(ll)i*(m-i)*n*n;
        sum%=mod;
    }
    sum*=comb_mod(n*m-2,k-2,mod);
    cout<<sum%mod<<endl;
    return 0;
}
