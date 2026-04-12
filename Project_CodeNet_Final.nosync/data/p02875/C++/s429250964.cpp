#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll mod=998244353;

ll mod_pow(ll a,ll b){
    a%=mod;
    if(b==0)return 1;
    if(b==1)return a;
    ll res=mod_pow(a,b/2)%mod;
    res*=res; res%=mod;
    if(b%2)res*=a;
    return res%mod;
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
        invp[sz-1]=mod_pow(p[sz-1],mod-2);
        for(int i=sz-2;i>=0;i--){
            invp[i]=invp[i+1]*(i+1)%mod;
        }
    }
    ll comb(ll x,ll y){
        if(x<y||y<0)return 0;
        return (p[x]*invp[x-y]%mod)*invp[y]%mod;
    }
};
perm p(1<<24);
 
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    ll ans=mod_pow(3,n);
    vector<ll> p2(n+1,1);
    for(int i=0;i<n;i++){
        p2[i+1]=p2[i]*2%mod;
    }
    for(int i=n/2+1;i<=n;i++){
        ans-=p.comb(n,i)*p2[n-i]*2;
        ans+=mod;
        ans%=mod;
    }
    cout << ans << endl;
}