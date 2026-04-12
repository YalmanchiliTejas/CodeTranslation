#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int n;
int constexpr N = 3009;
int a[N];
int dp[N][N][2];

void read_input()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    read_input();

    for(int len = 1; len <= n; ++len) {
        for(int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            if(len == 1) {
                dp[i][j][0] = a[i];
                dp[i][j][1] = -a[i];
                continue;
            }
            dp[i][j][0] = max(a[i] + dp[i + 1][j][1], a[j] + dp[i][j - 1][1]);
            dp[i][j][1] = min(-a[i] + dp[i + 1][j][0], -a[j] + dp[i][j - 1][0]);
        }
    }

    cout << dp[1][n][0] << endl;

}
