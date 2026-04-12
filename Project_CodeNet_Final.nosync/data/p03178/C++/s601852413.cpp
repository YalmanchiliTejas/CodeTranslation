#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int MaxN = 1e4 + 14;
const int MaxD = 100;

int dp[MaxN][MaxD][2];

void up(int & x, int y)
{
    x += y;
    if(x >= MOD)
        x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);

    string s;
    cin >> s;

    int D;
    cin >> D;

    for(int i = 0; i < s[0] - '0'; ++i)
        dp[1][i % D][0] += 1;
    dp[1][(s[0] - '0') % D][1] += 1;

    for(int i = 2; i <= s.size(); ++i)
    {
        int curD = s[i - 1] - '0';
        for(int prevSum = 0; prevSum < D; ++prevSum)
            for(int nextD = 0; nextD < 10; ++nextD)
            {
                int nextSum = (prevSum + nextD) % D;

                if(nextD < curD)
                {
                    up(dp[i][nextSum][0], dp[i - 1][prevSum][0]);
                    up(dp[i][nextSum][0], dp[i - 1][prevSum][1]);
                }else
                if(nextD == curD)
                {
                    up(dp[i][nextSum][0], dp[i - 1][prevSum][0]);
                    up(dp[i][nextSum][1], dp[i - 1][prevSum][1]);
                }else
                {
                    up(dp[i][nextSum][0], dp[i - 1][prevSum][0]);

                }
            }
    }

    int ans = MOD - 1;
    up(ans, dp[s.size()][0][0]);
    up(ans, dp[s.size()][0][1]);

    cout << ans << '\n';

    return 0;
}

