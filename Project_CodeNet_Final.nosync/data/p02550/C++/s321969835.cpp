#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, X, M;
    cin >> N >> X >> M;
    vector<ll> as;
    set<ll> used;
    ll a = X;
    while ( true ) {
        as.push_back(a);
        used.insert(a);
        a = a * a % M;
        if ( used.count(a) > 0 ) break;
    }
    ll f = 0;
    for ( f = 0; f < as.size(); f++ ) {
        if ( as[f] == a ) break;
    }
    ll t = as.size() - f;
    ll s0 = 0, s1 = 0;
    int i;
    for ( i = 0; i < f; i++ ) {
        s0 += as[i];
    }
    for ( ; i < as.size(); i++ ) {
        s1 += as[i];
    }
    ll ans = 0;
    if ( N - f <= 0 ) {
        for ( int i = 0; i < N; i++ ) {
            ans += as[i];
        }
    } else {
        ll k = (N-f) % t;
        ans = s0 + s1 * ((N-f)/t);
        for ( int i = f; i < f+k; i++ ) {
            ans += as[i];
        }
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}