// sto boshi
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

namespace IO {
    template <typename _T>
    inline bool read (_T& x) {
        x = 0;
        _T y = 1;
        char c = getchar();
        while ((c < '0' || '9' < c) && c != EOF) {
            if (c == '-') y = -1;
            c = getchar();
        }
        if (c == EOF) return false;
        while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
        x *= y;
        return true;
    }

    template <typename _T>
    inline _T input () {
        _T x = 0, y = 1;
        char c = getchar();
        while ((c < '0' || '9' < c) && c != EOF) {
            if (c == '-') y = -1;
            c = getchar();
        }
        if (c == EOF) return 0;
        while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
        x *= y;
        return x;
    }
};
using namespace IO;

#define reg register
#define MAX_N 200007
#define MOD 1000000007
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define lep(i, l, r) for(int i = l; i < r; ++i)
#define irep(i, r, l) for(int i = r; i >= l; --i)
#define ilep(i, r, l) for(int i = r; i > l; --i)
typedef long long ll;

int N;
int a[MAX_N], h[MAX_N], mn[MAX_N];
int L[MAX_N], R[MAX_N];
int f[MAX_N][2][2][2];

inline int add (int x, int y) { return (x += y) >= MOD ? x - MOD : x; }

inline void inc (int &x, int y) { (x += y) >= MOD ? x -= MOD : 0; }

inline int mul (int x, int y) { return 1LL * x * y % MOD; }

inline int qpow (int x, int y) {
    int ans = 1;
    for (; y; y >>= 1, x = mul(x, x)) if (y & 1) ans = mul(ans ,x);
    return ans;
}

bool cmp (int a, int b) { return h[a] > h[b]; }

inline void update (int a[2][2][2], int g[2][2][2], int delt) {
    int f[2][2][2];
    memset(f, 0, sizeof(f));
    lep (i, 0, 2) {
        lep (j, 0, 2) {
            if (delt) {
                inc(f[i][j][0], mul(a[i][j][0], qpow(2, delt - 1)));
                inc(f[i ^ 1][j ^ 1][0], mul(a[i][j][0], qpow(2, delt - 1)));
            } else inc(f[i][j][0], a[i][j][0]);
            inc(f[i ^ (delt & 1)][j ^ (delt & 1)][1], a[i][j][1]);
        }
    }
    memmove(g, f, sizeof(f));
}

inline void merge (int a[2][2][2], int b[2][2][2], int g[2][2][2]) {
    int f[2][2][2];
    memset(f, 0, sizeof(f));
    lep (ai, 0, 2) {
        lep (aj, 0, 2) {
            lep (sa, 0, 2) if (a[ai][aj][sa]) {
                lep (bi, 0, 2) {
                    lep (bj, 0, 2) {
                        lep (sb, 0, 2) if (b[bi][bj][sb]) {
                            inc(f[ai][bj][sa | sb | (aj == bi)],
                                mul(a[ai][aj][sa], b[bi][bj][sb]));
                        }
                    }
                }
            }
        }
    }
    memmove(g, f, sizeof(f));
}

inline void solve () {
    rep (i, 1, N) {
        int x = a[i];
        if (!L[x - 1] && !R[x + 1]) {
            f[x][0][0][0] = f[x][1][1][0] = 1;
            L[x] = R[x] = x;
            mn[x] = h[x];
        } else if (!L[x - 1] && R[x + 1]) {
            update(f[x + 1], f[x + 1], mn[x + 1] - h[x]);
            f[x][0][0][0] = f[x][1][1][0] = 1;
            R[x] = R[x + 1];
            L[R[x]] = x;
            merge(f[x], f[x + 1], f[x]);
            memmove(f[R[x]], f[x], sizeof(f[x]));
            mn[x] = mn[R[x]] = h[x];
        } else if (L[x - 1] && !R[x + 1]) {
            update(f[x - 1], f[x - 1], mn[x - 1] - h[x]);
            f[x][0][0][0] = f[x][1][1][0] = 1;
            L[x] = L[x - 1];
            R[L[x]] = x;
            merge(f[x - 1], f[x], f[x]);
            memmove(f[L[x]], f[x], sizeof(f[x]));
            mn[x] = mn[L[x]] = h[x];
        } else {
            update(f[x + 1], f[x + 1], mn[x + 1] - h[x]);
            update(f[x - 1], f[x - 1], mn[x - 1] - h[x]);
            f[x][0][0][0] = f[x][1][1][0] = 1;
            merge(f[x], f[x + 1], f[x]);
            merge(f[x - 1], f[x], f[x - 1]);
            L[x] = L[x - 1], R[x] = R[x + 1];
            R[L[x]] = R[x], L[R[x]] = L[x];
            memmove(f[L[x]], f[x - 1], sizeof(f[x - 1]));
            memmove(f[R[x]], f[x - 1], sizeof(f[x - 1]));
            mn[L[x]] = mn[R[x]] = h[x];
        }
    }
    // 这里之前忘记了
    update(f[1], f[1], mn[1] - 1);
    
    int res = 0;
    lep (i, 0, 2) lep (j, 0, 2) lep (k, 0, 2) inc(res, f[1][i][j][k]);
    printf("%d\n", res);
}

int main() {
#ifdef LOCAL
    freopen("1.in", "r", stdin);
#endif
    read(N);
    rep(i, 1, N) read(h[i]), a[i] = i;
    std::sort(a + 1, a + N + 1, cmp);
    solve();
    return 0;
}
