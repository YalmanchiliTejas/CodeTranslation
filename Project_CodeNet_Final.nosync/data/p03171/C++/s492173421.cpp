#include<bits/stdc++.h>

using namespace std;


int main() {

    int n;
    cin >> n;
    long long a[n];
    long long dp[n][n];

    for(int i = 0; i < n; ++i) {
                 for(int b = 0; b < n; ++b) {
                     dp[i][b]=0;
                 }
    }
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = n - 1; i >= 0; --i) {
        for(int j = i; j < n; ++j) {

            if(i==j)
                dp[i][j] = a[j];
            else
                dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
             
        }
    }

    cout << dp[0][n-1];

    return 0;
}
