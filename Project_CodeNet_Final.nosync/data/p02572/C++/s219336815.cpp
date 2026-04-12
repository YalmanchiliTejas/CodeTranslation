#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<sstream>
#include<numeric>
#include<queue>
#include<cstdio>
#include<iterator>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb(x) push_back(x)
ll mod = 1e9 + 7;
ll inf = 1e9 + 7;
template<typename T, typename U>
T binpow(T a, U n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return (binpow(a, n - 1) * a) % mod;
    else {
        ll b = binpow(a, n / 2) % mod;
        return (b * b) % mod;
    }
}
template<typename T>
T gcd(T a, T b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
template<typename T>
istream& operator>>(istream& str, vector<T>& vec) {
    for (auto& w : vec) str >> w;
    return str;
}
template<typename T>
ostream& operator<<(ostream& str, vector<T>& vec) {
    for (auto& w : vec) str << w << ' ';
    return str;
}

struct segtree {
    vector<set<ll>>mn;
    vector<ll>tree;
    size_t size = 1;
    //void build(ll x, ll lx, ll rx, vector<ll>& vec);
    void build(ll size_) {
        while (size < size_) {
            size *= 2;
        }
        tree.resize(size * 2 - 1);
        mn.resize(size * 2 - 1);
    }
    void update(ll i, ll x, ll v, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        ll m = (lx + rx) / 2;
        if (i < m) {
            update(i, 2 * x + 1, v, lx, m);
        }
        else {
            update(i, 2 * x + 2, v, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    ll get(ll l, ll r, ll x, ll lx, ll rx) {
        if (l <= lx && rx <= r) return tree[x];
        if (rx <= l || lx >= r) return 0;
        ll m = (lx + rx) / 2;
        return get(l, r, 2 * x + 1, lx, m) + get(l, r, 2 * x + 2, m, rx);
    }
};



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ll>vec(n), dp(n + 1);
    cin >> vec;
    for (int i = n; i > 1; --i) {
        dp[i - 1] = (vec[i - 1] + dp[i]) % mod;
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += (vec[i] * dp[i + 1]) % mod;
    }
    cout << ans % mod;
}