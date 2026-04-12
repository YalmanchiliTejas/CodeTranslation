#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

class comb{
private:
    ll mod;
    ll mx;
    vector<ll> F;
    vector<ll> FR;
    
public:
    comb(ll mod=1000000007,ll mx=100000):mod(mod),mx(mx),F(mx+1,1),FR(mx+1,1){
        mk_F();
    }
    
    ll mod_pow(ll a,ll x){
        a%=mod;
        ll ans=1;
        while(x>0){
            if(x&1){ans*=a; ans%=mod;}
            a*=a;
            a%=mod;
            x>>=1;
        }
        return ans;
    }
    
    pll Ex_gcd(ll a,ll b){
        if(b==0){return {1,0};}
        pll ret=Ex_gcd(b,a%b);
        ret.F-=a/b*ret.S;
        return {ret.S,ret.F};
    }
    
    ll prime_R(ll a){
        return mod_pow(a,mod-2);
    }
    
    ll R(ll a){
        ll ret=Ex_gcd(a,mod).F;
        ret%=mod;
        if(ret<0){ret+=mod;}
        return ret;
    }
    
    void mk_F(){
        for(ll i=1;i<=mx;i++){F[i]=F[i-1]*i%mod; FR[i]=R(F[i]);}
    }
    
    ll c(ll n,ll k){
        if(n<k || n<0 || k<0){return 0;}
        if(n==k || k==0){return 1;}
        return F[n]*FR[n-k]%mod*FR[k]%mod;
    }
    
    //mod must be prime
    ll Lucas_C(ll n,ll m){
        ll ret=1;
        while(n>0 || m>0){
            ret*=c(n%mod,m%mod);
            ret%=mod;
            n/=mod; m/=mod;
        }
        return ret;
    }
    
    ll Stirling(ll n,ll k){
        ll ret=0;
        for(ll i=1;i<=k;i++){
            if((k-i)%2){ret-=c(k,i)*mod_pow(i,n)%mod;}
            else{ret+=c(k,i)*mod_pow(i,n)%mod;}
            ret%=mod;
        }
        ret*=R(F[k]);
        ret%=mod;
        if(ret<0){ret+=mod;}
        return ret;
    }
    
    ll Bell(ll n,ll k){
        ll ret=0;
        for(ll i=1;i<=k;i++){ret+=Stirling(n,i); ret%=mod;}
        return ret;
    }
};

comb C(MOD,1000000);

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans=0;
    ll cnt=0;
    for(ll i=0;i<k;i++){
        cnt+=i*C.c(n,i)%MOD*C.c(m*n-n-1,k-1-i)%MOD;
        cnt%=MOD;
    }
    for(ll i=0;i<m;i++){
        ans+=n*cnt%MOD*((i*(i+1)/2+(m-i)*(m-i-1)/2)%MOD)%MOD;
        ans%=MOD;
    }
    cnt=0;
    for(ll i=0;i<k;i++){
        cnt+=i*C.c(m,i)%MOD*C.c(m*n-m-1,k-1-i)%MOD;
        cnt%=MOD;
    }
    for(ll i=0;i<n;i++){
        ans+=m*cnt%MOD*((i*(i+1)/2+(n-i)*(n-i-1)/2)%MOD)%MOD;
        ans%=MOD;
    }
    const ll inv=(MOD+1)/2;
    ans*=inv;
    ans%=MOD;
    if(ans<0){ans+=MOD;}
    cout<<ans<<endl;
    
    
    return 0;
}
