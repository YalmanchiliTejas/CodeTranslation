#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll =  long long ;
using P = pair<int,int> ;
const ll INF = 1e18;
const int MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if(n%2 == 0){
        ll res1 = 0,res2 = 0;
        rep(i,n){
            if(i%2 ==0) res1 += a[i];
            else res2 += a[i];
        }
        ll ans =  max(res1,res2);
        vector<vector<ll>> dp2(n+1,vector<ll>(2,-INF));
        dp2[1][0] = a[0];
        for(int i=2;i<=n;i++){
            if(i-2>=1){
                if(dp2[i-2][0] != -INF)dp2[i][0] = dp2[i-2][0] + a[i-1];
                if(dp2[i-2][1] != -INF)dp2[i][1] = dp2[i-2][1] + a[i-1];
            }if(i-3 >=1){
                if(dp2[i-3][0] != -INF)dp2[i][1] = max(dp2[i][1],dp2[i-3][0] + a[i-1]);
            }
        }
        ans = max(ans,max(dp2[n][1],dp2[n-1][0]));
        cout << ans << endl;
        return 0;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(3,-INF));
    dp[1][0] = a[0];
    for(int i=2;i<=n;i++){
        if(i-2 >= 1){
            if(dp[i-2][0] != -INF)dp[i][0] = dp[i-2][0] + a[i-1];
            if(dp[i-2][1] != -INF)dp[i][1] = dp[i-2][1] + a[i-1];
            if(dp[i-2][2] != -INF)dp[i][2] = dp[i-2][2] + a[i-1];
        }if(i-3 >=1){
            if(dp[i-3][0] != -INF)dp[i][1] = max(dp[i][1],dp[i-3][0] + a[i-1]);
            if(dp[i-3][1] != -INF)dp[i][2] = max(dp[i][2],dp[i-3][1] + a[i-1]);
        }if(i-4 >=1){
            if(dp[i-4][0] != -INF)dp[i][2] = max(dp[i][2],dp[i-4][0] + a[i-1]);
        }
    }
    vector<vector<ll>> dp2(n+1,vector<ll>(2,-INF));
    dp2[2][0] = a[1];
    for(int i=3;i<=n;i++){
        if(i-2>=1){
            if(dp2[i-2][0] != -INF)dp2[i][0] = dp2[i-2][0] + a[i-1];
            if(dp2[i-2][1] != -INF)dp2[i][1] = dp2[i-2][1] + a[i-1];
        }if(i-3 >=1){
            if(dp2[i-3][0] != -INF)dp2[i][1] = max(dp2[i][1],dp2[i-3][0] + a[i-1]);
        }
    }
    ll ans = max({dp[n][2],dp[n-1][1],dp[n-2][0],dp2[n][1],dp2[n-1][0]});
    ll res1 = 0,res2 = 0;
    rep(i,n){
        if(i%2 ==1) res1 += a[i];
        if(i%2 ==0 && i != 0) res2 += a[i];
    }
    ans = max(ans,max(res1,res2));
    cout << ans << endl;
    return 0;
}