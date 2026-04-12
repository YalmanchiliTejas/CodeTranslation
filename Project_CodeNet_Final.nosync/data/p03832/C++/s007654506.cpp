#include <bits/stdc++.h>

using namespace std;

long long MOD=1000000007, Dp[1001][1001], F[1001], t, R, Sa;
long long Pow[1001];

long long Power(long long a, long long k)
{
    t = 1;
    R = 1;
    Sa = a;
    while (k)
    {
        if (k & t)
        {
            k -= t;
            R *= Sa;
            R %= MOD;
        }
        Sa *= Sa;
        Sa %= MOD;
        t <<= 1;
    }
    return R;
}

int main()
{
    //ios::sync_with_stdio(false);
    long long N, A, B, C, D, S=0;
    cin >> N >> A >> B >> C >> D;
    for (int i = 0; i <= 1000; i++)
    {
        for (int y = 0; y <= 1000; y++)
        {
            Dp[i][y] = 0;
        }
    }
    Dp[A-1][0] = 1;
    F[1] = 1;
    F[0] = 1;
    for (int i = 2; i <= 1000; i++)
    {
        F[i] = F[i-1] * i;
        F[i] %= MOD;
    }
    for (int i = 0; i <= 1000; i++)
    {
        Pow[i] = Power(F[i], MOD-2);
    }
    for (int i = A; i <= B; i++)
    {
        for (int y = 0; y <= N; y++)
        {
            Dp[i][y] += Dp[i-1][y];
            if (Dp[i][y] > MOD)
            {
                Dp[i][y] -= MOD;
            }
            for (int u = C; u <= D; u++)
            {
                if (u*i + y > N)
                {
                    break;
                }
                S = Dp[i-1][y];
                S *= F[N-y];
                S %= MOD;
                S *= Pow[N-y-u*i];
                S %= MOD;
                S *= Power(F[i], MOD-u-1);
                S %= MOD;
                S *= Pow[u];
                S %= MOD;
                Dp[i][y+u*i] += S;
                if (Dp[i][y+u*i] > MOD)
                {
                    Dp[i][y+u*i] -= MOD;
                }
            }
        }
    }
    cout << Dp[B][N];
    return 0;
}
