#include <iostream>
#include <vector>
#include <set>
#ifndef LIB_REPEAT_HPP
#define LIB_REPEAT_HPP
#define repeat(i,n) for (int i = 0; i < (n); ++i)
#define repeat_from(i,m,n) for (int i = (m); i < (n); ++i)
#define repeat_one(i,n) for (int i = 1; i <= (n); ++i)
#define repeat_rev(i,n) for (int i = (n)-1; 0 <= i; --i)
#define foreach(it, cont) for (decltype(cont.begin()) it = cont.begin(); it != cont.end(); ++it)
#endif
#ifndef LIB_DATA_SEGMENT_TREE_HPP
#define LIB_DATA_SEGMENT_TREE_HPP
#include <vector>
#include <limits>
#include <cassert>
#ifndef LIB_REPEAT_HPP
#define LIB_REPEAT_HPP
#define repeat(i,n) for (int i = 0; i < (n); ++i)
#define repeat_from(i,m,n) for (int i = (m); i < (n); ++i)
#define repeat_one(i,n) for (int i = 1; i <= (n); ++i)
#define repeat_rev(i,n) for (int i = (n)-1; 0 <= i; --i)
#define foreach(it, cont) for (decltype(cont.begin()) it = cont.begin(); it != cont.end(); ++it)
#endif
struct segment_index {
    int k;
    operator int() const { return k; }
    segment_index up()    const { return (segment_index) { (k-1)/2 }; }
    segment_index left()  const { return (segment_index) { k*2+1 }; }
    segment_index right() const { return (segment_index) { k*2+2 }; }
};

struct segment_range {
    int k, l, r;
    operator int() const { return k; }
    segment_range left()  const { return (segment_range) { k*2+1, l, (l+r)/2 }; }
    segment_range right() const { return (segment_range) { k*2+2, (l+r)/2, r }; }
    bool is_contained  (int a, int b) const { return a <= l and r <= b; }
    bool is_intersected(int a, int b) const { return l < b and a < r; }
};

template <typename T>
struct segment_tree {
    static int power_ge(int n) {
        int m = 1;
        while (m < n) m *= 2;
        return m;
    }
    std::vector<T> v;
    int orig_n;
    segment_tree(int n)            : v(power_ge(n)*2-1)          , orig_n(n) {}
    segment_tree(int n, T initial) : v(power_ge(n)*2-1, initial) , orig_n(n) {}
    T & operator [] (size_t i) { return v[i]; }
    const T & operator [] (size_t i) const { return v[i]; }
    segment_index index_at(int i) const { return (segment_index) { i + power_ge(orig_n) - 1 }; }
    segment_range root_range()    const { return (segment_range) { 0, 0, power_ge(orig_n) }; }
};

template <typename T>
struct range_maximum_query {
    segment_tree<T> v;
    int size() const { return v.orig_n; }
    range_maximum_query(int n)            : v(n)          {}
    range_maximum_query(int n, T initial) : v(n, initial) {}
    range_maximum_query(std::vector<T> w) : v(w.size()) {
        repeat (i,w.size()) update_at(i,w[i]);
    }

    void update_at(int i, T x) {
        assert (0 <= i and i < size());
        segment_index k = v.index_at(i);
        v[k] = x;
        while (0 < k) {
            k = k.up();
            v[k] = std::max(v[k.left()], v[k.right()]);
        }
    }

    // [s,t)
    T max_query(int s, int t) {
        assert (0 <= s and s <= t and t <= size());
        return max_query(s, t, v.root_range());
    }
    T max_query(int s, int t, const segment_range & range) {
        if (range.is_contained(s,t)) {
            return v[range];
        } else if (range.is_intersected(s,t)) {
            return std::max(
                    max_query(s, t, range.left()),
                    max_query(s, t, range.right()));
        } else {
            return std::numeric_limits<T>::min();
        }
    }
    T max_query_all() { return max_query(0, size()); }
};

template <typename T>
struct range_minimum_add_query {
    segment_tree<T> v; // minimum
    segment_tree<T> w; // added
    int size() const { return v.orig_n; }
    range_minimum_add_query(int n)            : v(n),          w(n) {}
    range_minimum_add_query(int n, T initial) : v(n, initial), w(n) {}
    range_minimum_add_query(std::vector<T> a) : v(a.size()), w(a.size()/2) {
        repeat (i,a.size()) add_at(i,a[i]);
    }

    void add_range(int s, int t, T x) {
        assert (0 <= s and s <= t and t <= size());
        add_range(s, t, x, v.root_range());
    }
    void add_range(int s, int t, T x, const segment_range & range) {
        if (range.is_contained(s,t)) {
            v[range] += x;
            w[range] += x;
        } else if (range.is_intersected(s,t)) {
            add_range(s, t, x, range.left());
            add_range(s, t, x, range.right());
            v[range] = std::min(
                    min_query(0, size(), range.left()),
                    min_query(0, size(), range.right())) + w[range];
        }
    }

    // [s,t)
    T min_query(int s, int t) const {
        assert (0 <= s and s <= t and t <= size());
        return min_query(s, t, v.root_range());
    }
    T min_query(int s, int t, const segment_range & range) const {
        if (range.is_contained(s,t)) {
            return v[range];
        } else if (range.is_intersected(s,t)) {
            return std::min(
                    min_query(s, t, range.left()),
                    min_query(s, t, range.right())) + w[range];
        } else {
            return std::numeric_limits<T>::max();
        }
    }

    void add_at(int i, T x) { add_range(i,i+1,x); }
    T min_query_all() const { return min_query(0, size()); }
};

#endif
#ifndef LIB_TYPEDEF_LL_HPP
#define LIB_TYPEDEF_LL_HPP
typedef long long ll;
typedef unsigned long long ull;
#endif
using namespace std;
#define MAX_N 300000

int main() {
    ios_base::sync_with_stdio(false);
    ll N, Q; cin >> N >> Q;
    set<int> opening;
    set<int> closing;
    range_minimum_add_query<ll> segtree(N, 0);
    {
        ll nest = 0;
        repeat (i,N) {
            char c; cin >> c;
            if (c == '(') {
                nest ++;
                opening.insert(i);
                segtree.add_at(i,nest);
            } else {
                nest --;
                closing.insert(i);
                segtree.add_at(i,nest);
            }
        }
    }
    repeat (query,Q) {
        ll i; cin >> i; -- i;
        if (closing.find(i) != closing.end()) {
            ll low = 0, high = i;
            ll mid;
            while (low < high) {
                ll mid = (low + high + 1) / 2;
                if (2 <= segtree.min_query(mid,i)) {
                    if (high == mid) break;
                    high = mid;
                } else {
                    if (low == mid) break;
                    low = mid;
                }
            }
            ll j = (high + low + 1) / 2;
            while (0 <= j-1 and 2 <= segtree.min_query(j-1,i)) j -= 1;
            opening.insert(i); closing.erase(i);
            j = *opening.lower_bound(j);
            closing.insert(j); opening.erase(j);
            segtree.add_range(j, i, -2);
            cout << j+1 << endl;
        } else {
            closing.insert(i); opening.erase(i);
            ll j = *closing.lower_bound(0);
            opening.insert(j); closing.erase(j);
            segtree.add_range(j, i, 2);
            cout << j+1 << endl;
        }
    }
    return 0;
}