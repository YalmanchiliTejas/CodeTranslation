#include <bits/stdc++.h>

using namespace std;

int dp[110][2][10];

int main()
{
    string s;
    cin >> s;
    int n = (int)s.size();
    int k;
    cin >> k;

    dp[0][0][0] = 1;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            for(int l = 0; l <= k; ++l)
            {
                int granica = j ? 9 : (s[i]-'0');
                for(int d = 0; d <= granica; ++d)
                {
                    dp[i+1][j || d < granica][l + (d!=0)] += dp[i][j][l];
                }
            }
        }
    }

    cout << dp[n][0][k] + dp[n][1][k] << '\n';

    return 0;
}
