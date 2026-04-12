#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2e5 + 10;

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

int main() {
    int N, M, K; cin >> N >> M >> K;
    long long ans = 0;
    COMinit();
    for (int i = 1; i < M; i++) {
        ans = (ans + ((((COM(N*M-2, K-2) * (M - i) % MOD) * N % MOD) * N % MOD) * i % MOD)) % MOD;
    }
    for (int i = 1; i < N; i++) {
        ans = (ans + ((((COM(N*M-2, K-2) * (N - i) % MOD) * M % MOD) * M % MOD) * i % MOD)) % MOD;
    }
    cout << ans << endl;
}