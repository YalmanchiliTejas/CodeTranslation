#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

const int MAX_N = 200000;
const int MOD = 1000000007;
long long inv[MAX_N + 1], fac[MAX_N + 1], finv[MAX_N + 1];

void init() {
    inv[1] = fac[0] = fac[1] = finv[0] = finv[1] = 1;
    for (int i = 2; i <= MAX_N; ++i) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fac[i] = fac[i - 1] * i % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long nPk(int n, int k) {
    if (n < k || n < 0 || k < 0) return 0;
    return fac[n] * finv[n - k] % MOD;
}

long long nCk(int n, int k) {
    if (n < k || n < 0 || k < 0) return 0;
    return nPk(n, k) * finv[k] % MOD;
}

long long nHk(int n, int k) {
    if (n < 0 || k < 0) return 0;
    return nCk(n + k - 1, k);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int N, M, K;
    cin >> N >> M >> K;
    int ans = 0;
    FOR (i, 1, N) (ans += M * M % MOD * nCk(N * M - 2, K - 2) % MOD * (N - i) * i % MOD) %= MOD;
    FOR (i, 1, M) (ans += N * N % MOD * nCk(N * M - 2, K - 2) % MOD * (M - i) * i % MOD) %= MOD;
    cout << ans << endl;
}