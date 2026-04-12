#include <bits/stdc++.h>
#define rep(i, n) for (ll i=0; i<n; ++i)
#define rep1(i, n) for (ll i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

vector<ll> a {1};
vector<ll> p {1};

ll f(ll n, ll x) {
    if (n==0) {
        if (x<=0) return 0;
        else return 1;
    }
    else if (x <= 1 + a[n-1]) {
        return f(n-1, x-1);
    }
    else {
        return p[n-1] + 1 + f(n-1, x-2-a[n-1]);
    }
}

int main() {
    ll n, x; cin >> n >> x;
    rep(i, n) {
        a.push_back(a[i] * 2 + 3);
        p.push_back(p[i] * 2 + 1);
    }
    ll ret; ret = f(n, x);
    cout << ret << endl;
    return 0;
}