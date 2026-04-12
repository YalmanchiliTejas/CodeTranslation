# include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const int mod = 998244353;

int n, s, x, dp[N], ans;

int main() {
    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x > s) {
            continue;
        }
        if (s == x){
            ans += ((n - i + 1) * i) % mod;
            ans %= mod;
        } else {
            ans += (dp[s - x] * 1ll * (n - i + 1)) % mod;
            ans %= mod;
        }
        for (int j = s; j >= x; j--) {
            dp[j] = (dp[j - x] + dp[j] ) % mod;
        }
        dp[x] = (dp[x] + i) % mod;
    }

    cout << ans << endl;
}
