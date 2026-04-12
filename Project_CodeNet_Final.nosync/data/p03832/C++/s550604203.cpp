#include <bits/stdc++.h>
#define rep(i,s,t) for (int i=s;i<=t;++i)
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
using namespace std;
ll fac[maxn],inv[maxn];
ll quick_mod(ll x,ll y){
    ll ans=1;
    for(;y;y>>=1){
        if (y&1) ans=ans*x%mod;
        x=x*x%mod;
    }
    return ans;
}
void init(){
    fac[0]=1;
    rep(i,1,maxn-10) fac[i]=fac[i-1]*i%mod;
    inv[maxn-10]=quick_mod(fac[maxn-10],mod-2);
    for(int i=maxn-11;i>=0;--i) inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(int n,int m){
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll invv[maxn];
ll dp[1010][1010];
int main()
{
    init();
    int n,a,b,c,d;
    cin>> n >> a >> b >> c >> d;
    rep(i,0,b+1) dp[i][0]=1;
    rep(i,1,n) invv[i]=quick_mod(i,mod-2);
    rep(i,a,b){
        rep(j,0,n){
            if (!dp[i][j]) continue;
            if (j) (dp[i+1][j]+=dp[i][j])%=mod;
            ll tmp=1;
            rep(k,1,d){
                if (j+k*i>n) break;
                (tmp*=C(n-j-i*(k-1),i)*invv[k]%mod)%=mod;
                if (c<=k&&k<=d){
                    (dp[i+1][j+k*i]+=(dp[i][j]*tmp)%mod)%=mod;
                }
            }
        }
    }
    cout<< dp[b+1][n] <<endl;
    return 0;
}