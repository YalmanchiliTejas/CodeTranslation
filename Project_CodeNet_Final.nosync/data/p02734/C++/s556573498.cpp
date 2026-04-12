#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, S;
    ll mod = 998244353;
    cin >> N >> S;
    vector<vector<ll>> dp(N, vector<ll>(S+1, 0));
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    // first
    if(a[0]<=S) dp[0][a[0]] += 1;
    ll total = dp[0][S];
    for(int i=1;i<N;i++){
        if(a[i]<=S) dp[i][a[i]] += i + 1;
        for(int j=1;j<S+1;j++){
            // dp[i][j] += dp[i-1][j];
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= mod;
            if(dp[i-1][j] != 0 && j+a[i]<=S){
                dp[i][j+a[i]] += dp[i-1][j];
                dp[i][j+a[i]] %= mod;
            }
        }
        total += dp[i][S];
        total %= mod;
    }
    cout << total%mod << endl;
    return 0;
}
