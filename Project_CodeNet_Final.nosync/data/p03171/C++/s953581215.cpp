#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int SIZE = 3e3+9;

int n;
ll a[SIZE];
ll dp[SIZE][SIZE]; // [i, j] で先手が得られる最大の得点
ll sum[SIZE]; // [1, i] の総和

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    for(int len = 1; len <= n; len++) {
        for(int i = 1; i <= n; i++) {
            int j = i + len - 1;
            if(j > SIZE)    continue;
            if(len == 1) {
                dp[i][j] = a[i];
                continue;
            }
            ll d1 = sum[j] - sum[i-1] - dp[i][j-1];
            ll d2 = sum[j] - sum[i-1] - dp[i+1][j];
            dp[i][j] = max(d1, d2);
        }
    }
    cout << dp[1][n] - min(dp[1][n-1], dp[2][n]) << endl;
}