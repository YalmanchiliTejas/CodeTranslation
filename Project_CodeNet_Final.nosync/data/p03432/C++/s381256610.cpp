#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 16384, MAX_M = 300;
const ll MOD = 998244353, MOD_G = 3;

ll sq(ll x) { return x * x % MOD; }
ll qpow(ll a, ll b) { return b ? sq(qpow(a, b / 2)) * (b & 1 ? a : 1) % MOD : 1; }
ll inv(ll x) { return qpow(x, MOD - 2); }

int N, M;
ll factorial[MAX_N], ifactorial[MAX_N], omega[MAX_N];

ll comb(int n, int m) { return factorial[n] * ifactorial[n - m] % MOD * ifactorial[m] % MOD; }

void NTT(ll A[], int n, int d = 1) {
    for (int i = 0, j = 0, k; i < n; i++) {
        if (i < j) swap(A[i], A[j]);
        for (k = n / 2; (j ^= k) < k; k /= 2);
    }

    for (int i = 1; i < n; i *= 2) {
        ll u = omega[(MAX_N + d * (MAX_N / (2 * i))) % MAX_N];
        for (int j = 0; j < n; j += 2 * i) {
            ll v = 1;
            for (int k = 0; k < i; k++) {
                ll a = A[j + k], b = A[j + k + i] * v % MOD;
                A[j + k] = (a + b) % MOD; A[j + k + i] = (a - b + MOD) % MOD;
                (v *= u) %= MOD;
            }
        }
    }

    if (d == -1) {
        ll inv_n = inv(n);
        for (int i = 0; i < n; i++) (A[i] *= inv_n) %= MOD;
    }
}

void init() {
    scanf("%d%d", &N, &M);
    factorial[0] = 1;
    for (int i = 1; i < MAX_N; i++) factorial[i] = factorial[i - 1] * i % MOD;
    ifactorial[MAX_N - 1] = inv(factorial[MAX_N - 1]);
    for (int i = MAX_N - 1; i; i--) ifactorial[i - 1] = ifactorial[i] * i % MOD;
    omega[0] = 1; omega[1] = qpow(MOD_G, (MOD - 1) / MAX_N);
    for (int i = 2; i < MAX_N; i++) omega[i] = omega[i - 1] * omega[1] % MOD;
}

ll F[MAX_M][MAX_N];

void solve() {
    F[0][0] = 1;
    for (int i = 0; i < M; i++) {
        static ll A[MAX_N], B[MAX_N];
        fill_n(A, MAX_N, 0);
        fill_n(B, MAX_N, 0);
        for (int j = 0; j <= N; j++) A[j] = F[i][j] * ifactorial[j] % MOD;
        for (int j = 1; j <= N; j++) B[j] = ifactorial[j + 2] % MOD;
        NTT(A, MAX_N);
        NTT(B, MAX_N);
        for (int j = 0; j < MAX_N; j++) (A[j] *= B[j]) %= MOD;
        NTT(A, MAX_N, -1);
        for (int j = 0; j <= N; j++) F[i + 1][j] = A[j] * factorial[j + 2] % MOD;
        for (int j = 0; j <= N; j++) {
            ll coe = j * (j + 1) / 2 + 1;
            (F[i + 1][j] += F[i][j] * coe) %= MOD;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= N; i++)
        (ans += F[M][i] * comb(N, i)) %= MOD;
    printf("%lld\n", ans);
}

int main() {
    init();
    solve();
}