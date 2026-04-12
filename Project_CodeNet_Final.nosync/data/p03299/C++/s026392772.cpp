#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = MOD;
const int N = 101;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
int fp(int a, int p) {
    int ans = 1, cur = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * cur);
        cur = mod(cur * cur);
    }
    return ans;
}   
void add(int &a, int b) {
    a = mod(a + b);
}
int h[N];
int dp[N][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> h[i];
    vector <int> c;
    for (int i = 0; i < n; ++i) c.push_back(h[i]);
    sort(c.begin(), c.end()); 
    c.resize(unique(c.begin(), c.end()) - c.begin());
    int r = c.size();
    c.push_back(INF);
    dp[0][r] = 2;
    int p = 2;
    for (int i = r - 1; i >= 0; --i) {
        if (c[i] <= h[0] && c[i] > 1) {
            int down = 1;
            if (i) down = c[i - 1];
            dp[0][i] = mod(fp(2, h[0] - down + 1) - p);
            add(p, dp[0][i]);
        }   
    }   
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j <= r; ++j) {
            if (dp[i][j]) {
                if (h[i + 1] <= h[i]) {
                    if (c[j] <= h[i + 1]) {
                        add(dp[i + 1][j], dp[i][j]);
                    }
                    else {
                        add(dp[i + 1][r], dp[i][j] << 1);
                    }   
                }
                else {
                    if (j == r) {
                        dp[i + 1][r] = 2;
                        int p = 2;
                        for (int k = r - 1; k >= 0; --k) {
                            if (c[k] <= h[i]) break;
                            if (c[k] <= h[i + 1]) {
                                int down = 1;
                                if (k) down = c[k - 1];
                                dp[i + 1][k] = mod(fp(2, h[i + 1] - down + 1) - p);
                                add(p, dp[i + 1][k]);
                            }   
                        }   
                        for (int k = r; k >= 0; --k) {
                            if (c[k] <= h[i]) break;
                            dp[i + 1][k] = mod(dp[i + 1][k] * dp[i][j]);
                        }   
                    }
                    else {
                        add(dp[i + 1][j], dp[i][j] * fp(2, h[i + 1] - h[i]));
                    }   
                }   
            }   
        }   
    }   
    int ans = 0;
    for (int i = 0; i <= r; ++i) add(ans, dp[n - 1][i]);
    cout << ans << '\n';
}   