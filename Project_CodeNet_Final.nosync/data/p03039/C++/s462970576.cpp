#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

struct Combination{
    vector<ll> fac,finv,inv;
    Combination(int mx){
        fac.resize(mx+1);
        finv.resize(mx+1);
        inv.resize(mx+1);
        fac[0]=fac[1]=1;
        finv[0]=finv[1]=1;
        inv[1]=1;
        for(int i=2;i<=mx;i++){
            fac[i]=fac[i-1]*i%mod;
            inv[i]=mod-inv[mod%i]*(mod/i)%mod;
            finv[i]=finv[i-1]*inv[i]%mod;
        }
    }
    ll operator()(int n,int k){
        if(n<k)return 0;
        return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
    }
};

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    Combination comb(n*m-2);
    ll ans=n*m*(n*m-1)*(n+m)/6;
    ans%=mod;
    ans*=comb(m*n-2,k-2);
    ans%=mod;
    cout<<ans<<endl;
}
