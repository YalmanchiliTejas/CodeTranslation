#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vll a, p;

ll f(ll n, ll x) {
    if (n == 0) {
        return (x <= 0 ? 0 : 1);
    } else if (x <= 1 + a[n - 1]) {
        return f(n - 1, x - 1);
    } else {
        return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
    }
}

int main()
{
    ll N, X; cin >> N >> X;
    a.push_back(1), p.push_back(1);
    rep(i, N) {
        a.push_back(a[i] * 2 + 3);
        p.push_back(p[i] * 2 + 1);
    }
    cout << f(N, X) << endl;
    return 0;
}