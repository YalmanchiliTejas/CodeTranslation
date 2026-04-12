#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define all(x) x.begin(), x.end()
#define mp make_pair
#define X first
#define Y second

template<typename T> // order_of_key(), *find_by_order()
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 gen(time(nullptr));

ll const mod = 998244353;

namespace {
    ll mul(ll a, ll b) {
        ll val = a * b - (ll) ((ld) a * b / mod) * mod;
        if (val < 0) val += mod;
        if (val >= mod) val -= mod;
        return val;
    }

    ll poww(ll a, ll b) {
        ll val = 1;
        a %= mod;
        while (b > 0) {
            if (b % 2) val = mul(a, val);
            a = mul(a, a);
            b >>= 1;
        }
        return val % mod;
    }

    ll inv(ll a) {
        return poww(a, mod - 2);
    }
}
ll const maxn = 1e7 + 7;
ll fact[maxn];
ll pw[maxn];

ll C(ll n, ll k) {
    return mul(fact[n], inv(mul(fact[n - k], fact[k])));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    pw[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = fact[i - 1] * i;
        pw[i] = pw[i - 1] * 2;
        pw[i] %= mod;
        fact[i] %= mod;
    }
    ll n;
    cin >> n;
    ll ans = poww(3, n);
    ll kek = 0;
    for (ll i = n / 2 + 1; i <= n; i++) {
        (kek += mul(C(n, i), pw[n - i])) %= mod;
    }
    kek = mul(kek, 2);
    cout << ((ans - kek) % mod + mod) % mod << endl;
    return 0;
}
/*

*/