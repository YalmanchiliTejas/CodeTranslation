#include <bits/stdc++.h>
using namespace std;
using Int = long long;
constexpr Int MOD = 1e9 + 7;
constexpr int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main()
{
    COMinit();
    Int N, M, K; cin >> N >> M >> K;
    Int ans = 0;
    Int com = COM(N*M-2, K-2);
    for (int i = 1; i < N; i++) {
        ans = (ans + (N - i) * i * M % MOD * M % MOD * com) % MOD;
    }
    for (int i = 1; i < M; i++) {
        ans = (ans + (M - i) * i * N % MOD * N % MOD * com) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
