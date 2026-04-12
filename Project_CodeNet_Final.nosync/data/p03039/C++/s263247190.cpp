#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;

ll mod=1e9+7;

//繰り返し二乗法
ll power(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

struct perm{
private:
    int sz;
    vector<ll> p,invp;
public:
    perm(int n){
        sz=n+1;
        p.resize(sz),invp.resize(sz);
        p[0]=1;
        for(int i=1;i<=sz-1;i++){
            p[i]=p[i-1]*i%mod;
        }
        invp[sz-1]=power(p[sz-1],mod-2);
        for(int i=sz-2;i>=0;i--){
            invp[i]=invp[i+1]*(i+1)%mod;
        }
    }
    ll comb(ll x,ll y){
        if(x<y||y<0)return 0;
        return (p[x]*invp[x-y]%mod)*invp[y]%mod;
    }
};
perm p(1<<20);

int main(){
    ll n,m,k; cin >> n >> m >> k;
    ll ans=0;
    for(int i=1;i<=n-1;i++){
        ll cnt=m*m%mod*(n-i)%mod;
        ll add=cnt*i%mod*p.comb(n*m-2,k-2)%mod;
        (ans+=add)%=mod;
    }
    swap(n,m);
    for(int i=1;i<=n-1;i++){
        ll cnt=m*m%mod*(n-i)%mod;
        ll add=cnt*i%mod*p.comb(n*m-2,k-2)%mod;
        (ans+=add)%=mod;
    }
    cout << ans << endl;
}