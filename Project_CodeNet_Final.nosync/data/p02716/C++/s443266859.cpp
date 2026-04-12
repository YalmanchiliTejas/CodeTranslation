#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    vector<vector<ll>> dp(n+1, vector<ll>(3, -1e+18)); // dp[n個目まで][いくつ飛ばしたか];
    int base = (n%2==0?1:2);
    int lim = 2;
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        // 通常移動
        dp[i][0] = (i >= 2?dp[i-2][0]:0);
        dp[i][0] += a[i];
        // 一回だけ飛ばした奴
        if(i >= 1){
            dp[i][1] = (i >= 2?dp[i-2][1]:0);
            dp[i][1] += a[i];
        }
        // ニ回飛ばした奴
        if(i >= 2){
            dp[i][2] = (i >= 2?dp[i-2][2]:0);
            dp[i][2] += a[i];
        }


        // 一つ飛ばす
        if(i >= 1){
            dp[i][1] = max(dp[i][1], (i >= 3?dp[i-3][0]:0)+a[i]);
        }
        if(i >= 2){
            dp[i][2] = max(dp[i][2], (i >= 3?dp[i-3][1]:0)+a[i]);
        }

        // 二つ飛ばす
        if(i >= 2){
           dp[i][2] = max(dp[i][2], (i >= 4?dp[i-4][0]:0)+a[i]);
        }
    }
    ll ans = -1e+18;
    for(int j=0;j<=base;j++){
        ans = max(ans, dp[n-1-(base-j)][j]);
    }
    cout << ans << endl;
}