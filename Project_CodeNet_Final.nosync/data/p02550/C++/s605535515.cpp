#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll x, ll m) {
    return (x * x) % m;
}

int main() {
    ll N, X, M;
    cin >> N >> X >> M;
    set<ll> s;
    s.insert(X);
    ll t = X;
    set<ll> c;
    vector<ll> v, w;
    v.push_back(X);
    for (int i = 0; i < N; i++) {
        t = f(t, M);
        //cout << t << "\n";
        if (s.count(t) == 1) {
            if (c.count(t) == 1) {
                break;
            }
            w.push_back(t);
            c.insert(t);
        }
        if (c.size() == 0) {
            s.insert(t);
            v.push_back(t);
        }
    }
    // for (ll i : s) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    // for (ll i : c) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    
    
    ll ans = 0;
    if (v.size() >= N) {
        for (int i = 0; i < N; i++) {
            ans += v[i];
        }
        cout << ans << "\n";
        return 0;
    }
    
    for (ll i : v) {
        ans += i;
    }
    
    ll sum = 0;
    for (ll i : w) {
        sum += i;
    }
    
    N -= v.size();
    ll m = N / c.size();
    ans += m * sum;
    ll k = N - m * c.size();
    
    for (int i = 0; i < k; i++) {
        ans += w[i];
    }
    cout << ans << "\n";
    return 0;
}