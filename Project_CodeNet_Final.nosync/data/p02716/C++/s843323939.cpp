#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(n) cout << n << endl
const ll INF = 1e18;

int main(){
    ll N;
    cin >> N;

    vector<ll> a(N);
    rep(n,N) cin >> a[n];
    
    vector<vector<ll>> dp(2,vector<ll>(3, -INF));
    dp[0][0] = 0; dp[1][0] = 0;
    bool n;
    ll temp;
    const bool even = N & 1;
    rep(i,N){
        n = i&1;
        if(even && i >= 6 && !n){
            if(i == 6) dp[0][2] = a[0] + a[3] + a[6];
            else dp[0][2] = max(dp[0][2], temp) + a[i];
        }
        if(i >= 2){
            if(i <= 3) dp[n][1] = a[i] + n * a[0];
            else{
                if(n) temp = dp[n][1];
                dp[n][1] = max(dp[n][1], dp[1-n][0] - a[i-1]) + a[i];
            }
        }
        dp[n][0] += a[i];
    }
    if(even) dp[0][0] -= a[N-1];

    ll ans;
    if(N<=3) ans = max({dp[0][0],dp[0][1],dp[1][0]});
    else ans = max({dp[1-even][0],dp[1-even][1],dp[1-even][2]});
    
    print(ans);
    return 0;
}