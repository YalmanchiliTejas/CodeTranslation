#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=b-1;i>=a;i--)
const ll maxk=1e4+5, maxd=1e2+5, mod=1e9+7;
ll d,k,dp[maxk][maxd][2];
string s;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>s>>d;
    k=s.size();
    dp[k][0][0]=dp[k][0][1]=1;
    per(i,0,k) rep(j,0,d) { 
        rep(h,0,10) dp[i][(j+h)%d][1]+=dp[i+1][j][1];
        rep(h,0,s[i]-'0') dp[i][(j+h)%d][0]+=dp[i+1][j][1];
        dp[i][(j+s[i]-'0')%d][0]+=dp[i+1][j][0];
        dp[i][j][0]%=mod; dp[i][j][1]%=mod;
    }
    ll ans=(dp[0][0][0]-1+mod)%mod;
    cout<<ans<<"\n";
}
