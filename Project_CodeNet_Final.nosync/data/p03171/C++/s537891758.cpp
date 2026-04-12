#include <bits/stdc++.h>

using namespace std;

#define FaSt ios::sync_with_stdio(0),cin.tie(0);
#define random uniform_int_distribution<long long>(1, 2000000000000000LL)(rng)

const int N = 3005, K = 100005;
int n, a[N];
long long dp[N][N][2];
bool solved[N][N][2];

long long calc(int i, int j, bool b)
{
    if (i > j)
    {
        return 0;
    }
    
    if (solved[i][j][b])
    {
        return dp[i][j][b];
    }
    
    if (b == 0)
    {
        dp[i][j][b] = max(a[i] + calc(i + 1, j, 1), a[j] + calc(i, j - 1, 1));
    }
    else
    {
        dp[i][j][b] = min(-a[i] + calc(i + 1, j, 0), -a[j] + calc(i, j - 1, 0));
    }
    
    solved[i][j][b] = 1;
    return dp[i][j][b];
}

int main()
{
    FaSt
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    cout << calc(0, n - 1, 0);
}
