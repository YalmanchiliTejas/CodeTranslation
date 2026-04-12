#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> h,p;

ll patty(int n, ll x) {
    if ( n == 0 ) return x;
    ll r = 0;
    if ( x <= 1 ) {
    } else if ( x <= 1 + h[n-1] ) {
        r += patty(n-1, x-1);
    } else if ( x == 2 + h[n-1] ) {
        r += p[n-1] + 1;
    } else if ( x <= 2 + h[n-1]*2 ) {
        r += p[n-1] + 1 + patty(n-1, x - h[n-1] - 2);
    } else {
        r += p[n-1]*2 + 1;
    }
    return r;
}

int main() {
    ll N, X;
    cin >> N >> X;
    h.resize(N+1);
    p.resize(N+1);
    h[0] = 1;
    p[0] = 1;
    for ( int i = 1; i <= N; i++ ) {
        h[i] = 2*h[i-1]+3;
        p[i] = 2*p[i-1]+1;
    }
    ll ans = patty(N, X);
    cout << ans << '\n';
    return 0;
}