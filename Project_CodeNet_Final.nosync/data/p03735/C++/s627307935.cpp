#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < int(n); ++ (i))
#define ALL(x) begin(x), end(x)
using ll = long long;
using namespace std;
template <class T> inline void chmin(T & a, T const & b) { a = min(a, b); }

template <typename T>
vector<T> apply_permutation(vector<int> const & sigma, vector<T> const & xs) {
    int n = sigma.size();
    vector<T> ys(n);
    REP (i, n) ys[i] = xs[sigma[i]];
    return ys;
}

template <class Semilattice>
struct sparse_table {
    typedef typename Semilattice::underlying_type underlying_type;
    vector<vector<underlying_type> > table;
    Semilattice lat;
    sparse_table() = default;
    sparse_table(vector<underlying_type> const & data, Semilattice const & a_lat = Semilattice())
            : lat(a_lat) {
        int n = data.size();
        int log_n = 32 - __builtin_clz(n);
        table.resize(log_n, vector<underlying_type>(n));
        table[0] = data;
        REP (k, log_n - 1) {
            REP (i, n) {
                table[k + 1][i] = i + (1ll << k) < n ?
                    lat.append(table[k][i], table[k][i + (1ll << k)]) :
                    table[k][i];
            }
        }
    }
    underlying_type range_concat(int l, int r) const {
        if (l == r) return lat.unit();  // if there is no unit, remove this line
        assert (0 <= l and l < r and r <= table[0].size());
        int k = 31 - __builtin_clz(r - l);  // log2
        return lat.append(table[k][l], table[k][r - (1ll << k)]);
    }
};
struct max_semilattice {
    typedef int underlying_type;
    int unit() const { return INT_MIN; }
    int append(int a, int b) const { return max(a, b); }
};
struct min_semilattice {
    typedef int underlying_type;
    int unit() const { return INT_MAX; }
    int append(int a, int b) const { return min(a, b); }
};

int main() {
    // input
    int n; scanf("%d", &n);
    vector<int> x(n), y(n);
    REP (i, n) scanf("%d%d", &x[i], &y[i]);

    // solve
    { // prepare
        REP (i, n) if (x[i] > y[i]) swap(x[i], y[i]);
        vector<int> order(n);
        iota(ALL(order), 0);
        sort(ALL(order), [&](int i, int j) { return x[i] < x[j]; });
        x = apply_permutation(order, x);
        y = apply_permutation(order, y);
    }
    ll result = LLONG_MAX;
    { // min_x is red and max_y is blue
        int r_min = *min_element(ALL(x));
        int r_max = *max_element(ALL(x));
        int b_min = *min_element(ALL(y));
        int b_max = *max_element(ALL(y));
        chmin(result, (r_max - r_min) *(ll) (b_max - b_min));
    }
    { // min_x and max_y are red
        int r_min = *min_element(ALL(x));
        int r_max = *max_element(ALL(y));
        sparse_table<max_semilattice> y_max(y);
        sparse_table<min_semilattice> y_min(y);
        REP (i, n) {
            int b_min = min(x[i],     y_min.range_concat(0, i));
            int b_max = max(x[n - 1], y_max.range_concat(0, i));
            if (b_max < b_min) break;
            chmin(result, (r_max - r_min) *(ll) (b_max - b_min));
        }
    }

    // output
    printf("%lld\n", result);
    return 0;
}
