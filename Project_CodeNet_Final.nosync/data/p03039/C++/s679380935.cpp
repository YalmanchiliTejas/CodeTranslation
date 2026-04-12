#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

const int MAX = 200100;
const int MOD = 1000000007;
int fact[MAX], finv[MAX], inv[MAX];

void Cinit() {
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i=2; i<MAX; i++) {
        fact[i] = fact[i-1]*i%MOD;
        inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}

int C(int n, int k) {
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return fact[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int N, M, K;

signed main() {
    Cinit();
    cin >> N >> M >> K;
    int ans = 0;
    for (int i=1; i<N; i++) {
        ans += i*(N-i)*M*M*C(N*M-2, K-2);
        ans %= MOD;
    }
    for (int i=1; i<M; i++) {
        ans += i*(M-i)*N*N*C(N*M-2, K-2);
        ans %= MOD;
    }
    cout << ans << endl;
}