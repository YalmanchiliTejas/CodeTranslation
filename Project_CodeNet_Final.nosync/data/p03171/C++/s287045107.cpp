#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 3e3 + 5;
int dp[MAXN][MAXN][2];
int arr[MAXN];
int32_t main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        dp[i][1][0] = arr[i];
        dp[i][1][1] = -arr[i];
    }
    for(int l = 2; l <= n; l++){
        for(int i = 0; i <= n - l; i++){
            dp[i][l][0] = max(dp[i + 1][l - 1][1] + arr[i], dp[i][l - 1][1] + arr[i + l - 1]);
            dp[i][l][1] = min(dp[i + 1][l - 1][0] - arr[i], dp[i][l - 1][0] - arr[i + l - 1]);
        }
    }
    cout << dp[0][n][0] << '\n';
}
