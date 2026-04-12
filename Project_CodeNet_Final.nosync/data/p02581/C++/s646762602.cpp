#include<bits/stdc++.h>
using namespace std;
const int N = 2000 + 5;
struct Node {
    int x, y;
} up[N << 4];
int a[N * 3], n, m, ans, MAX;
int f[N][N], p[N], S[N], L[N][N];
int b[4];
inline int read () {
    int tot = 0, f = 1; char c = getchar ();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar (); }
    while (c >= '0' && c <= '9') { tot = tot * 10 + c - '0'; c = getchar (); }
    return tot * f;
}
inline int chkmax (int &a, int b) { return a = max (a, b); }
signed main () {
    n = read ();
    for (int i = 1; i <= 3 * n; i++) a[i] = read ();
    for (int i = 1; i < n; i++) {
        int psi = 2 + (i - 1) * 3;
        if (a[psi + 1] == a[psi + 2] && a[psi + 2] == a[psi + 3]) ans++, p[i] = 1;
    }
    memset (f, -0x3f, sizeof (f)); memset (S, -0x3f, sizeof (S)); memset (L, -0x3f, sizeof (L));
    L[a[1]][a[2]] = L[a[2]][a[1]] = f[a[1]][a[2]] = f[a[2]][a[1]] = S[a[1]] = S[a[2]] = 0;
    for (int i = 1; i < n; i++) {
        if (p[i]) continue;
        m = 0; int psi = 2 + (i - 1) * 3;
        f[a[psi + 1]][a[psi + 2]] = chkmax (f[a[psi + 2]][a[psi + 1]], max (MAX, L[a[psi + 3]][a[psi + 3]] + 1));
        f[a[psi + 1]][a[psi + 3]] = chkmax (f[a[psi + 3]][a[psi + 1]], max (MAX, L[a[psi + 2]][a[psi + 2]] + 1));
        f[a[psi + 2]][a[psi + 3]] = chkmax (f[a[psi + 3]][a[psi + 2]], max (MAX, L[a[psi + 1]][a[psi + 1]] + 1));
        up[++m].x = a[psi + 1]; up[m].y = a[psi + 2];
        up[++m].x = a[psi + 1]; up[m].y = a[psi + 3];
        up[++m].x = a[psi + 2]; up[m].y = a[psi + 3];
        b[1] = a[psi + 1]; b[2] = a[psi + 2]; b[3] = a[psi + 3];
        sort (b + 1, b + 4); int A = b[1], B = b[2], C = b[3];
        if (B == C) swap (C, A);
        for (int j = 1; j <= n; j++) {
            if (S[j] < 0) continue;
            up[++m].x = j; up[m].y = A; up[++m].x = j; up[m].y = B; up[++m].x = j; up[m].y = C;
            f[A][j] = chkmax (f[j][A], S[j]);
            f[B][j] = chkmax (f[j][B], S[j]);
            f[C][j] = chkmax (f[j][C], S[j]);
        }
        if (A == B) {
            for (int j = 1; j <= n; j++)
            if (L[A][j] >= 0) {
                up[++m].x = j; up[m].y = C;
                f[C][j] = chkmax (f[j][C], L[A][j] + 1);
            }
        }
        for (int j = 1; j <= m; j++) {
            int x = up[j].x, y = up[j].y;
            L[x][y] = L[y][x] = f[x][y];
            MAX = max (MAX, f[x][y]);
            S[x] = max (S[x], f[x][y]); S[y] = max (S[y], f[y][x]);
        }
    }
    printf ("%d\n", max (MAX, f[a[n * 3]][a[n * 3]] + 1) + ans);
    return 0;
}
