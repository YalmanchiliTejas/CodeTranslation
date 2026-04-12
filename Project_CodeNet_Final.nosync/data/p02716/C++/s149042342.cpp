#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll inf = 1e18;
ll mod = 1e9+7;
ll dp[200010][3];
ll n,a[200010];
int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -inf;
        }
    }
    dp[0][0] = a[0];
    dp[1][1] = a[1];
    dp[2][2] = a[2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i+k+2 > n) break;
                if (j + k > 2) break;
                dp[i+k+2][j+k] = max(dp[i+k+2][j+k], dp[i][j] + a[i+k+2]);
            }
        }
    }
    if (n & 1) {
        cout << max({dp[n-3][0],dp[n-2][1],dp[n-1][2]});
    } else {
        cout << max(dp[n-2][0], dp[n-1][1]);
    }
    cout << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}