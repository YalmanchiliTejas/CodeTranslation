#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;


const int MAX = 510000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM (int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    COMinit();

    ll N, M, K;
    cin >> N >> M >> K;

    ll ans = 0;
    for (ll a = 1; a < M; a++) {
        ans += a * (M - a) % MOD * N % MOD * N % MOD * COM(M*N-2, K-2) % MOD;
        ans %= MOD;
    }
    for (ll a = 1; a < N; a++) {
        ans += a * (N-a) % MOD * M % MOD * M % MOD * COM(M*N-2, K-2) % MOD;
        ans %= MOD;
    }

    cout << ans << "\n";
}