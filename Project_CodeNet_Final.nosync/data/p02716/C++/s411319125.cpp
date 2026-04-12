#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e16;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<vector<vector<long long int>>> dp(n+1, vector<vector<long long int>>(3, vector<long long int>(2, -INF)));
    // dp[i][j][k] = max sum up to i-th element, "xx" apeared j times, last choice o(0) or x(1)
    dp[0][0][1] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            // xo
            if(dp[i][j][1] != -INF) dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][1] + a[i]);
            // ox
            dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][0]);

            // basically above two transition, but some exceptions are
            // xx
            if(j+1 < 3) dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][1]);
            // oo : impossible
        }
    }

    long long int ans = -INF;
    if(n % 2 == 0){
        ans = max(ans, dp[n][1][0]);
        ans = max(ans, dp[n][0][1]);
        ans = max(ans, dp[n][1][1]);
    }
    if(n % 2 == 1){
        ans = max(ans, dp[n][2][0]);
        ans = max(ans, dp[n][1][1]);
    }
    cout << ans << endl;
    return 0;
}