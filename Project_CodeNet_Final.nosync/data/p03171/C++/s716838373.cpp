#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

int n, a[N];
long long dp[N][N];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) dp[i][i] = a[i];
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = max(-dp[i + 1][j] + a[i], -dp[i][j - 1] + a[j]);
        }
    }
    
    cout << dp[1][n];
    return 0;
}