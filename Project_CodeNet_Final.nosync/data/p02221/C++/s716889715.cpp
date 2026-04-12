#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

// 0-indexed bottom up Segment Tree
// UNIT is the identity element of operation func
template <typename T = int>
struct SegmentTree {
    using F = function<T(T, T)>;
    int n;
    vector<T> dat;
    F func;
    T UNIT;

    SegmentTree(int n_, F func_, T UNIT_) : func(func_), UNIT(UNIT_) {
        n = 1;
        // full binary tree: num of leaves = n = 2^k >= n_
        while (n < n_)
            n *= 2;
        dat.assign(2 * n - 1, UNIT);
    }
    SegmentTree(vector<T> v_, F func_, T UNIT_) : func(func_), UNIT(UNIT_) {
        n      = 1;
        int nv = v_.size();
        while (n < nv)
            n *= 2;
        dat.assign(2 * n - 1, UNIT);
        for (int i = 0; i < nv; ++i) {
            dat[n - 1 + i] = v_[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            dat[i] = func(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }
    void update(int k, T a) {
        // leaves are at index n-1 to 2*n-2
        k += n - 1;
        dat[k] = a;
        while (k > 0) {
            // k -> parent node
            k = (k - 1) / 2;
            // func(child nodes)
            dat[k] = func(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // get result of func() in [l, r)
    T query(int l, int r) {
        l += n - 1;
        r += n - 1;
        T retl = UNIT, retr = UNIT;
        while (l < r) {
            if ((l & 1) == 0)
                retl = func(retl, dat[l]);
            if ((r & 1) == 0)
                retr = func(dat[r - 1], retr);
            l = l / 2;
            r = (r - 1) / 2;
        }
        return func(retl, retr);
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    lint n;
    cin >> n;
    string s;
    cin >> s;
    lint m = 1 << n;
    vector<lint> p(1 << (n));
    vector<vector<lint>> dp(n + 10, vector<lint>(1 << (n + 2), -1));
    for (int i = 0; i < (1 << n); ++i) {
        cin >> p[i];
        dp[0][i] = dp[0][i + m] = p[i];
    }
    const lint unit = -1;
    auto f          = [&](lint l, lint r) {
        if (l == unit)
            return r;
        if (r == unit)
            return l;
        if (l > r)
            swap(l, r);
        if (s[r - l - 1] == '1')
            return r;
        else
            return l;
    };
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2 * m; ++j) {
            dp[i][j] = f(dp[i - 1][j], dp[i - 1][(j + (1 << (i - 1))) % m]);
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << dp[n][i] << "\n";
    }
    return 0;
}
