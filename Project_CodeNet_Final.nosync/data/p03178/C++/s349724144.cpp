#include <bits/stdc++.h>
#define int long long
#define maxn 10005
#define maxc 105
using namespace std;

const int mod = 1e9 + 7;

//     len   sum  last
int dp[maxn][maxc][10] = {};
string s;
int n, k;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> k;
    reverse(begin(s), end(s));
    n = s.size(); s = "@" + s;
    for(int i = 0; i < 10; i++) {
        dp[1][i % k][i] = 1;
    }
    for(int len = 2; len <= n; len++) {
        for(int sum = 0; sum < k; sum++) {
            for(int last = 0; last < 10; last++) {
                int prev = (sum - last + 10 * k) % k;
                for(int i = 0; i < 10; i++)
                    dp[len][sum][last] += dp[len - 1][prev][i];
                dp[len][sum][last] %= mod;
            }
        }
    }
    int ans = 0, cnt = 0;
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < (s[i] - '0'); j++) {
            int prev = (k - cnt + 10000000LL * k) % k;
            ans += dp[i][prev][j];
        }
        ans %= mod;
        cnt += s[i] - '0';
    }
    ans = (ans - 1 + mod) % mod;
    if(cnt % k == 0) ans = (ans + 1) % mod;
    cout << ans << '\n';
    return 0;
}
