#include <bits/stdc++.h>

using ll = unsigned long long;
const int maxn = 503, must0 = 1, must1 = 2, rat0 = 4, rat1 = 8, cat0 = 16, cat1 = 32, rmust0 = 64, rmust1 = 128, cmust0 = 256, cmust1 = 512;

int n;
ll s[maxn], t[maxn], u[maxn], v[maxn], b[64][maxn][maxn], a[maxn][maxn], rat0c[64][maxn], cat0c[64][maxn];
bool vis[64][maxn][maxn], rs[64][maxn], cs[64][maxn];

bool check() {
    for(int i = 0; i < n; ++i) {
        if(s[i] == 0) {
            ll rd = a[i][0];
            for(int j = 1; j < n; ++j)
                rd &= a[i][j];
            if(rd != u[i])
                return false;
        } else {
            ll rd = a[i][0];
            for(int j = 1; j < n; ++j)
                rd |= a[i][j];
            if(rd != u[i])
                return false;
        }
    }
    for(int j = 0; j < n; ++j) {
        if(t[j] == 0) {
            ll rd = a[0][j];
            for(int i = 1; i < n; ++i)
                rd &= a[i][j];
            if(rd != v[j])
                return false;
        } else {
            ll rd = a[0][j];
            for(int i = 1; i < n; ++i)
                rd |= a[i][j];
            if(rd != v[j])
                return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%llu", s + i);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%llu", t + i);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%llu", u + i);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%llu", v + i);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < 64; ++k) {
                if(s[i]) {
                    if((u[i] & (1ll << k)) == 0)
                        b[k][i][j] |= must0 | rmust0;
                    else
                        b[k][i][j] |= rat1;
                } else {
                    if((u[i] & (1ll << k)) != 0)
                        b[k][i][j] |= must1 | rmust1;
                    else
                        b[k][i][j] |= rat0;
                }
                if(t[j]) {
                    if((v[j] & (1ll << k)) == 0)
                        b[k][i][j] |= must0 | cmust0;
                    else
                        b[k][i][j] |= cat1;
                } else {
                    if((v[j] & (1ll << k)) != 0)
                        b[k][i][j] |= must1 | cmust1;
                    else
                        b[k][i][j] |= cat0;
                }
            }
        }
    }
    for(int k = 0; k < 64; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                const auto &w = b[k][i][j];
                if((w & must1) && (w & must0)) {
                    puts("-1");
                    return 0;
                }
                if(w & must1) {
                    vis[k][i][j] = true;
                    a[i][j] |= 1ll << k;
                    if(w & (rmust1 | rat1))
                        rs[k][i] = true;
                    if(w & (cmust1 | cat1))
                        cs[k][j] = true;
                    continue;
                }
                if(w & must0) {
                    vis[k][i][j] = true;
                    if(w & (rmust0 | rat0))
                        rs[k][i] = true;
                    if(w & (cmust0 | cat0))
                        cs[k][j] = true;
                    continue;
                }
                if((w & rat1) && (w & cat1)) {
                    vis[k][i][j] = true;
                    a[i][j] |= 1ll << k;
                    rs[k][i] = cs[k][j] = true;
                    continue;
                }
                if((w & rat0) && (w & cat0)) {
                    vis[k][i][j] = true;
                    rs[k][i] = cs[k][j] = true;
                    continue;
                }
            }
        }
    }
    for(int k = 0; k < 64; ++k) {
        for(int i = 0, jc = 0; i < n; ++i) {
            if(rs[k][i] || (b[k][i][0] & rat0))
                continue;
            for(int _ = 0; _ < n; ++_) {
                const auto &w = b[k][i][jc];
                if(vis[k][i][jc]) {
                    jc = (jc == n - 1) ? 0 : jc + 1;
                    continue;
                }
                if((w & rat1) && (w & cat0) && (cs[k][jc] || cat0c[k][jc] < n)) {
                    vis[k][i][jc] = true;
                    cat0c[k][jc] += 1;
                    a[i][jc] |= 1ll << k;
                    rs[k][i] = true;
                    jc = (jc == n - 1) ? 0 : jc + 1;
                    break;
                }
                jc = (jc == n - 1) ? 0 : jc + 1;
            }
        }
    }
    for(int k = 0; k < 64; ++k) {
        for(int j = 0, ic = 0; j < n; ++j) {
            if(cs[k][j] || (b[k][0][j] & cat0))
                continue;
            for(int _ = 0; _ < n; ++_) {
                const auto &w = b[k][ic][j];
                if(vis[k][ic][j]) {
                    ic = (ic == n - 1) ? 0 : ic + 1;
                    continue;
                }
                if((w & rat0) && (w & cat1) && (rs[k][ic] || rat0c[k][ic] < n)) {
                    vis[k][ic][j] = true;
                    rat0c[k][ic] += 1;
                    a[ic][j] |= 1ll << k;
                    cs[k][j] = true;
                    ic = (ic == n - 1) ? 0 : ic + 1;
                    break;
                }
                ic = (ic == n - 1) ? 0 : ic + 1;
            }
        }
    }
    if(!check()) {
        puts("-1");
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("%llu%c", a[i][j], " \n"[j == n - 1]);
        }
    }
    return 0;
}