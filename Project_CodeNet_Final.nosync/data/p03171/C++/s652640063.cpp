#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3589;

ll a[N], dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int len=1; len<=n; len++) {
        for (int i=1, j=i+len-1; j<=n; i++, j++) {
            dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
        }
    }
    cout << dp[1][n] << '\n';
}
