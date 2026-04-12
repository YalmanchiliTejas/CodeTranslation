#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 3;
const int N = 2e5 + 3;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

const double PI = acos(-1);



void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    auto sum = accumulate(a, a + n, 0ll), ans = 0ll;
    long long suf[n];
    for (int i = n - 1; i >= 0; i--)
        suf[i] = (i == n - 1 ? a[i] : suf[i + 1] + a[i]);
    for (int i = 0; i < n - 1; i++) {
        auto val = suf[i + 1] % MOD;
        ans += (val * a[i]) % MOD;
        ans %= MOD;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}