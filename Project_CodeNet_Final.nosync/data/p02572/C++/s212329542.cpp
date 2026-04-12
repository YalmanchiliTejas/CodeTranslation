#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define M 1000000007

int main() {

    int n;
    cin >> n;
    vector<ll> a(n, 0);

    ll out = 0;
    ll total = 0;

    rep(i, n) {
        cin >> a[i];
        total += a[i];
        total %= M;
    }

    rep(i, n) {
        total -= a[i];
        if (total < 0) total += M;
        out += ((a[i] * total) % M);
        out %= M;
    }

    cout << out;

    return 0;
}