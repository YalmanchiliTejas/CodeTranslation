//thuanqvbn03
#include <bits/stdc++.h>

using namespace std;

const int MaxN = 3005;
const long long oo = 1e18;

int n;
int a[MaxN];
long long dp[MaxN][MaxN];

long long Cal(int L, int R, int Type)
{
    if (L == R)
    {
        return Type * a[L];
    }
    if (dp[L][R] != -oo)
    {
        return dp[L][R];
    }
    if (Type == 1)
    {
        dp[L][R] = max(a[L] + Cal(L + 1, R, -1), a[R] + Cal(L, R - 1, -1));
    }
    else
    {
        dp[L][R] = min(Cal(L + 1, R, 1) - a[L], Cal(L, R - 1, 1) - a[R]);
    }
    return dp[L][R];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = -oo;
        }
    }
    cout << Cal(1, n, 1);
    return 0;
}