#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const int INF = 1 << 28;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <typename T = int>
struct StarrySkyTree {
    int size;
    vector<T> data;
    vector<T> lazy;
    vector<T> width;

    StarrySkyTree(int n) {
        size = 1;
        while (size < n)
            size <<= 1;
        data.resize(size * 2, 0);
        lazy.resize(size * 2, 0);
        width.resize(size * 2, 1);
        for (int i = size - 2; i >= 0; i--) {
            width[i] = width[i * 2 + 1] + width[i * 2 + 2];
        }
    }

    void lazy_propagate(int p) {
        data[p] += lazy[p];
        if (p < size - 1) {
            lazy[p * 2 + 1] += lazy[p];
            lazy[p * 2 + 2] += lazy[p];
        }
        lazy[p] = 0;
    }

    void add(int wishl, int wishr, T x) { add(wishl, wishr, 0, size, 0, x); }
    void add(int wishl, int wishr, int watchl, int watchr, int k, T x) {
        if (wishr <= watchl || watchr <= wishl) {
            lazy_propagate(k);
            return;
        }
        if (wishl <= watchl && watchr <= wishr) {
            lazy[k] += x;
            lazy_propagate(k);
            return;
        }

        int mid = (watchl + watchr) / 2;
        lazy_propagate(k);
        add(wishl, wishr, watchl, mid, k * 2 + 1, x);
        add(wishl, wishr, mid, watchr, k * 2 + 2, x);
        data[k] = max(data[k * 2 + 1], data[k * 2 + 2]);
    }

    T getMax(int wishl, int wishr) { return getMax(wishl, wishr, 0, size, 0); }
    T getMax(int wishl, int wishr, int watchl, int watchr, int k) {
        if (wishr <= watchl || watchr <= wishl)
            return 0;
        if (wishl <= watchl && watchr <= wishr) {
            lazy_propagate(k);
            return data[k];
        }

        int mid = (watchl + watchr) / 2;
        T L = getMax(wishl, wishr, watchl, mid, k * 2 + 1);
        T R = getMax(wishl, wishr, mid, watchr, k * 2 + 2);
        return max(L, R);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pll>> ints(n + 1);
    for (int i = 0; i < m; ++i) {
        ll l, r, a;
        cin >> l >> r >> a;
        ints[r].emplace_back(l, a);
    }
    StarrySkyTree<ll> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        ll maxi = dp.getMax(0, i);
        dp.add(i, i + 1, maxi);
        for (auto &p : ints[i]) {
            dp.add(p.first, i + 1, p.second);
        }
    }
    cout << dp.getMax(0, n + 1) << "\n";

    return 0;
}