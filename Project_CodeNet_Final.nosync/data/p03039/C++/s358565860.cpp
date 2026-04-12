#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define INF 2e9
#define MOD (1000000007)
#define EPS 1e-9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long long int lli;
lli extGcd(lli a, lli b, lli &x, lli &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        lli d = extGcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}

#define MAXN 200000
lli invN[MAXN + 1];
lli Fact[MAXN + 1];
lli FactInv[MAXN + 1];
void init()
{
    REPS(i, MAXN)
    {
        lli x, y;
        extGcd(i, MOD, x, y);
        x += MOD;
        x %= MOD;
        invN[i] = x;
    }
    Fact[0] = 1, FactInv[0] = 1;
    REPS(i, MAXN)
    {
        Fact[i] = (Fact[i - 1] * i) % MOD;
        FactInv[i] = (FactInv[i - 1] * invN[i]) % MOD;
    }
}

int main()
{
    init();
    cin.tie(0);
    ios::sync_with_stdio(false);
    lli N, M, K;
    cin >> N >> M >> K;
    //  cout << Fact[7] << " " << FactInv[2] << "\n";
    lli MN = M * N;

    lli dLen = M * N;
    dLen %= MOD;
    dLen *= M + N;
    dLen %= MOD;
    dLen *= MN - 1;
    dLen %= MOD;
    dLen *= invN[12];
    dLen %= MOD;
    lli ans = (2 * dLen) % MOD;
    //cout << ans << "\n";
    ans *= Fact[MN - 2];
    ans %= MOD;
    ans *= FactInv[K - 2];
    ans %= MOD;
    ans *= FactInv[MN - K];
    ans %= MOD;
    cout << ans << "\n";
}

//NM C K * K C 2