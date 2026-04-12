#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 998244353;

ll dp[3005][3005];

int main(){
    int n,s;
    ll ans = 0;
    cin >> n >> s;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n+1){
        dp[i][0] = i+1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(j-a[i-1]>=0) dp[i][j] = (dp[i-1][j] + dp[i-1][j-a[i-1]])%MOD;
            else dp[i][j] = dp[i-1][j];
        }
        ans += dp[i][s];
        ans %= MOD;
    }
    cout << ans << endl;
    /*
    rep(i,n+1){
        rep(j,s+1){
            cout << dp[i][j] << " ";
        }
         cout << endl;
    }
    */
    return 0;
}