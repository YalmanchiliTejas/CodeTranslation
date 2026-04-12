#include <bits/stdc++.h>

//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


#define int long long
#define endl '\n'

using namespace std;

const int mod = 998244353;

int dp[3228][3228][2];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i, j, n, s, m;
    cin >> n >> s;
    vector < int > a(n + 1);
    for (i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    int ans = 0;
    for (i = 1; i <= n; i++){
        dp[i][0][1] = i + 1;
        dp[i][0][0] = i * (i - 1) / 2;
        for (j = 1; j <= s; j++){
            dp[i][j][1] = dp[i - 1][j][1];
            dp[i][j][1] %= mod;
            if (j >= a[i]){
                dp[i][j][1] += dp[i - 1][j - a[i]][1];
                dp[i][j][1] %= mod;
            }
        }
        for (j = 1; j <= s; j++){
            dp[i][j][0] = dp[i - 1][j][0];
            dp[i][j][0] += dp[i][j][1];
            dp[i][j][0] %= mod;
        }


    }
    cout << dp[n][s][0] << endl;
    return 0;
}
