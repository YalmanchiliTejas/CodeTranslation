// Author: Vamsi Krishna Reddy Satti
// With love for Competitive Programming!

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = int64_t; using vll = vector<ll>; using vvll = vector<vll>;
using pll = pair<ll, ll>; using vpll = vector<pll>; using vvpll = vector<vpll>;

// ------------------------------------------------------------------------------------------------

ll n;
vll v;

void func() {
    cin >> n;
    v.clear();
    for (ll i = 0, a; i < n; i++) {
        cin >> a;
        if (v.empty() || a <= v.back()) {
            v.push_back(a);
        } else {
            *upper_bound(v.begin(), v.end(), a, greater<ll>()) = a;
        }
    }
    cout << v.size() << endl;
}

int main() {
    fast_io; cout.precision(32);
    ll t = 1; // cin >> t;
    for (ll i = 1; i <= t; i++) {
        func();
    }
}
