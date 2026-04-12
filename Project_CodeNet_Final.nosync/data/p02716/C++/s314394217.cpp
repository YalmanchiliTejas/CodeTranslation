#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 60; //10e18+10e17ちょっとくらい
const int MOD = 1000000007;
const int MAX_N = 200100;

int dp[200010][2][3];
signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    vi v;
    rep(i, 200010)
        rep(j, 2)
            rep(k, 3)
                dp[i][j][k] = -INF;
    rep(i, n)
    {
        int t;
        cin >> t;
        v.emplace_back(t);
    }
    if (n % 2 == 0)
    {
        dp[0][0][0] = -INF;
        dp[0][0][1] = 0;
        dp[0][0][2] = -INF;
        dp[0][1][0] = -INF;
        dp[0][1][1] = -INF;
        dp[0][1][2] = -INF;
    }
    else
    {
        dp[0][0][0] = -INF;
        dp[0][0][1] = -INF;
        dp[0][0][2] = 0;
        dp[0][1][0] = -INF;
        dp[0][1][1] = -INF;
        dp[0][1][2] = -INF;
    }
    rep(i, n)
    {
        dp[i + 1][0][0] = max(dp[i][0][1], dp[i][1][0]);
        dp[i + 1][0][1] = max(dp[i][0][2], dp[i][1][1]);
        dp[i + 1][0][2] = dp[i][1][2];
        if (dp[i][0][0] != -INF)
            dp[i + 1][1][0] = dp[i][0][0] + v[i];
        if (dp[i][0][1] != -INF)
            dp[i + 1][1][1] = dp[i][0][1] + v[i];
        if (dp[i][0][2] != -INF)
            dp[i + 1][1][2] = dp[i][0][2] + v[i];
    }

    int ans = -INF;
    ans = max(ans, dp[n][0][0]);
    ans = max(ans, dp[n][0][1]);
    // ans = max(ans, dp[n][0][2]);
    ans = max(ans, dp[n][1][0]);
    ans = max(ans, dp[n][1][1]);
    // ans = max(ans, dp[n][1][2]);
    cout << ans << endl;

    return 0;
}