#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define FOR(i, a, b) for(int i=a, _n=b; i<=_n; ++i)
#define REV(i, a, b) for(int i=a, _n=b; i>=_n; --i)
using namespace std;

const int N = 1e3+5, mod = 1e9+7;
int n, a, b, c, d;
int64_t C[N][N], P[N], f[N], r[N];

int64_t pw(int64_t a, int n)
{
    if (n == 1) return a;
    int64_t res = pw(a, n>>1);
    res = res * res % mod;
    return (n&1) ? res * a % mod : res;
}
int main()
{
    ios::sync_with_stdio(); cin.tie(0);
    ///freopen("a.inp","r",stdin);

    cin >> n >> a >> b >> c >> d;

    FOR(i, 0, n) C[i][0] = 1;
    FOR(i, 1, n) FOR(j, 1, i) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;

    P[0] = r[0] = 1;
    FOR(i, 1, n) {
        P[i] = (P[i-1] * i) % mod;
        r[i] = pw(P[i], mod-2);
    }

    f[0] = 1;
    FOR(m, a, b) REV(i, n, 1) if (i >= m*c) {
        int64_t tmp = 1; int s = i;
        FOR(j, 1, c-1) {
            tmp = tmp * C[s][m] % mod;
            s = s - m;
        }
        FOR(j, c, d) {
            tmp = tmp * C[s][m] % mod;
            s = s - m; if (s < 0) break;
            f[i] = (f[i] + f[s] * tmp % mod * r[j] % mod) % mod;
        }
    }

    cout << f[n];
}
