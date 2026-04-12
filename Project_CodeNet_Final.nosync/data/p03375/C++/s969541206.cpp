#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 3030;

int N;
ll P, F[MAX_N][MAX_N], fac[MAX_N], ifac[MAX_N], pof2[MAX_N * MAX_N];

ll sq(ll x, ll p = P) { return x * x % p; }
ll qpow(ll a, ll b, ll p = P) { return b ? sq(qpow(a, b / 2, p), p) * (b & 1 ? a : 1) % p : 1; }
ll inv(ll x) { return qpow(x, P - 2); }
ll comb(int n, int m) { return fac[n] * ifac[n - m] % P * ifac[m] % P; }

int main() {
    scanf("%d%lld", &N, &P);
    for (int i = 0; i <= N; i++) {
        F[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            F[i][j] = ((j + 1) * F[i - 1][j]  + F[i - 1][j - 1]) % P;
        }
    }
    fac[0] = 1;
    for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % P;
    ifac[N] = inv(fac[N]);
    for (int i = N; i; i--) ifac[i - 1] = ifac[i] * i % P;
    pof2[0] = 1;
    for (int i = 1; i <= N * N; i++) pof2[i] = pof2[i - 1] * 2 % P;
    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        ll coe = (i & 1 ? P - 1 : 1) * comb(N, i) % P * qpow(2, qpow(2, N - i, P - 1)) % P, t = 0;
        for (int j = 0; j <= i; j++) {
            (t += pof2[j * (N - i)] * F[i][j]) %= P;
        }
        (ans += coe * t) %= P;
    }
    printf("%lld\n", ans);
}
