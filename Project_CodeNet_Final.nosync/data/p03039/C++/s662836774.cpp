#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <functional>
#include <ctime>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
using namespace std;
using ll = long long;

unsigned euclidean_gcd(unsigned a, unsigned b) {
    if (a < b) return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

class UnionFind {
public:
    vector <ll> par;
    vector <ll> siz;
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    ll root(ll x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    ll size(ll x) {
        return siz[root(x)];
    }
};

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 1;
    for (int i = 0; i < k; i++) {
        ans *= (n * m - i);
        ans %= 1000000007;
        ans *= modinv(i + 1, 1000000007);
        ans %= 1000000007;
    }
    ll b = (k * (k - 1) + k * (k - 1) % 1000000007 * modinv((n * m - 1) % 1000000007, 1000000007) % 1000000007) % 1000000007;
    ans *= b;
    ans %= 1000000007;
    ll t = 0;
    ll y = 0;
    for (int i = 0; i < n; i++) {
        t += i * (n - i) * 2 %1000000007;
        t %= 1000000007;
    }
    for (int i = 0; i < m; i++) {
        y += i * (m - i) * 2 %1000000007;
        y %= 1000000007;
    }
    ll p = n * n % 1000000007;
    ll q = m * m % 1000000007;
    t *= modinv(p, 1000000007);
    y *= modinv(q, 1000000007);

    ans *= (t + y) % 1000000007;
    ans %= 1000000007;
    ans *= modinv(2, 1000000007);
    ans %= 1000000007;
    cout << ans << endl;
}