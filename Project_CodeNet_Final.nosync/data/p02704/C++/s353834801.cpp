#include <stdio.h>
#include <string.h>

unsigned long long u[510], v[510], r[510][510];
int c[510][510][64];
int s[510], t[510], n;
int p[510][64], q[510][64];

void init() {
    memset(c, -1, sizeof(c));
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &s[i]);
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    for (int i = 0; i < n; i++) scanf("%llu", &u[i]);
    for (int i = 0; i < n; i++) scanf("%llu", &v[i]);
}

void setDeterminedBit() {
    int i, j, k;
    for (i = 0; i < n; i++) {
        if (s[i] == 0) {
            for (k = 0; k < 64; k++) {
                if (u[i] & (1llu<<k)) {
                    p[i][k] = -1;
                    for (j = 0; j < n; j++) c[i][j][k] = 1;
                } else {
                    p[i][k] = 0;
                }
            }
        } else {
            for (k = 0; k < 64; k++) {
                if ((u[i] & (1llu<<k)) == 0) {
                    p[i][k] = -1;
                    for (j = 0; j < n; j++) c[i][j][k] = 0;
                } else {
                    p[i][k] = 1;
                }
            }
        }
        if (t[i] == 0) {
            for (k = 0; k < 64; k++) {
                if (v[i] & (1llu<<k)) {
                    q[i][k] = -1;
                    for (j = 0; j < n; j++) c[j][i][k] = 1;
                } else {
                    q[i][k] = 0;
                }
            }
        } else {
            for (k = 0; k < 64; k++) {
                if ((v[i] & (1llu<<k)) == 0) {
                    q[i][k] = -1;
                    for (j = 0; j < n; j++) c[j][i][k] = 0;
                } else {
                    q[i][k] = 1;
                }
            }
        }
    }
}

void fullFillSet(int k) {
    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j][k] < 0) {
                if (x < 0) {
                    x = i; y = j;
                    c[i][j][k] = 0;
                } else if (i == x || j == y) c[i][j][k] = 1;
                else c[i][j][k] = 0;
            }
        }
    }
}

bool checkP(int i, int k) {
    if (p[i][k] < 0) return true;
    for (int j = 0; j < n; j++) if (c[i][j][k] == p[i][k]) return true;
    return false;
}

bool checkQ(int j, int k) {
    if (q[j][k] < 0) return true;
    for (int i = 0; i < n; i++) if (c[i][j][k] == q[j][k]) return true;
    return false;
}

void setRestBit() {
    for (int k = 0; k < 64; k++) {
        int numP = 0, numQ = 0;
        for (int i = 0; i < n; i++) {
            if (p[i][k] >= 0) numP++;
            if (q[i][k] >= 0) numQ++;
        }
        if (numP == 0 || numQ == 0) continue;
        if (numP > 1 && numQ > 1) {
            fullFillSet(k);
            continue;
        }
        if (numP == 1) {
            int i, j;
            for (i = 0; i < n; i++) if (p[i][k] >= 0) break;
            for (j = 0; j < n; j++) {
                if (c[i][j][k] >= 0) continue;
                if (checkQ(j, k)) c[i][j][k] = p[i][k];
                else c[i][j][k] = q[j][k];
            }
        } else {
            int i, j;
            for (j = 0; j < n; j++) if (q[j][k] >= 0) break;
            for (i = 0; i < n; i++) {
                if (c[i][j][k] >= 0) continue;
                if (checkP(i, k)) c[i][j][k] = q[j][k];
                else c[i][j][k] = p[i][k];
            }
        }
    }
}

void solve() {
    setDeterminedBit();
    setRestBit();
}

void build() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            unsigned long long x = 0;
            for (int k = 0; k < 64; k++) {
                if (c[i][j][k]) x |= 1llu<<k;
            }
            r[i][j] = x;
        }
    }
}

bool check() {
    for (int i = 0; i < n; i++) {
        unsigned long long x = r[i][0];
        for (int j = 1; j < n; j++) {
            if (s[i] == 0) x &= r[i][j];
            else x |= r[i][j];
        }
        if (x != u[i]) return false;
    }
    for (int j = 0; j < n; j++) {
        unsigned long long x = r[0][j];
        for (int i = 1; i < n; i++) {
            if (t[j] == 0) x &= r[i][j];
            else x |= r[i][j];
        }
        if (x != v[j]) return false;
    }
    return true;
}

void output() {
    if (!check()) {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%llu%c", r[i][j], (j==n-1)?'\n':' ');
        }
    }
}

int main() {
    int i, j, k;
    init();
    input();
    solve();
    build();
    output();
    return 0;
}
