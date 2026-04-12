#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < (int)N; ++i)

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];

    ll ans = 0;
    for (int c = 1; c <= n - 1; ++c) {
        ll score = 0;
        vector<bool> used(n, false);
        for (int i = 0; i < n - 1; i += c) {
            if (n - 1 - i - c <= 0) break;
            if (used[i] || used[n - 1 - i] || i == n - 1 - i) break;
            score += ll(s[i]) + s[n - 1 - i];
            used[i] = used[n - 1 - i] = true;
            ans = max(ans, score);
        }
    }
    cout << ans << endl;
}
