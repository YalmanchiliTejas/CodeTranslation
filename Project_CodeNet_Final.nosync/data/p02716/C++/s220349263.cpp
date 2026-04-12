#include <bits/stdc++.h>

//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3", "Ofast", "fast-math", "unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


#define int long long
#define endl '\n'

using namespace std;

const int inf = -1e17;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i, n;
    cin >> n;
    vector < int > a(n + 1);
    for (i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector < vector < int > > dp(n + 1, vector < int > (2, inf));
    dp[1][0] = 0;
    dp[1][1] = a[1];
    dp[2][0] = max(a[1], a[2]);
    dp[2][1] = inf;
    for (i = 3; i <= n; i++){
        if (i % 2 == 0){
            dp[i][0] = max(dp[i][0], dp[i - 1][1]);
            dp[i][0] = max(dp[i][0], dp[i - 2][0] + a[i]);
            dp[i][1] = max(dp[i][1], dp[i - 2][1] + a[i]);
        }
        else{
            dp[i][0] = max(dp[i][0], dp[i - 1][0]);
            dp[i][0] = max(dp[i][0], dp[i - 2][0] + a[i]);
            dp[i][1] = max(dp[i][1], dp[i - 1][1]);
            dp[i][1] = max(dp[i][1], dp[i - 2][1] + a[i]);
        }
    }
    cout << dp[n][0] << endl;

    return 0;
}
