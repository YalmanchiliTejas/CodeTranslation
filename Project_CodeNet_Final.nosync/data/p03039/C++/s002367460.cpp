#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)

using namespace std;

namespace mp = boost::multiprecision;

using ll = long long;
using Bint = mp::cpp_int;

ll mod = 1000000007;
const ll com_max = 510000;

ll fac[com_max], finv[com_max], inv[com_max];

void Cominit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    for (ll i = 2; i < com_max; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

ll com(ll n, ll k) {
    if (n < k) {
        return 0;
    }
    if (n < 0 || k < 0) {
        return 0;
    }

    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
    // source
    ll n, m, k;
    cin >> n >> m >> k;
    Cominit();

    ll sigma0 = 0, sigma1 = 0;
    repd(d, 1, m) { sigma0 += d * (m - d); }
    repd(d, 1, n) { sigma1 += d * (n - d); }

    sigma0 %= mod;
    sigma1 %= mod;

    ll front0 = ((n * n) % mod) * com(n * m - 2, k - 2),
       front1 = ((m * m) % mod) * com(n * m - 2, k - 2);

    front0 %= mod;
    front1 %= mod;

    ll ans = front0 * sigma0 + front1 * sigma1;
    ans %= mod;

    cout << ans << endl;

    return 0;
}

