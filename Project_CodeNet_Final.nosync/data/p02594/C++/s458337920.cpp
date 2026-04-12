#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}

    mint operator-() const { return mint(-x); }

    mint &operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }

    mint operator+(const mint a) const { return mint(*this) += a; }

    mint operator-(const mint a) const { return mint(*this) -= a; }

    mint operator*(const mint a) const { return mint(*this) *= a; }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }

    mint &operator/=(const mint a) { return *this *= a.inv(); }

    mint operator/(const mint a) const { return mint(*this) /= a; }
};

istream &operator>>(istream &is, const mint &a) { return is >> a.x; }

ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

struct combination {
    vector<mint> fact, ifact;

    combination(int n) : fact(n + 1), ifact(n + 1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }

    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
};

struct UnionFind {
    vector<int> d;

    UnionFind(int n = 0) : d(n, -1) {}

    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return -d[find(x)]; }
};

template<typename T>
struct BIT {
    int n;
    vector<T> bit[2];

    BIT(int n_) { init(n_); }

    void init(int n_) {
        n = n_ + 1;
        for (int p = 0; p < 2; p++) bit[p].assign(n, 0);
    }

    void add_sub(int p, int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }

    void add(int l, int r, T x) {
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }

    T sum_sub(int p, int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
        }
        return s;
    }

    T sum(int i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
};

struct WeightedUnionFind {
    vector<int> data;
    vector<ll> ws;

    WeightedUnionFind() {}

    WeightedUnionFind(int sz) : data(sz, -1), ws(sz) {}

    int find(int k) {
        if (data[k] < 0) return k;
        auto par = find(data[k]);
        ws[k] += ws[data[k]];
        return data[k] = par;
    }

    ll weight(int t) {
        find(t);
        return ws[t];
    }

    bool unite(int x, int y, ll w) {
        w += weight(x);
        w -= weight(y);
        x = find(x), y = find(y);
        if (x == y) return false;
        if (data[x] > data[y]) {
            swap(x, y);
            w *= -1;
        }
        data[x] += data[y];
        data[y] = x;
        ws[y] = w;
        return true;
    }

    ll diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


int main() {
    int x;
    cin >> x;
    if (x >= 30)cout << "Yes" << endl;
    else cout <<"No" <<endl;
    return 0;
}
