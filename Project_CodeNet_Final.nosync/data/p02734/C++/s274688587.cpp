#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

constexpr int MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, s, ans = 0;
    cin >> n >> s;

    vll dp(s + 1, 0);

    rep(i, 0, n) {
        int a;
        cin >> a;
        ++dp[0];
        if (s >= a) { ans = (ans + dp[s - a] * (n - i)) % MOD; }
        rrep(j, 0, s - a) { dp[j + a] = (dp[j + a] + dp[j]) % MOD; }
    }
    cout << ans << endl;

    return 0;
}