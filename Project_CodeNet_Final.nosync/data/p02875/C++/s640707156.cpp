#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353;

vector<ll> inv,fact,invfact;
void mod_build(int n=101010){
    fact.resize(n+1);
    inv.resize(n+1);
    invfact.resize(n+1);
    fact[0]=inv[0]=invfact[0]=1;
    inv[1]=1;
    rep(i,n){
        fact[i+1]=fact[i]*(i+1)%mod;
        if(i>0)inv[i+1]=mod-inv[mod%(i+1)]*(mod/(i+1))%mod;
        invfact[i+1]=invfact[i]*inv[i+1]%mod;
    }
}
ll perm(int n,int k){
    if(n<0||k<0||k>n)return 0;
    return fact[n]*invfact[n-k]%mod;
}
ll comb(int n,int k){
    if(n<0||k<0||k>n)return 0;
    return (fact[n]*invfact[n-k]%mod)*invfact[k]%mod;
}
ll powmod(ll n,ll k){
    k%=mod-1;
    if(k<0)k+=mod-1;
    ll ret=1;
    while(k){
        if(k&1)ret=ret*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return ret;
}
int main(){
    mod_build(12345678);
    int n;
    cin>>n;
    ll ans = powmod(3,n);
    vector<ll> sum(n/2+1);
    ll p = powmod(2,n/2);
    rep(i,n/2+1){
        sum[i]=comb(n/2,i)*p%mod;
        p*=inv[2];
        p%=mod;
    }
    rep(i,n/2){
        sum[n/2-i-1]+=sum[n/2-i];
        sum[n/2-i]%=mod;
    }
    ll res = 0;
    p = powmod(2,n/2);
    rep(i,n/2+1){
        if(i==0)continue;
        res+=comb(n/2,i)*p%mod*sum[n/2+1-i]%mod;
        p*=inv[2];
        p%=mod;
    }
    cout<<(ans-res%mod+mod)%mod<<endl;
    return 0;
}