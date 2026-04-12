#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    lint n;
    cin >> n;
    vector<lint> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    lint ret = 0;
    if (n % 2 == 0) {
        lint e = 0, o = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0)
                e += a[i];
            else
                o += a[i];
        }
        ret = max(e, o);
    } else {
        lint o = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 1)
                o += a[i];
        }
        ret = o;
    }
    vector<vector<lint>> dp(n + 2, vector<lint>(3, -inf));
    a.insert(a.begin(), 0);
    a.push_back(0);
    dp[0][0] = a[0];
    dp[1][0] = a[1];
    for (int i = 2; i <= n + 1; ++i) {
        chmax(dp[i][0], dp[i - 2][0] + a[i]);
        chmax(dp[i][1], dp[i - 2][1] + a[i]);
        chmax(dp[i][2], dp[i - 2][2] + a[i]);
        if (i >= 3) {
            chmax(dp[i][1], dp[i - 3][0] + a[i]);
            chmax(dp[i][2], dp[i - 3][1] + a[i]);
        }
        if (i >= 4) {
            chmax(dp[i][2], dp[i - 4][0] + a[i]);
        }
    }
    if (n % 2 == 0)
        chmax(ret, dp[n][1]);
    else {
        chmax(ret, max({dp[n - 1][1], dp[n][1], dp[n][2]}));
    }
    cout << ret << "\n";
    return 0;
}