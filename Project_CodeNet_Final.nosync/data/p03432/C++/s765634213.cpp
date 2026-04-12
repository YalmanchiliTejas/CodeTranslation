#include <bits/stdc++.h>
using namespace std;

const int N = 8010;
const int M = 210;
const int mod = 998244353;

typedef long long LL;

inline int Pow(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = (LL)x * x % mod) if (y & 1) res = (LL)res * x % mod;
    return res;
}

int frac[N], inv[N];

inline int C(int n, int r) {
    return (LL)frac[n] * inv[r] % mod * inv[n - r] % mod;
}

int dp[M][N];

int r[N << 2], A[N << 2], B[N << 2];

inline void NTT(int a[], int len, int type) {
    for (int i = 1; i < len; i++) if (i < r[i]) swap(a[i], a[r[i]]);
    for (int mid = 2; mid <= len; mid <<= 1) {
        int Wn = Pow(3, type ? (mod - 1) / mid : mod - 1 - (mod - 1) / mid);
        for (int i = 0; i < len; i += mid)
            for (int j = i, w = 1, t; j < i + (mid >> 1); j++, w = (LL)w * Wn % mod)
                t = (LL)a[j + (mid >> 1)] * w % mod, a[j + (mid >> 1)] = (a[j] - t + mod) % mod, a[j] = (a[j] + t) % mod;
    }
    if (!type) for (int i = 0, inv = Pow(len, mod - 2); i < len; i++)
        a[i] = (LL)a[i] * inv % mod;
}

int main() {
    int n, m; cin >> n >> m;
    frac[0] = inv[0] = 1;
    for (int i = 1; i <= n + 2; i++) 
        frac[i] = (LL)frac[i - 1] * i % mod, inv[i] = Pow(frac[i], mod - 2);
    int len = 1, l = 0;
    while (len <= n * 2) len <<= 1, l++;
    for (int i = 1; i < len; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << l - 1);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) B[i] = inv[i + 2];
    NTT(B, len, 1);
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < len; j++) A[j] = 0;
        for (int j = 0; j <= n; j++) A[j] = (LL)dp[i - 1][j] * inv[j] % mod;
        NTT(A, len, 1);
        for (int j = 0; j < len; j++) A[j] = (LL)A[j] * B[j] % mod;
        NTT(A, len, 0);
        for (int j = 0; j <= n; j++) 
            dp[i][j] = ((LL)frac[j + 2] * A[j] + (LL)dp[i - 1][j] * (1 + C(j + 1, 2))) % mod;
    }
    int res = 0;
    for (int i = 0; i <= n; i++) res = (res + (LL)dp[m][i] * C(n, i)) % mod;
    cout << res << endl;
    return 0;
}
