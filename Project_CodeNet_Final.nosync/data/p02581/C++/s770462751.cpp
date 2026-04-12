#include <bits/stdc++.h>

const int maxn = 2e3 + 13;

int n, a[maxn * 3], dp[maxn][maxn], mxdp, rmx[maxn], cmxdp, crmx[maxn], dpu[maxn];

void Max(int i, int j, int v) {
    int &u = dp[i][j];
    if(v > u)
        u = v;
    dp[j][i] = u;
    rmx[i] = std::max(rmx[i], u);
    rmx[j] = std::max(rmx[j], u);
    mxdp = std::max(mxdp, v);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n * 3; ++i) {
        scanf("%d", a + i);
        a[i] -= 1;
    }
    a[n * 3] = n;
    a[n * 3 + 1] = n;
    memset(dp, 0x80, sizeof(dp));
    memset(rmx, 0x80, sizeof(rmx));
    dp[a[0]][a[1]] = dp[a[1]][a[0]] = 0;
    rmx[a[0]] = rmx[a[1]] = 0;
    mxdp = 0;
    int extra = 0;
    for(int i = 5; i <= 3 * n + 2; i += 3) {
        cmxdp = mxdp;
        memcpy(crmx, rmx, sizeof(*rmx) * (n + 1));
        std::map<int, int> c;
        for(int k = 3; k > 0; --k)
            c[a[i - k]] += 1;
        int u = a[i - 3], v = a[i - 2], w = a[i - 1];
        if(c.size() >= 3) {
            int dpuu = dp[u][u], dpvv = dp[v][v], dpww = dp[w][w];
            for(int j = 0; j <= n; ++j) {
                Max(u, j, crmx[j]);
                Max(v, j, crmx[j]);
                Max(w, j, crmx[j]);
            }
            Max(v, w, std::max({cmxdp, dpuu + 1}));
            Max(u, w, std::max({cmxdp, dpvv + 1}));
            Max(u, v, std::max({cmxdp, dpww + 1}));
        } else if(c.size() >= 2) {
            if(v == w) {
                std::swap(u, w);
            } else if(u == w) {
                std::swap(v, w);
            }
            int dpuu = dp[u][u], dpww = dp[w][w];
            for(int j = 0; j <= n; ++j) {
                dpu[j] = dp[u][j];
            }
            Max(u, u, std::max({cmxdp, dpww + 1}));
            Max(u, w, std::max({cmxdp, dpuu + 1}));
            for(int j = 0; j <= n; ++j) {
                Max(u, j, crmx[j]);
                Max(w, j, std::max({crmx[j], dpu[j] + 1}));
            }
        } else {
            extra += 1;
            Max(v, v, cmxdp - 1);
            for(int j = 0; j <= n; ++j) {
                Max(j, v, crmx[j] - 1);
            }
        }
    }
    printf("%d\n", mxdp + extra);
    return 0;
}