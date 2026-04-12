#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e2 + 5;

int n, k;
ll dp[N][5][2];
char s[N];

ll solveI()
{
    for(int i = n ; i >= 0 ; i--) dp[i][0][0] = dp[i][0][1] = 1;
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        for(int j = 1 ; j <= k ; j++)
        {
            dp[i][j][1] = 9 * dp[i + 1][j - 1][1] + dp[i + 1][j][1];
            if(s[i] != '0') dp[i][j][0] = (s[i] - '1') * dp[i + 1][j - 1][1] + dp[i + 1][j - 1][0] + dp[i + 1][j][1];
            else dp[i][j][0] = dp[i + 1][j][0];
        }
    }
    return dp[0][k][0];
}

int main()
{
    scanf("%s%d", s, &k);
    n = strlen(s);
    printf("%lld\n", solveI());
}
