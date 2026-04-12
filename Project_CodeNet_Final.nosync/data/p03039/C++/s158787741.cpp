#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

const int MAX = 210000;
const ll MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    COMinit();
    int n, m, k;
    cin >> n >> m >> k;
    ll ans = COM(n * m - 2, k - 2);

    ll sub = 0;
    rep(i, n)
    {
        rep(j, m)
        {
            ll a = (ll)(i + j) * (ll)(n - i) * (ll)(m - j);
            if (j != 0 && i != 0)
                a *= 2LL;
            sub += a;
            sub %= MOD;
        }
    }
    ans *= sub;
    ans %= MOD;
    cout << ans << endl;

    return 0;
}
