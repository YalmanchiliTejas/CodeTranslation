#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
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
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<ll, int> Pl;
const double PI = 3.1415926535897932;   // acos(-1)
const double EPS = 1e-15;
const int INF = 1001001001;
const ll mod = 1e+9 + 7;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define chadd(x, y) x = (x + y) % mod

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

    Monoid operator[](const int &k) const{
        return seg[k + sz];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<P> input(n);
    int maxe = 0, mine = INF;
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        if(x > y)   swap(x, y);
        input[i] = P(x, y);
        chmax(maxe, y);
        chmin(mine, x);
    }
    bool flag = false;
    for(int i = 0; i < n; ++i){
        int x = input[i].first, y = input[i].second;
        if((maxe == x && mine != y) || (maxe != x && mine == y) || (mine == x && maxe != y) || (mine != x && maxe == y)){
            flag = true;
            break;
        }
    }

    ll res = 1e+18;
    // max と min が異なるグループ
    int rmin = INF, bmax = 0;
    for(int i = 0; i < n; ++i){
        int x = input[i].first, y = input[i].second;
        chmin(rmin, y);
        chmax(bmax, x);
    }
    ll hoge = (ll)(maxe - rmin) * (bmax - mine);
    chmin(res, hoge);

    // max と min が同じグループ
    if(flag){
        sort(input.begin(), input.end());
        SegmentTree<int> segmax(n, [](int a, int b){return max(a, b);}, 0);
        SegmentTree<int> segmin(n, [](int a, int b){return min(a, b);}, INF);
        for(int i = 0; i < n; ++i){
            segmax.set(i, input[i].second);
            segmin.set(i, input[i].second);
        }
        segmax.build();
        segmin.build();

        int bmax = 0, bmin = INF;
        for(int i = 1; i < n-1; ++i){
            if(segmax.query(i, n) != maxe)  continue;
            int foo_min = min(input[i].first, segmin.query(0, i));
            int foo_max = max(input[n-1].first, segmax.query(0, i));
            ll bar = (ll)(maxe - mine) * (foo_max - foo_min);
            chmin(res, bar);
        }
        if(input[n-1].first == maxe){
            int foo_min = segmin.query(0, n);
            int foo_max = segmax.query(0, n);
            ll bar = (ll)(maxe - mine) * (foo_max - foo_min);
            chmin(res, bar);
        }
    }
    cout << res << endl;
}