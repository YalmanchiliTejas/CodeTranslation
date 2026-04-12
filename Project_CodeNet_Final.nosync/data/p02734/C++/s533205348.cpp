#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

int A[3000];
ll dp[3001][3001][3];
int main()
{
    int N, S;
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int s = 0; s < S + 1; s++)
        {
            dp[i + 1][s][0] = dp[i][s][0];
            if (s - A[i] >= 0)
            {
                dp[i + 1][s][1] = (dp[i][s][1] + dp[i][s][0] + dp[i][s - A[i]][1] + dp[i][s - A[i]][0]) % MOD;
                dp[i + 1][s][2] = (dp[i][s][2] + dp[i][s][1] + dp[i][s][0] + dp[i][s - A[i]][1] + dp[i][s - A[i]][0]) % MOD;
            }
            else
            {
                dp[i + 1][s][1] = (dp[i][s][1] + dp[i][s][0]) % MOD;
                dp[i + 1][s][2] = (dp[i][s][2] + dp[i][s][1] + dp[i][s][0]) % MOD;
            }
        }
    }

    cout << dp[N][S][2] << endl;
}
