#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


#define N 200007
ll fac[N], inv[N], finv[N];

void cominit(int n) {
    int i;
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (i = 2; i < n + 2; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
    return;
}

ll com(int n, int r) {
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    if (r == 0 || r == n) return 1;
    return (fac[n] * finv[r]) % mod * finv[n - r] % mod;
}

int main(void) {
    int n, m, k;
    ll fdi, fdj, cdi, cdj, ans;

    scanf("%d%d%d", &n, &m, &k);

    cominit(n * m);

    fdi = 0;
    for (cdi = 1; cdi <= n - 1; cdi++) {
        fdi += cdi * (n - cdi) % mod * m % mod * m % mod;
    }
    fdj = 0;
    for (cdj = 1; cdj <= m - 1; cdj++) {
        fdj += cdj * (m - cdj) % mod * n % mod * n % mod;
    }

    ans = (fdi + fdj) % mod;

    ans = ans * com(n * m - 2, k - 2) % mod;

    printf("%lld\n", ans);

    return 0;
}