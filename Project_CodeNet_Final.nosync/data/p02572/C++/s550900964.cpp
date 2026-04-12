#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < n; i++)

void solve();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(void) {
    init();
    solve();
    return 0;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    ll partialSum = 0;
    ll sum = 0;
    rep(i, n) {
        sum += a[i] * partialSum;
        partialSum += a[i];
        sum %= 1000000007;
        partialSum %= 1000000007;
    }
    cout << sum % 1000000007 << "\n";
}
