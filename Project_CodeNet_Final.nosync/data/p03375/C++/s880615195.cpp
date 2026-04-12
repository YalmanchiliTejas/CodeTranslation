#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll mod;
ll dp[2][3010];
ll P[10000000] = {1};
ll F[3010] = {1},R[3010],D[3010] = {2};
ll ans = 0;

ll pow_mod(ll a,ll b)
{
    if(b == 0)return 1;
    ll res = pow_mod(a * a % mod,b / 2);
    if(b & 1)res = res * a % mod;
    return res;
}

ll con(int a,int b)
{
    return F[a] * R[b] % mod * R[a - b] % mod;
}

int main()
{
    scanf("%d%lld",&N,&mod);

    for(int i = 1; i < 3010; i++)F[i] = F[i - 1] * i % mod;
    for(int i = 1; i < 10000000; i++)P[i] = P[i - 1] * 2 % mod;
    for(int i = 1; i < 3010; i++)D[i] = D[i - 1] * D[i - 1] % mod;
    for(int i = 0; i < 3010; i++)R[i] = pow_mod(F[i],mod - 2);
    dp[0][0] = 1;
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            //if(dp[i][j] == 0)continue;
            dp[1][j] += dp[0][j];
            dp[1][j] += dp[0][j] * j;
            dp[1][j + 1] += dp[0][j];
            dp[1][j] %= mod;
            dp[1][j + 1] %= mod;
            ll tmp = ((dp[0][j] * P[(N - i) * j] % mod * D[N - i] % mod * con(N,i) % mod)) % mod;
            if(i % 2)ans -= tmp;
            else ans += tmp;
            ans = (ans + mod) % mod;
        }
        for(int j = 0; j <= N; j++)
        {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }

    printf("%lld\n",ans);
    return 0;
}
