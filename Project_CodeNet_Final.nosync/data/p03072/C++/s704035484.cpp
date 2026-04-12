#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    cin >> N;
    vector<ll> H(N);
    for (ll i = 0; i < N; i++) {
        cin >> H[i];
    }

    ll ans = 0, h = 0;
    for (ll i = 0; i < N; i++) {
        if (H[i] >= h) {
            ans++;
            h = H[i];
        }
    }

    cout << ans << endl;
}