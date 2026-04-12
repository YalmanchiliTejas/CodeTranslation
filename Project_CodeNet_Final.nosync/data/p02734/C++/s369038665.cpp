#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(s,i, n) for (int i = (int)s; i < (int)(n); i++)
#define pb push_back
typedef long long ll;
  
int main(){
    ll mod=998244353;
    ll n,s;
    cin>>n>>s;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    

    ll dp[3030][3030][3];
    dp[0][0][0]=1;
    rep(i,n){
        rep(j,s+1){
            (dp[i+1][j][0]+=dp[i][j][0])%=mod;
            (dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
            (dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= mod;
            if(j + a[i] <= s){
                (dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
                (dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1]) %= mod;
            }
        }
    }
    cout<<dp[n][s][2]<<endl;

    
    return 0;
}