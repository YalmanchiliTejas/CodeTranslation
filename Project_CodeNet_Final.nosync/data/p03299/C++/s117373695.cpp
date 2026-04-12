#include <bits/stdc++.h>
using namespace std;
constexpr int P = 1E9 + 7;
int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = 1LL * result * base % P;
        base = 1LL * base * base % P;
        exp >>= 1;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    function<array<int, 2>(int, int, int)> calc = [&](int l, int r, int low) {
        if (l == r)
            return array<int, 2>{1, 0};
        int mn = 1E9;
        array<int, 2> dp {1, 1};
        for (int i = l; i < r; ++i)
            mn = min(mn, h[i]);
        int x = l, cnt = 0;
        for (int i = l; i < r; ++i) {
            if (h[i] == mn) {
                auto f = calc(x, i, mn);
                x = i + 1;
                ++cnt;
                dp[0] = 1LL * dp[0] * f[0] % P;
                dp[1] = 1LL * dp[1] * (f[0] + f[1]) % P;
            }
        }
        auto f = calc(x, r, mn);
        dp[0] = 1LL * dp[0] * f[0] % P;
        dp[1] = 1LL * dp[1] * (f[0] + f[1]) % P;
        int tmp = power(2, mn - low);
        dp[1] = (1LL * power(2, cnt) * dp[1] + 1LL * (tmp - 2 + P) * dp[0]) % P;
        dp[0] = 1LL * tmp * dp[0] % P;
        return dp;
    };
    cout << calc(0, n, 0)[1] << endl;
    return 0;
}