#include <bits/stdc++.h>

const int MAXN = 100 + 5;

const int Mod = 1e9 + 7;

int n, h[MAXN];

int sorted[MAXN];

int qpow(int a, int x) {
    int res = 1;
    for (; x > 0; x >>= 1) {
        if (x & 1) res = 1LL * res * a % Mod;
        a = 1LL * a * a % Mod;
    }
    return res;
}

std::set<std::pair<int, int>> intervals;

std::map<int, int> L_R, R_L;

int dp[MAXN][MAXN][2][2][2];

void Merge(int dp_l[2][2][2], int dp_r[2][2][2], int res[2][2][2]) {
    static int tmp[2][2][2];
    
    memset(tmp, 0, sizeof tmp);
    
    for (int l = 0; l < 2; ++l)
    for (int r = 0; r < 2; ++r) {
        for (int ll = 0; ll < 2; ++ll)
        for (int rr = 0; rr < 2; ++rr)
        for (int sl = 0; sl < 2; ++sl)
        for (int sr = 0; sr < 2; ++sr) {
            int t = sl | sr | (ll == rr);
            tmp[l][r][t] = (tmp[l][r][t] + 1LL * dp_l[l][ll][sl] * dp_r[rr][r][sr]) % Mod;
        }
    }
    
    memcpy(res, tmp, sizeof tmp);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", h + i);
        sorted[i] = i;
    }
    
    std::sort(sorted + 1, sorted + n + 1, [] (int a, int b) { return h[a] > h[b]; });
    
    for (int i = 1; i <= n; ++i) {
        int j = sorted[i], k = sorted[i - 1], t = (h[k] - h[j]) & 1;
        
        if (h[k] > h[j]) {
            for (auto e: intervals) {
                int L = e.first, R = e.second;
                
                static int tmp[2][2][2];
                for (int l = 0; l < 2; ++l)
                for (int r = 0; r < 2; ++r) {
                    tmp[l][r][1] = dp[L][R][l ^ t][r ^ t][1];
                    tmp[l][r][0] = 1LL * (dp[L][R][l][r][0] + dp[L][R][l ^ 1][r ^ 1][0]) * qpow(2, h[k] - h[j] - 1) % Mod;
                }
                
                memcpy(dp[L][R], tmp, sizeof tmp);
            }
        }
        
        static int tmp[2][2][2];
        int L = j, R = j;
        
        memset(tmp, 0, sizeof tmp);
        tmp[0][0][0] = tmp[1][1][0] = 1;
        
        if (R_L.count(j - 1)) {
            int l = R_L[j - 1], r = j - 1;
            intervals.erase(intervals.find(std::make_pair(l, r)));
            L_R.erase(L_R.find(l));
            R_L.erase(R_L.find(r));
            Merge(dp[l][r], tmp, tmp);
            L = l;
        }
        
        if (L_R.count(j + 1)) {
            int l = j + 1, r = L_R[j + 1];
            intervals.erase(intervals.find(std::make_pair(l, r)));
            L_R.erase(L_R.find(l));
            R_L.erase(R_L.find(r));
            Merge(tmp, dp[l][r], tmp);
            R = r;
        }
        
        memcpy(dp[L][R], tmp, sizeof tmp);
        intervals.insert({L, R});
        L_R.insert({L, R});
        R_L.insert({R, L});
    }
    
    if (h[sorted[n]] > 1) {
        int t = (h[sorted[n]] - 1) & 1;
        int tmp[2][2][2];
        for (int l = 0; l < 2; ++l)
        for (int r = 0; r < 2; ++r) {
            tmp[l][r][1] = dp[1][n][l ^ t][r ^ t][1];
            tmp[l][r][0] = 1LL * (dp[1][n][l][r][0] + dp[1][n][l ^ 1][r ^ 1][0]) * qpow(2, h[sorted[n]] - 1 - 1) % Mod;
        }
        
        memcpy(dp[1][n], tmp, sizeof tmp);
    }
    
    int ans = 0;
    for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    for (int k = 0; k < 2; ++k) {
        ans = (ans + dp[1][n][i][j][k]) % Mod;
    }
    printf("%d\n", ans);
    
    return 0;
}