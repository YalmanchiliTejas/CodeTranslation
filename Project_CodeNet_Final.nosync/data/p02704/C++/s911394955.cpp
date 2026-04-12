#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 500;
const int M = 64;

int n;
int S[N], T[N];
ull U[N], V[N];
ull ans[N][N];

int mat[M][N][N];
int sr[N], sc[N];

int pt(int t, ull v, int k) {
    return (t << 1) | ((v & (1llu << k)) ? 1 : 0);
}

void fill(int k) {
    for (int r = 0; r < n; ++r) {
        if (pt(S[r], U[r], k) == 1) {
            for (int c = 0; c < n; ++c) {
                mat[k][r][c] = 1;
            }
        }
    }

    for (int c = 0; c < n; ++c) {
        if (pt(T[c], V[c], k) == 1) {
            for (int r = 0; r < n; ++r) {
                mat[k][r][c] = 1;
            }
        }
    }

    memset(sr, 0, sizeof(sr));
    memset(sc, 0, sizeof(sc));

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            sr[r] += mat[k][r][c];
            sc[c] += mat[k][r][c];
        }
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            // OR1 OR1
            if (pt(S[r], U[r], k) == 3 && pt(T[c], V[c], k) == 3) {
                mat[k][r][c] = 1;
                ++sr[r]; ++sc[c];
            } else 
            // AND0 OR1
            if (pt(S[r], U[r], k) == 0 && pt(T[c], V[c], k) == 3) {
                if (mat[k][r][c] == 0 && sc[c] == 0 && sr[r] < n - 1) {
                    mat[k][r][c] = 1;
                    ++sr[r]; ++sc[c];
                }
            } else
            // OR1 AND0
            if (pt(S[r], U[r], k) == 3 && pt(T[c], V[c], k) == 0) {
                if (mat[k][r][c] == 0 && sr[r] == 0 && sc[c] < n - 1) {
                    mat[k][r][c] = 1;
                    ++sr[r]; ++sc[c];
                }
            }
        }
    }
}

void cal() {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            for (int k = M - 1; k >= 0; --k) {
                ans[r][c] = (ans[r][c] << 1) | mat[k][r][c];
            }
        }
    }
}

bool check() {
    for (int r = 0; r < n; ++r) {
        ull v = ans[r][0];
        for (int c = 1; c < n; ++c) {
            v = S[r] == 0 ? (v & ans[r][c]) : (v | ans[r][c]);
        }
        if (v != U[r]) {
            return false;
        }
    }

    for (int c = 0; c < n; ++c) {
        ull v = ans[0][c];
        for (int r = 1; r < n; ++r) {
            v = T[c] == 0 ? (v & ans[r][c]) : (v | ans[r][c]); 
        }
        if (v != V[c]) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &S[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &T[i]);
    for (int i = 0; i < n; ++i) scanf("%llu", &U[i]);
    for (int i = 0; i < n; ++i) scanf("%llu", &V[i]);

    for (int k = 0; k < M; ++k) {
        fill(k);
    }

    cal();

    if (check()) {
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                printf("%llu%c", ans[r][c], c == n - 1 ? '\n' : ' ');
            }
        }
    } else {
        printf("-1");
    }

    return 0;
}