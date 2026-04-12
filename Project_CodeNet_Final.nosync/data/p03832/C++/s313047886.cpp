#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007

int N,A,B,C,D;
int F[1010] = {1};
int dp[1010][1010];
int R[1010];

int power(int x,int y)
{
    if(y == 0)return 1;
    int res = power(x * x % MOD,y / 2);
    if(y & 1)res = x * res % MOD;
    return res % MOD;
}

int per(int x,int y)
{
    return F[x] * R[x - y] % MOD;
}

int P(int n,int m)
{
    if(n == 0)return dp[n][m] = 1;
    if(m < A)return dp[n][m] = 0;
    if(dp[n][m] != -1)return dp[n][m];
    int res = P(n,m - 1);
    for(int i = C; n - m * i >= 0 && i <= D; i++)
    {
        res += P(n - m * i,m - 1) *
               per(N - n + m * i,m * i) % MOD *
               power(power(F[m],i),MOD - 2) % MOD *
               R[i] % MOD;
        res %= MOD;
    }
    return dp[n][m] = res % MOD;
}

signed main()
{
    scanf("%lld%lld%lld%lld%lld",&N,&A,&B,&C,&D);
    for(int i = 0; i <= N; i++)for(int j = 0; j <= N; j++)dp[i][j] = -1;
    for(int i = 1; i < 1010; i++)F[i] = F[i - 1] * i % MOD;
    for(int i = 0; i < 1010; i++)R[i] = power(F[i],MOD - 2);
    printf("%lld\n",P(N,B));
    /*for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            printf("  %lld",dp[i][j]);
        }printf("\n");
    }*/
    return 0;
}
