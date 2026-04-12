#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;     

const int MAXN = 228;

const ll MOD = 1e9 + 7;
const ll REV2 = (MOD + 1) / 2;

using Vec = vector<ll>;

ll p2(ll a) {
    if (!a) {
        return 1;
    }

    ll v = p2(a / 2);
    v = (v * v) % MOD;

    if (a & 1) {
        v = (v * 2) % MOD;
    }

    return v;
}


const ll INF = (1ll << 60);

ll eval(const Vec& a) {
    assert(a.size());

    ll mn = INF;
    for (ll x : a) {
        mn = min(mn, x);
    }

    ll cn = p2(mn) - 1;
    Vec na(a);
    for (ll& x : na) {
        x -= mn;
    }

    ll pv = 0;
    ll p = 0;

    na.push_back(0);

    for (ll x : na) {
        p += max<ll>(x - pv, 0ll);
        pv = x;
    }

    ll ans = p2(p) * cn % MOD;
    Vec cur;
    
    ll ansgood = REV2 * REV2 % MOD;

    for (ll x : na) {
        if (!x) {
            ansgood = (ansgood * 2) % MOD;
            if (!cur.empty()) {
                ansgood = ansgood * eval(cur) * 2 % MOD;
                cur.clear();
            }
        } else {
            cur.push_back(x);
        }
    }
    
    return (ans + ansgood) % MOD;
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    int n;
    cin >> n;
    Vec a(n);
    for (ll& x : a) {
        cin >> x;
        --x;
    }

    ll ans = eval(a);
    cout << (ans * 2) % MOD << "\n";
}