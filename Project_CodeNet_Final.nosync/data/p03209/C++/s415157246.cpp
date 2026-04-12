#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans, N, X, patties[51], levels[51];

ll patties_eaten(ll level, ll x)
{
    if (x <= 0LL)
        return 0LL;
    if (level == 0LL)
        return 1LL;
    x--;
    ll pe;
    if (x >= levels[level - 1])
        pe = patties[level - 1];
    else
        pe = patties_eaten(level - 1, x);
    x-=levels[level - 1];
    if (x > 0LL)
    {
        pe++;
        x--;
    }
    pe += patties_eaten(level - 1, x);
    return pe;
}

int main()
{
    scanf("%lld %lld", &N, &X);
    patties[0] = 1;
    levels[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        patties[i] = 2*patties[i-1] + 1;
        levels[i] = 2*levels[i-1] + 3;
    }
    ans = patties_eaten(N, X);
    printf("%lld\n", ans);
    return 0;
}
