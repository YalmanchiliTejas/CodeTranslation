#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class ModComb{
public:
    static const ll MOD=1e9+7;
    static const int MAXN=2e5+10;
    ll factor[MAXN];
    ModComb(){
        factor[0]=1;
        for(ll i=1;i<MAXN;i++)factor[i]=i*factor[i-1]%MOD;
    }
    ll egcd(ll a,ll b,ll &x,ll &y){
        if(a==0){
            x=0;
            y=1;
            return b;
        }
        ll x1,y1;
        ll d=egcd(b%a,a,x1,y1);
        x=y1-(b/a)*x1;
        y=x1;
        return d;
    }
    ll modInv(ll k){
        ll g,x,y;
        g=egcd(k,MOD,x,y);
        if(g!=1)return -1;
        return (x%MOD+MOD)%MOD;
    }
    ll comb(ll n,ll m){
        if(n<m)swap(n,m);
        ll rt=factor[n]*modInv(factor[m])%MOD;
        rt=rt*modInv(factor[n-m])%MOD;
        return rt;
    }
};
class Solver{
public:
    static const ll MOD=1e9+7;
    static const int MAXN=2e5+10;
    ll N,M,K;
    ModComb *comb;
    Solver(){
        comb=new ModComb();
    }
    void solve(){
        ios::sync_with_stdio(false);
        cin>>N>>M>>K;
        ll ans=0;
        ll cnt=comb->comb(N*M-2,K-2);
        for(ll d=1;d<=N-1;d++){
            ll tmp=d*M*M%MOD*(N-d)%MOD;
            ans=(ans+tmp*cnt%MOD)%MOD;
        }
        for(ll d=1;d<=M-1;d++){
            ll tmp=d*N*N%MOD*(M-d)%MOD;
            ans=(ans+tmp*cnt%MOD)%MOD;
        }
        cout<<ans;
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();
}