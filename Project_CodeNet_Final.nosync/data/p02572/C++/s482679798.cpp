#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repp(i, a, n) for(ll i = a; i < (ll)(n); i++)
#define repd(i, n) for(ll i = n - 1; i >= 0; i--)
#define all(x) x.begin(), x.end()

ll k, l, m, n;
const int M = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    m = (ll)M;

    vl a(n);
    rep(i, n) cin >> a[i];

    vl b(n - 1);
    b[n - 2] = a[n - 1];
    repd(i, n - 2) {
        b[i] = b[i + 1] + a[i + 1];
        if(b[i] > m) b[i] -= m;
    }

    ll sum = 0;
    rep(i, n - 1) {
        sum += a[i] * b[i];
        if(sum > m) sum %= m;
    }

    cout << sum << endl;
}