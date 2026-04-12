#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=(a); i<(b); i++)
const ll maxn=3e3+5, mod=998244353;
ll n,s,a[maxn],dp[maxn][maxn];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    rep(i,1,n+1) cin>>a[i];
    dp[0][0]=1;
    rep(i,1,n+1) {
        dp[i][0]=i+1;
        rep(j,1,s+1) {
            if(j<s) dp[i][j]=dp[i-1][j];
            if(a[i]<=j) dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
        }
    }
    ll ans=0;
    rep(i,1,n+1) ans=(ans+dp[i][s]*(n-i+1))%mod;
    cout<<ans<<"\n";
}
