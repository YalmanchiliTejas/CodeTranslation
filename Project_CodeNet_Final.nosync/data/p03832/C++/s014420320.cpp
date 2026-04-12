// {{{
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
// }}}

using ll = long long;

ll MOD = 1000000007;

ll modpow(ll a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 1) return a * modpow(a, n-1) % MOD;
    ll h = modpow(a, n/2) % MOD;
    return h * h % MOD;
}

ll modinv(ll x) {
    return modpow(x, MOD-2);
}

ll perm[1010][1010], fact[1010], factinv[1010], factpowinv[1010][1010];

void init() {
    for (int j = 0; j <= 1000; ++j) {
        perm[j][0] = 1;
        for (int k = 1; k <= j; ++k)
            perm[j][k] = perm[j][k-1] * (j-k+1) % MOD;
    }

    fact[0] = 1;
    for (int j = 1; j <= 1000; ++j)
        fact[j] = fact[j-1] * j % MOD;

    for (int j = 0; j <= 1000; ++j)
        factinv[j] = modinv(fact[j]);

    ll inv1 = modinv(1);
    for (int j = 0; j <= 1000; ++j)
        factpowinv[j][0] = inv1;

    for (int j = 0; j <= 1000; ++j) {
        for (int k = 1; k <= 1000; ++k)
            factpowinv[j][k] = factpowinv[j][k-1] * factinv[j] % MOD;
    }
}

int N, A, B, C, D;

ll dp[1010][1010];

int main() {
    cin >> N >> A >> B >> C >> D;
    init();

    for (int j = A; j <= B; ++j) fill(dp[j], dp[j]+N+1, 0);
    dp[A-1][0] = 1;

    for (int j = A; j <= B; ++j) {
        for (int k = 0; k <= N; ++k) {
            dp[j][k] = dp[j-1][k];
            for (int m = C; m <= D && k - m * j >= 0; ++m) {
                ll inc = dp[j-1][k - m*j]
                    * perm[N - k + m*j][m*j] % MOD
                    * factpowinv[j][m] % MOD
                    * factinv[m] % MOD;
                dp[j][k] = (dp[j][k] + inc) % MOD;
            }
        }
    }

    cout << dp[B][N] << endl;
    return 0;
}
