#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
#include <complex>
#include <cstring>
using namespace std;

using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

template<class T>
inline bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template<typename Monoid>
struct SegmentTree{
    using F = function<Monoid(Monoid, Monoid)>;

    int sz;
    vector<Monoid> seg;

    const F f;      // モノイドに対して二項演算を行う関数オブジェクト
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1){
        sz = 1;
        while(sz < n)   sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x){
        seg[k + sz] = x;
    }

    void build(){
        for(int k = sz - 1; k > 0; --k){
            seg[k] = f(seg[k << 1], seg[k << 1 | 1]);
        }
    }

    void update(int k, const Monoid &x){
        k += sz;
        seg[k] = x;
        while(k >>= 1){
            seg[k] = f(seg[k << 1], seg[k << 1 | 1]);
        }
    }

    Monoid query(int a, int b){
        Monoid L = M1, R = M1;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1){
            if(a & 1)   L = f(L, seg[a++]);
            if(b & 1)   R = f(seg[--b], R);
        }
        return f(L, R);
    }

    int lower_bound(int a, int b, const Monoid& x, int k = 1, int l = 0, int r = -1){
        if(r == -1) r = sz;
        if(b <= l || r <= a)    return b;
        else if(k >= sz){
            // judge condition
            if(seg[k] < x)  return b;
            else    return l;
        }
        else if(a <= l && r <= b){
            int L = lower_bound(a, b, x, k << 1, l, (l + r) >> 1);
            if(L < b)   return L;
            return lower_bound(a, b, x, k << 1 | 1, (l + r) >> 1, r);
        }
        else{
            int L = lower_bound(a, b, x, k << 1, l, (l + r) >> 1);
            if(L < b)   return L;
            return lower_bound(a, b, x, k << 1 | 1, (l + r) >> 1, r);
        }
    }

    Monoid operator[](const int &k) const{
        return seg[k + sz];
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    SegmentTree<int> seg(N, [](int a, int b){return max(a, b);}, 0);
    for(int i = 0; i < N; ++i){
        int A;
        cin >> A;
        seg.set(i, A);
    }
    seg.build();
    for(int i = 0; i < Q; ++i){
        int T;
        cin >> T;
        if(T == 2){
            int L, R;
            cin >> L >> R;
            --L;
            cout << seg.query(L, R) << '\n';
        }
        else{
            int X, V;
            cin >> X >> V;
            --X;
            if(T == 1)  seg.update(X, V);
            else    cout << seg.lower_bound(X, N, V) + 1 << '\n';
        }
    }
}