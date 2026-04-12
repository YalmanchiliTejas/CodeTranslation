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
const ll mod=1e9+7 ;

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

ll comb(ll n,ll k){
    if(n<k||n<0||k<0)return 0;
    ll ret=1;
    rep(i,k){
        ret*=n%mod;
        ret%=mod;
        ret*=powmod(i+1,mod-2);
        ret%=mod;
        --n;
    }
    return ret;
}

void solve(ll n,ll d,ll x){
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    dp[0][0]=1;
    rep(i,n){
        rep(j,n){
            dp[i+1][j+1]+=dp[i][j];
            if(j+x<=n)dp[i+1][j+x]+=mod-dp[i][j];
        }
        rep(j,n){
            dp[i+1][j+1]+=dp[i+1][j];
            dp[i+1][j+1]%=mod;
        }
    }
    ll ans=0;
    rep(i,n+1){
        ans+=dp[i][n]*comb(d,i)%mod;
    }
    cout<<ans%mod<<endl;

}
int main(){
    ll n,d,x;
    while(cin>>n>>d>>x,n!=0)solve(n,d,x);
    return 0;
}
