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
    vector<map<ll,ll>> dp(n+1);
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        if(i==1){
            dp[i][0] = 0;
            dp[i][1] = a[0];
            continue;
        }
        dp[i][(i-1)/2] = dp[i][(i+1)/2] = -INF;
        if(i-1>=0){
            if(dp[i-1].find((i-1)/2) == dp[i-1].end()) dp[i-1][(i-1)/2] = -INF;
            if(dp[i-1].find((i+1)/2) == dp[i-1].end()) dp[i-1][(i+1)/2] = -INF;
            dp[i][(i-1)/2] = max(dp[i][(i-1)/2],dp[i-1][(i-1)/2]);
            dp[i][(i+1)/2] = max(dp[i][(i+1)/2],dp[i-1][(i+1)/2]);
        }if(i-2>=0){
            if(dp[i-2].find(((i-1)/2 - 1)) == dp[i-2].end()) dp[i-2][((i-1)/2 - 1)] = -INF;
            if(dp[i-2].find(((i+1)/2 - 1)) == dp[i-2].end()) dp[i-2][((i+1)/2 - 1)] = -INF;
            dp[i][(i-1)/2] = max(dp[i][(i-1)/2],dp[i-2][-1 + (i-1)/2] + a[i-1]);
            dp[i][(i+1)/2] = max(dp[i][(i+1)/2],dp[i-2][-1 + (i+1)/2] + a[i-1]);
        }
    }
    cout << dp[n][n/2] << endl;
    return 0;
}