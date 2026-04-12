#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp[51], dp2[51];

ll solve(int level, ll rest) {
    if (rest == 0) return 0;
    if (level == 0) return 1;

    if (rest <= 1) return 0;
    rest--;
    if (rest == 0) return 0;
    
    ll hoge = min(rest, dp[level - 1]);
    ll res = (hoge == dp[level - 1] ? dp2[level - 1] : solve(level - 1, hoge));
    rest -= hoge;

    if (rest == 0) return res;

    rest--;
    res++;

    hoge = min(rest, dp[level - 1]);
    res += (hoge == dp[level - 1] ? dp2[level - 1] : solve(level - 1, hoge));
    rest -= hoge;

    if (rest == 0) return res;
    rest--;
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll x;
    cin >> n >> x;

    dp[0] = 1;
    dp2[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 2 * dp[i - 1] + 3;
        dp2[i] = 2 * dp2[i - 1] + 1;
    }
    cout << solve(n, x) << endl;
    return 0;
}