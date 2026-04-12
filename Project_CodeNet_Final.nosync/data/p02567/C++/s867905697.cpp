#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <vector>
#include <functional>
#include <iterator>

//===
template<class Monoid>
struct SegmentTree {
    using T = typename Monoid::value_type;

    std::vector<T> tree;

    SegmentTree() = default;
    explicit SegmentTree(int n)
        :tree(n << 1, Monoid::identity()) {};

    template<class InputIterator>
    SegmentTree(InputIterator first, InputIterator last) {
        tree.assign(distance(first, last) << 1, Monoid::identity());

        int i;
        i = size();
        for (InputIterator itr = first; itr != last; itr++) {
            tree[i++] = *itr;
        }
        for (i = size() - 1; i > 0; i--) {
            tree[i] = Monoid::operation(tree[(i << 1)], tree[(i << 1) | 1]);
        }
    };

    inline int size() {
        return tree.size() >> 1;
    };

    inline T operator[] (int k) {
        return tree[k + size()];
    };

    void update(int k, const T dat) {
        k += size();
        tree[k] = dat;
        
        while(k > 1) {
            k >>= 1;
            tree[k] = Monoid::operation(tree[(k << 1)], tree[(k << 1) | 1]);
        }
    };

    // [l, r)
    T fold(int l, int r) {
        l += size(); //points leaf
        r += size();

        T lv = Monoid::identity();
        T rv = Monoid::identity();
        while (l < r) {
            if (l & 1) lv = Monoid::operation(lv, tree[l++]);
            if (r & 1) rv = Monoid::operation(tree[--r], rv);
            l >>= 1;
            r >>= 1;
        }

        return Monoid::operation(lv, rv);
    };

    template<class F>
    inline int sub_tree_search(int i, T sum, F f) {
        while (i < size()) {
            T x = Monoid::operation(sum, tree[i << 1]);
            if (f(x)) {
                i = i << 1;
            }
            else {
                sum = x;
                i = (i << 1) | 1;
            }
        }
        return i - size();
    }

    template<class F>
    int search(int l, F f) {
        l += size();
        int r = size() * 2; //r = n;
        int tmpr = r;
        int shift = 0;

        T sum = Monoid::identity();
        while (l < r) {
            if (l & 1) {
                if (f(Monoid::operation(sum, tree[l]))) {
                    return sub_tree_search(l, sum, f);
                }
                sum = Monoid::operation(sum, tree[l]);
                l++;
            }
            l >>= 1;
            r >>= 1;
            shift++;
        }

        while (shift > 0) {
            shift--;
            r = tmpr >> shift;
            if (r & 1) {
                r--;
                if (f(Monoid::operation(sum, tree[r]))) {
                    return sub_tree_search(r, sum, f);
                }
                sum = Monoid::operation(sum, tree[r]);
            }
        }

        return -1;
    };
};
//===

#endif

using i64 = long long;
#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)
#define _rep3(Itr, a, b, step) for (i64 (Itr) = a; (Itr) < b; (Itr) += step)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)

using namespace std;
using llong = long long;

struct Monoid {
    using value_type = int;
    inline static int identity() {
        return -1;
    };
    inline static int operation(int a, int b) {
        return max(a, b);
    };
};

#include <iostream>

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &vs:v) cin >> vs;
    SegmentTree<Monoid> seg(v.begin(), v.end());

    int com, a, b;
    int tmp;

    auto f = [&](int x){
        if (x >= b) return true;
        else return false;
    };
    while (q--) {
        cin >> com >> a >> b;
        switch(com) {
            case 1:
            seg.update(a - 1, b);
            break;
            case 2:
            printf("%d\n", seg.fold(a - 1, b));
            break;
            case 3:
            tmp = seg.search(a - 1, f);
            printf("%d\n", tmp >= 0 ? tmp + 1 : n + 1);
            break;
        }
    }

    return 0;
};
