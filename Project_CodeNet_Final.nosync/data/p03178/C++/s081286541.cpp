#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ll long long
#define ld long double
#define pii pair < int , int >

const int M = 1e9 + 7;

int main()
{
    #ifdef Estb_probitie
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    string s;
    int x;
    cin >> s;
    cin >> x;
    ll dp[s.size()][x][3] = {};

    for (int i = 1; i < 10; ++i)
    {
        if (i + '0' < s[0])
            dp[0][i % x][0]++;
        else
        if (i + '0' == s[0])
            dp[0][i % x][1]++;
        else
            dp[0][i % x][2]++;
    }

    for (int i = 0 ;i + 1 < s.size(); ++i)
        for (int j = 0; j < x; ++j)
          for (int l = 0; l < 10; ++l)
            {
                int zn = (j + l) % x;
                if (l + '0' < s[i + 1])
                    dp[i + 1][zn][0] += dp[i][j][0] + dp[i][j][1],
                    dp[i + 1][zn][2] += dp[i][j][2]; else
                if (l + '0' == s[i + 1])
                    dp[i + 1][zn][0] += dp[i][j][0],
                    dp[i + 1][zn][1] += dp[i][j][1],
                    dp[i + 1][zn][2] += dp[i][j][2];
                else
                    dp[i + 1][zn][0] += dp[i][j][0],
                    dp[i + 1][zn][2] += dp[i][j][1] + dp[i][j][2];
                dp[i + 1][zn][0] %= M;
                dp[i + 1][zn][1] %= M;
                dp[i + 1][zn][2] %= M;
            }
    ll ans = 0;
    for (int i = 0; i  + 1< s.size(); ++i)
        for (int fl = 0; fl < 3; ++fl)
          ans += dp[i][0][fl], ans%=M;
    ans += dp[s.size() - 1][0][0] + dp[s.size() - 1][0][1];
    cout << ans % M;
}
