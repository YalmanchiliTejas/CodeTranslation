#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> seq;
    vector<bool> seen(m);
    ll val = x;
    vector<int> cycle;
    while (!seen[x]) {
        seen[x] = true;
        seq.push_back(x);
        //cout << "x: " << x << endl;
        x *= x;
        x %= m;
    }
    while (seq.back() != x) {
        cycle.push_back(seq.back());
        seq.pop_back();
    }
    cycle.push_back(x);
    seq.pop_back();
    reverse(cycle.begin(), cycle.end());
    ll ans = 0;
    for (ll j = 0; j < min((ll)(seq.size()), n); ++j) {
        ans += seq[j];
    }
    n -= (ll) seq.size();
    if (n < 0) {
        cout << ans << endl;
        return 0;
    }
    vector<ll> pref(cycle.size());
    for (int i = 0; i < cycle.size(); ++i) {
        pref[i] = cycle[i];
        if (i) pref[i] += pref[i - 1];
    }
    ans += (n / ((ll) cycle.size())) * 1ll * pref.back();
    if (n % ((ll) cycle.size()) != 0) ans += pref[n % ((ll) cycle.size()) - 1];
    cout << ans << endl;
    return 0;
}