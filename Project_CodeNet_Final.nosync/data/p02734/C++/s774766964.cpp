#include <bits/stdc++.h>
using namespace std;

int binpow(int n, int k) {
    if (k == 0) return 1;
    if (k == 1) return n;
    if (k % 2 == 0) {
        int nn = binpow(n, k / 2);
        return nn*nn;
    }
    if (k % 2 == 1) {
        return n * binpow(n, k - 1);
    }
}

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    vector<long long> dp(s), dp1(s);
    long long res = 0;
    long long mod = 998244353;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < s; i++) {
        dp[i] = 0;
        dp1[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == s) {
            res += (i + 1) * (n - i);
            continue;
        }
        if (v[i] > s) continue;
        for (int j = 0; j < s; j++) {
            if (j + v[i] == s) {
                res += dp[j] * (n - i);
                res %= mod;
            }
            if (j + v[i] < s) {
                dp1[j + v[i]] += dp[j];
                dp1[j + v[i]] %= mod;
            }
        }
        dp1[v[i]] += i + 1;
        dp1[v[i]] %= mod;
        for (int j = 0; j < s; j++) {
            dp[j] += dp1[j];
            dp1[j] = 0;
            dp[j] %= mod;
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
