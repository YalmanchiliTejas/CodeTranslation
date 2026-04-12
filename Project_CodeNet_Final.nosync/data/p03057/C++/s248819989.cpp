#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
char s[200001];
long long dp[200001][2];
long long dp2[200001][2];

int main() {
    int n, m, c, i, j;
    long long ans = 0;
    vector <int> v, w;
    
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    
    for (i = 0; i < m; ) {
        for (j = i; j < m; j++) {
            if (s[i] != s[j]) break;
        }
        
        v.push_back(j - i);
        i = j;
    }
    v.back() = 1e9;
    
    c = v[0] + 1;
    for (i = 0; i < v.size(); i += 2) {
        if (v[i] % 2 == 1) c = min(c, v[i]);
    }
    
    dp[0][1] = 1;
    dp[1][1] = mod - 1;
    dp2[0][1] = 1;
    dp2[1][1] = mod - 1;
    
    for (i = 0; i <= n; i++) {
        if (i > 0) {
            for (j = 0; j < 2; j++) {
                dp[i][j] += dp[i - 1][j];
                if (dp[i][j] >= mod) dp[i][j] -= mod;
                
                dp2[i][j] += dp2[i - 1][j];
                if (dp2[i][j] >= mod) dp2[i][j] -= mod;
            }
        }
        
        if (i == 0) {
            dp[1][0] = 2;
            for (j = 2; j <= c && j <= n; j++) dp[j][0] = 1;
            if (c + 1 <= n) dp[c + 1][0] = mod - (c + 1);
        } else if (i % 2 == 1) {
            if (i + 1 <= n) {
                dp[i + 1][1] += dp[i][0];
                if (dp[i + 1][1] >= mod) dp[i + 1][1] -= mod;
            }
            
            if (i + 2 <= n) {
                dp[i + 2][1] -= dp[i][0];
                if (dp[i + 2][1] < 0) dp[i + 2][1] += mod;
            }
        } else {
            if (i + 1 <= n) {
                dp[i + 1][0] += dp[i][1];
                if (dp[i + 1][0] >= mod) dp[i + 1][0] -= mod;
            }
            
            if (i + c + 1 <= n) {
                dp[i + c + 1][0] -= dp[i][1];
                if (dp[i + c + 1][0] < 0) dp[i + c + 1][0] += mod;
            }
        }
        
        if (i == 0) {
            dp2[1][0] = 2;
            for (j = 2; j <= c && j <= n; j++) dp2[j][0] = 1;
            if (c + 1 <= n) dp2[c + 1][0] = mod - (c + 1);
        } else {
            if (i + 1 <= n) {
                dp2[i + 1][1] += dp2[i][0];
                if (dp2[i + 1][1] >= mod) dp2[i + 1][1] -= mod;
            }
            
            if (i + 2 <= n) {
                dp2[i + 2][1] -= dp2[i][0];
                if (dp2[i + 2][1] < 0) dp2[i + 2][1] += mod;
            }
            
            if (i + 1 <= n) {
                dp2[i + 1][0] += dp2[i][1];
                if (dp2[i + 1][0] >= mod) dp2[i + 1][0] -= mod;
            }
            
            if (i + c + 1 <= n) {
                dp2[i + c + 1][0] -= dp2[i][1];
                if (dp2[i + c + 1][0] < 0) dp2[i + c + 1][0] += mod;
            }
        }
    }
        
    if (n % 2 == 0) ans = dp[n][1];
    if (v.size() == 1) ans = (dp2[n][1] + 1) % mod;
    
    printf("%lld\n", ans);
    
    return 0;
}
