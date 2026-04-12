typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(3,vector<ll>(2,-1e15)));
    
    dp[0][1][0] = 0;
    
    for (int i = 0; i < n; i++) {
        if(i%2==1){
            dp[i+1][1][1] = dp[i][1][0]+a[i];
            dp[i+1][1][0] = dp[i][2][1];
            dp[i+1][0][0] = max(dp[i][1][1],dp[i][1][0]);
        }else{
            dp[i+1][2][1] = dp[i][1][0]+a[i];
            dp[i+1][1][1] = dp[i][0][0]+a[i];
            dp[i+1][1][0] = max(dp[i][1][0],dp[i][1][1]);
        }
    }
    std::cout << max(dp[n][1][1],dp[n][1][0]) << std::endl;
}
