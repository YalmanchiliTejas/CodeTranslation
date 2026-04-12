#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    ll hi = 1e18, lo = -1;
    while (lo + 1 < hi) {
        ll mi = (lo + hi) / 2, s = 0;
        //cout << mi << "\n";
        rep(i, N) {
            s += (a[i] + mi + 1) / (N + 1);
        }
        if (s <= mi) hi = mi;
        else lo = mi;
    }
    for (ll i = max(0LL, hi - 100000); i <= hi; i++) {
        //cout << i << "\n";
        ll s = 0;
        rep(j, N) {
            s += (a[j] + i + 1) / (N + 1);
        }
        if (s <= i) {
            cout << i << "\n";
            return 0;
        }
    }
}