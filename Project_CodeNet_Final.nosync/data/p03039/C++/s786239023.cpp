#include "bits/stdc++.h"

#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define FORV(a, A) for (auto &a : A)

using namespace std;

using ll = long long;

const ll MAX = 510000;
const int MOD = 1E9 + 7;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void Main()
{
    ll N, M, K;
    cin >> N >> M >> K;
    COMinit();
    ll ans = 0;
    REP(d, 1, M - 1)
    {
        ans += d * (M - d) * N * N;
        ans %= MOD;
    }
    REP(d, 1, N - 1)
    {
        ans += d * (N - d) * M * M;
        ans %= MOD;
    }

    ans = (ans * COM(N * M - 2, K - 2)) % MOD;
    cout << ans << endl;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}