#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    set<ll> s;
    vector<ll> v;
    v.push_back(x);
    s.insert(x);
    ll lsz;
    vector<ll>::iterator it;
    while (true) {
        ll a = (v.back() * v.back()) % m;
        ll sz = s.size();
        s.insert(a);
        if (sz == s.size()) {
            it = find(v.begin(), v.end(), a);
            lsz = s.size() - distance(v.begin(), it);
            break;
        }
        v.push_back(a);
    }
    ll idx = distance(v.begin(), it);
    ll bsum = 0;
    if (it != v.begin()) {
        bsum = accumulate(v.begin(), it, 0ll);
    }
    ll lsum = accumulate(it, v.end(), 0ll);
    ll ans = 0;
    if (v.size() >= n) {
        cout << accumulate(v.begin(), v.begin() + n, 0ll) << endl;
    }
    else {
        ans += bsum;
        n -= distance(v.begin(), it);
        ans += (n / lsz) * lsum;
        ans += accumulate(it, it + (n % lsz), 0ll);
        cout << ans << endl;
    }
}