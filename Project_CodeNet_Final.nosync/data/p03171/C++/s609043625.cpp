#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    long long dp[n+2][n+1] = {0};
    reverse(a.begin(), a.end());
    for(int i=0; i<n; i++) {
        for(int j=n-1-i; j<n; j++) {
            if(j == n-1-i) {
                dp[i][j] = a[i];
            } else {
                dp[i][j] = max(dp[i][n-1-i]-dp[i-1][j], dp[n-1-j][j]-dp[i][j-1]);
            }
        }
    }
    /*
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[n-1][n-1];
    // What is important so far
    // current change
    return 0;
}
