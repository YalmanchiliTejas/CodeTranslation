#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)

int N;
lint MOD;

lint power(lint x, lint n, lint MOD=MOD)
{
    lint ans = 1;
    while (n>0)
    {
        if (n & 1) (ans *= x) %= MOD;
        (x *= x) %= MOD;
        n >>= 1;
    }
    return ans;
}

vector<lint> fac, facInv, inv;
void facInit(int nmax)
{
    fac = facInv = inv = vector<lint>(nmax + 1, 1);
    for (int i = 2; i <= nmax; i++)
    {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        facInv[i] = facInv[i-1] * inv[i] % MOD;
    }
}

lint nCr(int n, int r)
{
    if (n<r || r<0) return 0;
    return (fac[n] * facInv[r] % MOD) * facInv[n-r] % MOD;
}


int main()
{
    cin >> N >> MOD;
    facInit(N);

    vector<lint> part(N + 1, 0);

    vector<vector<lint> > dp(N+1, vector<lint>(N+1)); // dp[i][j] : 品1~iの一部をj杯に分割する総数
    REP(i, N+1) dp[i][0] = 1;
    FOR(i, 1, N+1) FOR(j, 1, N+1) {
        dp[i][j] = (dp[i-1][j] * (j + 1) + dp[i-1][j-1]) % MOD;
    }

    REP(n, N+1) {
        lint pattern = power(2, N - n);
        lint pattern_p = power(2, N - n, MOD - 1);
        REP(j, n+1) (part[n] += (dp[n][j] * power(pattern, j) % MOD) * power(2, pattern_p)) %= MOD;
    }

    lint ans = 0;
    REP(n, N+1) (ans += ((MOD + 1 - n%2*2) * nCr(N, n) % MOD) * part[n]) %= MOD;
    cout << ans << endl;
}
