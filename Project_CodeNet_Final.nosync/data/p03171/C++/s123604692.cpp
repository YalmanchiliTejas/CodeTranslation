#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define int long long

typedef pair<int, int> ii;

const int mod = 1e9 + 7;

const int N = 3e3 + 5;

const int inf = 1e15;

int n, dp[N][N][2], a[N];

signed main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    /*for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k <= 1; k++)
                dp[i][j][k] =
        }
    }*/
    for(int i = 1; i <= n; i++) {
        if(n % 2 != 0) {
            dp[i][i][0] = a[i];
            dp[i][i][1] = 0;
        }
        else {
            dp[i][i][0] = 0;
            dp[i][i][1] = -a[i];
        }
    }
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i <= n; i++) {
            int j = i + len - 1, k;
            if(j > n) break;
            if((n - len) % 2 != 0) {//luot thang 2
                k = 1;
                dp[i][j][k] = min(dp[i + 1][j][1 - k] - a[i], dp[i][j - 1][1 - k] - a[j]);
            }
            else {
                k = 0;
                dp[i][j][k] = max(dp[i + 1][j][1 - k] + a[i], dp[i][j - 1][1 - k] + a[j]);
            }
        }
    }
    cout << dp[1][n][0];
}
