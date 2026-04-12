#include <bits/stdc++.h>

using namespace std;

const int NM_MAX = 10;

int n, m;

bool ma[NM_MAX][NM_MAX];

int dp[NM_MAX][NM_MAX];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++)
            ma[i][j] = (s[j - 1] == '#');
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(ma[i][j] == 1)
                cnt++;
    if(cnt > n + m - 1)
    {
        cout << "Impossible\n";
        return 0;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(ma[i][j] == 1)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
    if(dp[n][m] == n + m - 1)
        cout << "Possible\n";
    else
        cout << "Impossible\n";
    return 0;
}
