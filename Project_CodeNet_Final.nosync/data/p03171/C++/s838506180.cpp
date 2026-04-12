
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e3 + 5;
int n;
ll dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> dp[1][i];
    }
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len <= n; i++) {
            dp[len][i] = max(dp[1][i + len - 1] - dp[len - 1][i], dp[1][i] - dp[len - 1][i + 1]);
        }
    }
    cout << dp[n][0] << endl;
}