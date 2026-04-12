#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    while (true) {
        ll max_index = max_element(a.begin(), a.end()) - a.begin();
        if (a[max_index] < N) {
            break;
        }

        ll diff = a[max_index] - (N - 1);
        ll num = (diff + N - 1) / N;
        ans += num;
        a[max_index] -= num * N;
        for (ll i = 0; i < N; i++) {
            if (i == max_index) {
                continue;
            }
            a[i] += num;
        }
    }

    cout << ans << endl;
}