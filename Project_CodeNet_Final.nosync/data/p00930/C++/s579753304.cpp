#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < int(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define REP_R(i, n) for (int i = (n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (n) - 1; (i) >= int(m); -- (i))
#define ALL(x) begin(x), end(x)
#define dump(x) cerr << #x " = " << x << endl
#define unittest_name_helper(counter) unittest_ ## counter
#define unittest_name(counter) unittest_name_helper(counter)
#define unittest __attribute__((constructor)) void unittest_name(__COUNTER__) ()
using ll = long long;
using namespace std;

const int inf = 1e9+7;
struct starry_sky_tree {
    int n;
    vector<int> a, b; // add, min
    explicit starry_sky_tree(int a_n) {
        n = pow(2, ceil(log2(a_n)));
        a.resize(2 * n - 1); // fill 0, unit of add
        b.resize(2 * n - 1); // fill 0, unit of add
    }
    void range_add(int l, int r, int z) {
        range_add(0, 0, n, l, r, z);
    }
    void range_add(int i, int il, int ir, int l, int r, int z) {
        if (l <= il and ir <= r) {
            a[i] += z;
            b[i] += z;
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_add(2 * i + 1, il, (il + ir) / 2, l, r, z);
            range_add(2 * i + 2, (il + ir) / 2, ir, l, r, z);
            b[i] = a[i] + min(b[2 * i + 1], b[2 * i + 2]); // min
        }
    }
    int range_min(int l, int r) {
        return range_min(0, 0, n, l, r);
    }
    int range_min(int i, int il, int ir, int l, int r) {
        if (l <= il and ir <= r) {
            return b[i];
        } else if (ir <= l or r <= il) {
            return inf; // unit of min
        } else {
            return a[i] + min( // min
                    range_min(2 * i + 1, il, (il + ir) / 2, l, r),
                    range_min(2 * i + 2, (il + ir) / 2, ir, l, r));
        }
    }
};

template <typename UnaryPredicate>
ll binsearch(ll l, ll r, UnaryPredicate p) { // [l, r), p is monotone
    assert (l < r);
    -- l;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        (p(m) ? r : l) = m;
    }
    return r; // = min { x in [l, r) | p(x) }, or r
}

int parentoi(char c) { return c == '(' ? + 1 : - 1; }
int main() {
    int n, queries; cin >> n >> queries;
    string s; cin >> s;
    starry_sky_tree nest(n);
    starry_sky_tree lparen(n);
    REP (i, n) {
        nest.range_add(i, n, parentoi(s[i]));
        if (s[i] == '(') lparen.range_add(i, i + 1, 1);
    }
    auto flip = [&](int i) {
        nest.range_add(i, n, - parentoi(s[i]));
        if (s[i] == '(') lparen.range_add(i, i + 1, -1);
        s[i] = (s[i] == '(' ? ')' : '(');
        nest.range_add(i, n,   parentoi(s[i]));
        if (s[i] == '(') lparen.range_add(i, i + 1,  1);
    };
    while (queries --) {
        int q; cin >> q; -- q;
        flip(q);
        int result = -1;
        if (s[q] == '(') {
            result = binsearch(0, n, [&](int i) {
                return nest.range_min(i, n) >= 2;
            });
        } else {
            result = binsearch(0, n, [&](int i) {
                return lparen.range_min(0, i + 1) == 0;
            });
        }
        cout << result + 1 << endl;
        flip(result);
    }
    return 0;
}