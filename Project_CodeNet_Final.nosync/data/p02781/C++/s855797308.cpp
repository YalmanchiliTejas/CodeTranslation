#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
string N;
int K;
ll dp[110][3][4];

int main()
{
    cin >> N;
    cin >> K;
    for (int i = 1; i <= N.length(); i++)
    {
        int n = N[i - 1] - '0';
        if (i == 1)
        {
            // n != 0
            dp[i][0][1] = 1;
            dp[i][1][1] = n - 1;
            dp[i][1][0] = 1;
            continue;
        }

        if (n == 0)
        {
            for (int k = 0; k <= 3; k++)
            {
                dp[i][0][k] = dp[i - 1][0][k];
                if (k >= 1)
                {
                    dp[i][1][k] = dp[i - 1][1][k] + dp[i - 1][1][k - 1] * 9;
                }
                else
                {
                    dp[i][1][0] = dp[i - 1][1][0];
                }
            }
        }
        else
        {
            dp[i][0][1] = dp[i - 1][0][0];
            dp[i][0][2] = dp[i - 1][0][1];
            dp[i][0][3] = dp[i - 1][0][2];
            dp[i][1][0] = dp[i - 1][1][0];
            for (int k = 1; k <= 3; k++)
            {
                /*
                dp[i][1][k] = dp[i - 1][0][1] + dp[i - 1][1][1];
                dp[i][1][k] += dp[i - 1][0][k - 1] * (n - 1);
                dp[i][1][k] += dp[i - 1][1][k - 1] * n;
                */
                dp[i][1][k] = dp[i - 1][0][k - 1] * (n - 1);
                dp[i][1][k] += dp[i - 1][0][k];
                dp[i][1][k] += dp[i - 1][1][k - 1] * 9;
                dp[i][1][k] += dp[i - 1][1][k];
            }
        }
    }
    cout << dp[N.length()][0][K] + dp[N.length()][1][K] << endl;
}
