//
//  main.cpp
//
 
#include <algorithm>
#include <array>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
using namespace std;
 
using ll = int64_t;
using ull = uint64_t;
 
template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
    return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
    auto inner = make_vec_nd(init, rest...);
    return vector<decltype(inner)>(size, inner);
}
 
// https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;
    using G = function< Monoid(Monoid, OperatorMonoid, int) >;
    using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;
    
    int sz;
    vector< Monoid > data;
    vector< OperatorMonoid > lazy;
    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;
    
    
    LazySegmentTree(int n, const F f, const G g, const H h,
                    const Monoid &M1, const OperatorMonoid OM0)
    : f(f), g(g), h(h), M1(M1), OM0(OM0) {
        sz = 1;
        while(sz < n) sz <<= 1;
        data.assign(2 * sz, M1);
        lazy.assign(2 * sz, OM0);
    }
    
    void set(int k, const Monoid &x) {
        data[k + sz] = x;
    }
    
    void build() {
        for(int k = sz - 1; k > 0; k--) {
            data[k] = f(data[2 * k + 0], data[2 * k + 1]);
        }
    }
    
    void propagate(int k, int len) {
        if(lazy[k] != OM0) {
            if(k < sz) {
                lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
                lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            }
            data[k] = g(data[k], lazy[k], len);
            lazy[k] = OM0;
        }
    }
    
    Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r) {
        propagate(k, r - l);
        if(r <= a || b <= l) {
            return data[k];
        } else if(a <= l && r <= b) {
            lazy[k] = h(lazy[k], x);
            propagate(k, r - l);
            return data[k];
        } else {
            return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                               update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
        }
    }
    
    Monoid update(int a, int b, const OperatorMonoid &x) {
        return update(a, b, x, 1, 0, sz);
    }
    
    
    Monoid query(int a, int b, int k, int l, int r) {
        propagate(k, r - l);
        if(r <= a || b <= l) {
            return M1;
        } else if(a <= l && r <= b) {
            return data[k];
        } else {
            return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
                     query(a, b, 2 * k + 1, (l + r) >> 1, r));
        }
    }
    
    Monoid query(int a, int b) {
        return query(a, b, 1, 0, sz);
    }
    
    Monoid operator[](const int &k) {
        return query(k, k + 1);
    }
};
 
 
int main() {
    int N, M;
    cin >> N >> M;
    struct Range {
        int start;
        int end;
        ll value;
    };
    unordered_map<ll, vector<Range>> ranges_end;
    unordered_map<ll, vector<Range>> ranges_start;
    for (ll i = 0; i < M; i++) {
        int l, r;
        ll a;
        cin >> l >> r >> a;
        l--;
        ranges_end[r].push_back(Range{l, r, a});
        ranges_start[l].push_back(Range{l, r, a});
    }
    ll NEG_INF = numeric_limits<ll>::min() / 2;
    LazySegmentTree<ll> dp((int)N+1, [](ll lhs, ll rhs){ return max(lhs, rhs); },
                           [](ll elm, ll op, ll len){ return elm + op; },
                           [](ll lhs, ll rhs){ return lhs + rhs; },
                           NEG_INF,
                           0);
    /*
    auto print_dp = [N, &dp](){
        for (int n = 0; n <= N; n++) {
            cout << dp[n] << " ";
            cout << endl;
        }
    };
    */
    ll ans = 0;
    dp.update(0, 1, -dp[0]);
    /*
    cout << "start: " << endl;
    print_dp();
    */
    for (int n = 1; n <= N; n++) {
        // cout << "n: " << n << endl;
        int idx = n - 1;
        for (const Range& range : ranges_start[idx]) {
            dp.update(0, n, range.value);
        }
        /*
        cout << "add: " << endl;
        print_dp();
        */
        for (const Range& range : ranges_end[idx]) {
            dp.update(0, range.start + 1, -range.value);
        }
        /*
        cout << "subtract: " << endl;
        print_dp();
        */
        ll dp_n = dp.query(0, (int)n);
        ans = max(ans, dp_n);
        dp.update(n, n+1, -dp[n] + dp_n);
        /*
        cout << "write: " << endl;
        print_dp();
        */
    }
    // cout << "ans" << endl;
    cout << ans << endl;
}
 