#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int k;
    cin >> s >> k;
    long long dp[s.size() + 1][k + 1][10];
    for(int i = 0; i <= s.size(); i++)
    {
        for(int j = 0; j <= k; j++)
        {
            for(int d = 0; d < 10; d++)
            {
                dp[i][j][d] = 0;
            }
        }
    }
    dp[1][0][0] = 1;
    for(int i = 1; i <= 9; i++)
    {
        dp[1][1][i] = 1;
    }
    for(int i = 2; i <= s.size(); i++)
    {
        for(int j = 0; j <= k; j++)
        {
            for(int d = 0; d < 10; d++)
            {
                if(d != 0)
                {
                    if(j == 0)
                        break;
                    for(int t = 0; t < 10; t++)
                    {
                        if(j > 0)
                        {
                            dp[i][j][d] += dp[i - 1][j - 1][t];
                        }
                    }
                }
                else
                {
                    for(int t = 0; t < 10; t++)
                    {
                        dp[i][j][d] += dp[i - 1][j][t];
                    }
                }
            }
        }
    }
    long long ans = 0, not_zero = 0;
    for(int i = 0; i <= s.size(); i++)
    {
        if(i > 0 && s[i - 1] != '0')
        {
            not_zero++;
        }
        if(k - not_zero >= 0)
        {
            for(int j = 0; j < s[i] - '0'; j++)
            {
                ans += dp[s.size() - i][k - not_zero][j];
            }
        }
    }
    if(not_zero == k)
        ans++;
    cout << ans;
    return 0;
}
