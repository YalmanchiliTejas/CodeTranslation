#include <cstdio>

typedef long long ll;

ll tree[202020];

ll mod = 1e9 + 7;

void add(int idx, int diff)
{
    while (idx < 202020)
    {
        tree[idx] += diff;
        tree[idx] %= mod;
        idx += (idx) & (-idx);
    }
}

ll sum(int idx)
{
    ll ret = 0;
    while (idx > 0)
    {
        ret += tree[idx];
        ret %= mod;
        idx -= (idx) & (-idx);
    }
    return ret;
}

int main(void)
{
    ll N, x;
    ll A[202020];
    scanf("%lld", &N);

    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &x);
        add(i, x);
        A[i] = x;
    }

    ll ans = 0;

    for (int i = 1; i <= N; i++)
    {
        ans += ((sum(N) - sum(i)+ mod) * A[i])%mod;
        ans %= mod;
    }

    printf("%lld\n", ans);

    return 0;
}