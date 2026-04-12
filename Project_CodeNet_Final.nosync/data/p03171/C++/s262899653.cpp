//In The Name of Allah
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3000 + 10;

ll a[N], dp[N][N][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    for (int len = 0; len < n; len ++)
        for (int i = 0; i + len < n; i ++)
            for (int j = 0; j < 2; j ++)
                dp[i][i + len][j] = max(a[i] - dp[i + 1][i + len][1 -j], a[i + len] - dp[i][i + len - 1][1 - j]);
    cout << dp[0][n - 1][0];
    return 0;
}
