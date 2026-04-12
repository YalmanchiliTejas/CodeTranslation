#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    int n;
    cin >> n;
    ll a[n];
    long long dp[n][n];

    for(int i = 0; i < n; ++i) 
        cin >> a[i];

    for(int l = n - 1; l >= 0; --l) {

        for(int r = l; r < n; ++r) {

            if(l == r)
                dp[l][r] = a[r];
            else
                dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
            // for(int i = 0; i < n; ++i) {
            //     for(int j = 0; j < n; ++j) {
            //         cout << dp[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        }
    }

    cout << dp[0][n-1];

    return 0;
}