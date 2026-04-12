#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define REP(i, n) for (ll i = 0, i ## _end = n; i < i ## _end; i++)

int main() {

    ll n, t, e; cin >> n >> t >> e;
    vector<ll> x(n);
    REP(i, n) cin >> x[i];

    REP(i, n) {
        for (ll xl = 0; xl <= t+e; xl += x[i]) {
            if (t-e <= xl && xl <= t+e) {
                cout << -~i << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

}
