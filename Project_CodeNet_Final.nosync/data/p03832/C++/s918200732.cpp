#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAXN = 1000, MOD = 1000 * 1000 * 1000 + 7;
int f[MAXN + 1], f1[MAXN + 1], dp[MAXN + 1][MAXN + 1];

int binPow(int a, int n) {
    if(n == 0)
        return 1;
    else if(n & 1)
        return (1LL * binPow(a, n  - 1) * a) % MOD;
    else {
        int d = binPow(a, n / 2);
        return (1LL * d * d) % MOD;
    }
}

void add(int& a, int b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

int C(int n, int k) {
    int res = (1LL * f[n] * f1[k]) % MOD;
    res = (1LL * res * f1[n - k]) % MOD;
    return res;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    f[0] = 1;
    f1[0] = 1;
    for(int i = 1; i <= n; i++) {
        f[i] = (1LL * f[i - 1] * i) % MOD;
        f1[i] = binPow(f[i], MOD - 2);
        assert(((ll)f[i] * f1[i]) % MOD == 1);
    }
    dp[a - 1][n] = 1;
    for(int cnt = a; cnt <= b; cnt++) {
        for(int lost = n; lost >= 0; lost--) {
            add(dp[cnt][lost], dp[cnt - 1][lost]);
            if(lost < c * cnt)
                continue;
            int val = 1;
            for(int curG = 1; curG < c; curG++) {
                val = (1LL * val * C(lost - (curG - 1) * cnt, cnt)) % MOD;
            }
            for(int curG = c; curG <= d && lost >= curG * cnt; curG++) {
                val = (1LL * val * C(lost - (curG - 1) * cnt, cnt)) % MOD;
                add(dp[cnt][lost - curG * cnt], (((1LL * dp[cnt - 1][lost] * val) % MOD) * (ll)f1[curG]) % MOD);
            }
        }
    }
    cout << dp[b][0] << endl;
    return 0;
}