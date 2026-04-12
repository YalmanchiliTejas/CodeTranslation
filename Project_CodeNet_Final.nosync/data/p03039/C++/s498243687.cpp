#include <iostream>
#include <algorithm>

using namespace std;

constexpr int64_t MOD = 1'000'000'007;

int64_t f(int64_t n, int64_t m) {
    int64_t res = 0;
    for(int d=1; d<m; d++) {
        res += d * (m-d);
        res %= MOD;
    }
    res *= n*n % MOD;
    return res % MOD;
}

int64_t modinv(int64_t a) {
    int64_t b = MOD, u = 1, v = 0;
    while (b) {
        int64_t t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

int main(void) {
    int64_t N, M, K;
    cin >> N >> M >> K;

    int64_t ans = f(N, M) + f(M, N);
    for(int64_t i=1; i<=K-2; i++) {
        ans *= (N*M-1-i);
        ans %= MOD;
        ans *= modinv(i);
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
