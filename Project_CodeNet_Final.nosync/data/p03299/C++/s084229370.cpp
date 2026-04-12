#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = (int) 1e5 + 5;

const int MOD = (int)1e9 + 7;

int n, h[MAXN], sorted[MAXN];

int qpow(int a, int x) {
    int res = 1;
    for (; x > 0; x >>= 1) {
        if (x & 1)
            res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
    }
    return res;
}

bool added[MAXN];
int R_L[MAXN], L_R[MAXN];

int dp[MAXN][2][2][2];
int last_h[MAXN];

void merge(int dp_l[2][2][2], int dp_r[2][2][2], int res[2][2][2]) {
    int tmp[2][2][2];
    
    memset(tmp, 0, sizeof tmp);
    
    for (int l = 0; l < 2; ++l)
    for (int r = 0; r < 2; ++r) {
        for (int ll = 0; ll < 2; ++ll)
        for (int rr = 0; rr < 2; ++rr)
        for (int sl = 0; sl < 2; ++sl)
        for (int sr = 0; sr < 2; ++sr) {
            int t = sl | sr | (ll == rr);
            tmp[l][r][t] = (tmp[l][r][t] + 1LL * dp_l[l][ll][sl] * dp_r[rr][r][sr]) % MOD;
        }
    }
    
    memcpy(res, tmp, sizeof tmp);
}

void calc(int L, int h_now) {
    if (last_h[L] == h_now) {
        return;
    }
    
    int tmp[2][2][2];
    int t = (last_h[L] - h_now) & 1;

    for (int l = 0; l < 2; ++l)
    for (int r = 0; r < 2; ++r) {
        tmp[l][r][1] = dp[L][l ^ t][r ^ t][1];
        tmp[l][r][0] = 1LL * (dp[L][l][r][0] + dp[L][l ^ 1][r ^ 1][0]) * qpow(2, last_h[L] - h_now - 1) % MOD;
    }

    memcpy(dp[L], tmp, sizeof tmp);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", h + i);
        sorted[i] = i;
    }
    
    std::sort(sorted + 1, sorted + n + 1, [&] (int a, int b) {
        return h[a] > h[b];
    });

    for (int i = 1; i <= n; ++i) {
        int j = sorted[i];

        int tmp[2][2][2];
        int L = j, R = j;

        memset(tmp, 0, sizeof tmp);
        tmp[0][0][0] = tmp[1][1][0] = 1;

        if (R_L[j - 1]) {
            int l = R_L[j - 1], r = j - 1;
            L_R[l] = R_L[r] = 0;
            calc(l, h[j]);
            merge(dp[l], tmp, tmp);
            L = l;
        }

        if (L_R[j + 1]) {
            int l = j + 1, r = L_R[j + 1];
            L_R[l] = R_L[r] = 0;
            calc(l, h[j]);
            merge(tmp, dp[l], tmp);
            R = r;
        }

        added[j] = true;
        memcpy(dp[L], tmp, sizeof tmp);
        L_R[L] = R;
        R_L[R] = L;
        last_h[L] = h[j];
    }

    if (h[sorted[n]] > 1) {
        int t = (h[sorted[n]] - 1) & 1;
        int tmp[2][2][2];

        for (int l = 0; l < 2; ++l)
        for (int r = 0; r < 2; ++r) {
            tmp[l][r][1] = dp[1][l ^ t][r ^ t][1];
            tmp[l][r][0] = 1LL * (dp[1][l][r][0] + dp[1][l ^ 1][r ^ 1][0]) * qpow(2, h[sorted[n]] - 1 - 1) % MOD;
        }
        
        memcpy(dp[1], tmp, sizeof tmp);
    }

    int ans = 0;
    for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    for (int k = 0; k < 2; ++k) {
        ans = (ans + dp[1][i][j][k]) % MOD;
    }

    printf("%d\n", ans);

    return 0;
}