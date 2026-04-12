#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll *fact, *fact_inv;

ll Mod(ll x) {
    if (x < 0)
        return (MOD - x % MOD);
    else
        return x % MOD;
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = Mod(res * a);
        a = Mod(a * a);
        b >>= 1;
    }
    return res;
}

ll inverse(ll x) { return power(x, MOD - 2); }

ll Comb(int N, int k) {
    if (k < 0 || N < k) {
        return 0;
    }
    return Mod(fact[N] * Mod(fact_inv[N - k] * fact_inv[k]));
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    ll ans = 0;
    fact = (ll *)malloc(sizeof(ll) * (N * M + 10));
    fact_inv = (ll *)malloc(sizeof(ll) * (N * M + 10));
    fact[0] = 1;
    fact_inv[0] = 1;
    for (int i = 1; i < N * M + 10; i++) {
        fact[i] = Mod(i * fact[i - 1]);
        fact_inv[i] = inverse(fact[i]);
    }

    ll comb = Comb(N * M - 2, K - 2);
    for (int d = 1; d < N; d++) {
        ans = Mod(ans + Mod(d * Mod((N - d) * Mod(M * Mod(M * comb)))));
    }
    for (int d = 1; d < M; d++) {
        ans = Mod(ans + Mod(d * Mod((M - d) * Mod(N * Mod(N * comb)))));
    }
    cout << ans << endl;
    return 0;
}
