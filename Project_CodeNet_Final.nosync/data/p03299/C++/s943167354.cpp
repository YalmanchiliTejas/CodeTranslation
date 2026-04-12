#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using ull = uint64_t;
using ld = long double;

const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INV2 = (MOD + 1) / 2;

ll pw(ll x, ll y) {
    if (y == 0) {
        return 1;
    } else if (y % 2 == 0) {
        return pw(x * x % MOD, y / 2);
    } else {
        return pw(x, y - 1) * x % MOD;
    }
}

pair<ll, ll> solve(const vector<ll>& a) {
    if (a.size() == 1) {
        return {pw(2, a[0]), 0};
    } else {
        int mn = a[0];
        for (int x : a) {
            mn = min(mn, x);
        }
        bool eq = true;
        for (int x : a) {
            if (mn != x) {
                eq = false;
            }
        }
        if (eq) {
            ll fr = pw(2, a.size());
            return {pw(2, a[0]), (fr + MOD - 2) % MOD};
        }
        vector<pair<ll, ll> > segs;
        int ptr = 0;
        while (ptr < a.size()) {
            if (a[ptr] == mn) {
                int go = ptr;
                while (go < a.size() && a[go] == a[ptr]) {
                    go++;
                }
                ll tot = pw(2, go - ptr);
                segs.emplace_back(2, (tot + MOD - 2) % MOD);
                ptr = go;
            } else {
                int go = ptr;
                vector<ll> td;
                while (go < a.size() && a[go] > mn) {
                    td.push_back(a[go] - mn + 1);
                    go++;
                }
                segs.push_back(solve(td));
                ptr = go;
            }
        }

        ll tot = 1;
        for (const auto& x : segs) {
            tot = (tot * (x.first + x.second)) % MOD;
        }
        ll good = 1;
        for (const auto& x : segs) {
            ll cur = (x.first * INV2) % MOD;
            good = (good * cur) % MOD;
        }
        good = (good * 2) % MOD;
        ll bad = (tot + MOD - good) % MOD;
        return {good * pw(2, mn - 1) % MOD, bad};
    }
}
int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll& x : a) {
        cin >> x;
    }
    auto res = solve(a);
    cout << (res.first + res.second) % MOD << "\n";
}
