#include <bits/stdc++.h>
using namespace std;

long long n, a[200001];
long long dp[200001][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    memset(dp, 0, sizeof(dp));
    dp[2][0] = a[0];
    dp[2][1] = a[1];

    for (int i = 3; i <= n; i++){
        if (i % 2 == 1){
            dp[i][1] = a[i - 1] + max(max(dp[i - 2][1], dp[i - 2][0]), max(dp[i - 3][1], dp[i - 3][0]));
            dp[i][0] = dp[i - 1][1];
        }
        else {
            dp[i][1] = a[i - 1] + max(max(dp[i - 2][1], dp[i - 2][0]), dp[i - 1][0]);
            dp[i][0] = a[i - 2] + dp[i - 2][0]; // 
        }
    }

    cout << max(dp[n][1], dp[n][0]) <<"\n";
    return 0;
}