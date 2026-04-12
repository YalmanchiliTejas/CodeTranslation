#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int mod = 1e9 + 7;

typedef long long LL;

char s[N];

int f[N], g[N], dp[2][2][N];

int main() {
    int n, m; scanf("%d%d%s", &n, &m, s + 1);
    bool flag = false;
    for (int i = 1; i <= m; i++) if (s[i] != s[1]) {
        flag = true; break;
    } 
    if (flag) {
        if (n & 1) return puts("0"), 0;
        int fir = 0;
        for (int i = 1; i <= m; i++) if (s[i] != s[1]) {
            fir = i - 1; break;
        }
        int lim = fir | 1;
        for (int i = fir + 1; i <= m; i++) if (s[i] != s[1]) {
            int j = i + 1;
            while (j <= m && s[j] == s[1]) j++;
            if (j <= m && (j - i - 1) % 2 == 1) lim = min(lim, j - i - 1); 
        } 
        n /= 2, lim = (lim + 1) / 2;
        for (int i = 1; i <= lim; i++) f[i] = i * 2;
        for (int i = 1, diff = 0; i <= n; i++) {
            diff = (diff + g[i]) % mod, f[i] = (f[i] + diff) % mod;
            if (i + 1 <= n) g[i + 1] = (g[i + 1] + f[i]) % mod;
            if (i + lim + 1 <= n) g[i + lim + 1] = (g[i + lim + 1] - f[i] + mod) % mod;
        }
        printf("%d\n", f[n]);
    } else {
        dp[1][1][1] = dp[0][0][1] = 1;
        for (int i = 2; i <= n; i++) 
            for (int t = 0; t <= 1; t++) {
                dp[t][0][i] = (dp[t][1][i - 1] + dp[t][0][i - 1]) % mod;
                dp[t][1][i] = dp[t][0][i - 1];
            }
        printf("%d\n", ((LL)dp[1][0][n] + dp[0][0][n] + dp[0][1][n]) % mod);
    }
    return 0;
}//