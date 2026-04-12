#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

const int mod = 1e9 + 7;

int N, A, B, C, D;
int fct[1005], ifct[1005];
int dp[1005][1005];

int add(int x, int y)
{
    x += y; if(x >= mod)    x -= mod;
    return x;
}

int mult(int x, int y)
{
    return (1LL * x * y) % mod;
}

int power(int x, int y)
{
    int p = x, r = 1;
    while(y > 0)
    {
        if(y & 1)   r = mult(r, p);
        p = mult(p, p);
        y >>= 1;
    }
    return r;
}

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d", &N);
    scanf("%d%d", &A, &B);
    scanf("%d%d", &C, &D);

    fct[0] = ifct[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        fct[i] = mult(fct[i - 1], i);
        ifct[i] = power(fct[i], mod - 2);
    }

    dp[0][0] = 1;
    for(int i = 1; i <= B - A + 1; i++)
    {
        for(int j = 0; j <= N; j++)
            dp[i][j] = dp[i - 1][j];
        int l = i + A - 1;
        int pwfct = power(ifct[l], C - 1);
        for(int j = C; j <= D; j++)
        {
            pwfct = mult(pwfct, ifct[l]);
            for(int k = 0; k + j * l <= N; k++)
                dp[i][k + j * l] = add( dp[i][k + j * l], mult( dp[i - 1][k], mult( ifct[j], pwfct ) ) );
        }
    }

    int ans = mult(dp[B - A + 1][N], fct[N]);
    printf("%d\n", ans);

    return 0;
}
