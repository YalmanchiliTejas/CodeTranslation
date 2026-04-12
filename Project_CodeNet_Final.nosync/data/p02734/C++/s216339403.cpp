#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const int maxn = 1e5 + 10;
int N, S, A[maxn];
LL dp[maxn];
int main()
{
    scanf("%d %d", &N, &S);
    for(int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    LL ans = 0;
    for(int i = 1; i <= N; i++)
    {
        if(A[i] == S)
            ans = (ans + i * (N - i + 1) % MOD) % MOD;
        if(A[i] >= S)
            continue;
        ans = (ans + dp[S-A[i]] * (N - i + 1) % MOD) % MOD;
        for(int j = S - 1; j >= 0; j--)
        {
            if(A[i] + j < S)
                dp[A[i] + j] = (dp[A[i] + j] + dp[j] % MOD)% MOD;
        }
        dp[A[i]] = (dp[A[i]] + i) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
