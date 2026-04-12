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
using namespace std;

typedef long long ll;
typedef uint64_t ull;
typedef pair<int, int> P;
constexpr double PI = 3.1415926535897932;   // acos(-1)
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

template<typename Monoid, typename OperatorMonoid = Monoid>
struct LazySegmentTree{
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;
    using C = function<OperatorMonoid(OperatorMonoid, int)>;

    int sz;
    vector<Monoid> data;
    vector<OperatorMonoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid M1;            // モノイドの単位元
    const OperatorMonoid OM0;   // 作用素モノイドの単位元
    const C c;

    LazySegmentTree(int n, const F f, const G g, const H h, const Monoid &M1,
        const OperatorMonoid OM0, const C c = [](OperatorMonoid a, int b){return a;})
        : f(f), g(g), h(h), M1(M1), OM0(OM0), c(c)
    {
        sz = 1;
        while(sz < n)   sz <<= 1;
        data.assign(sz << 1, M1);
        lazy.assign(sz << 1, OM0);
    }

    void set(int k, const Monoid &x){
        data[k + sz] = x;
    }

    void build(){
        for(int k = sz - 1; k > 0; --k){
            data[k] = f(data[k << 1], data[k << 1 | 1]);
        }
    }

    void propagate(int k, int len){
        if(lazy[k] != OM0){
            if(k < sz){
                lazy[k << 1] = h(lazy[k << 1], lazy[k]);
                lazy[k << 1 | 1] = h(lazy[k << 1 | 1], lazy[k]);
            }
            data[k] = g(data[k], c(lazy[k], len));
            lazy[k] = OM0;
        }
    }

    Monoid update(int a, int b, const OperatorMonoid &x, int k=1, int l=0, int r=-1){
        if(r == -1)     r = sz;
        propagate(k, r - l);
        if(r <= a || b <= l)    return data[k];
        else if(a <= l && r <= b){
            lazy[k] = h(lazy[k], x);
            propagate(k, r - l);
            return data[k];
        }
        else{
            return data[k] = f(update(a, b, x, k << 1, l, (l + r) >> 1),
                                update(a, b, x, k << 1 | 1, (l + r) >> 1, r));
        }
    }

    Monoid query(int a, int b, int k=1, int l=0, int r=-1){
        if(r == -1)     r = sz;
        propagate(k, r - l);
        if(r <= a || b <= l)    return M1;
        else if(a <= l && r <= b)   return data[k];
        else{
            return f(query(a, b, k << 1, l, (l + r) >> 1),
                        query(a, b, k << 1 | 1, (l + r) >> 1, r));
        }
    }

    Monoid operator[](const int &k){
        return query(k, k + 1);
    }

    void print(){
        for(int i = 0; i < data.size(); ++i){
            cerr << data[i] << " ";
        }
        cerr << "\n";
    }

    void lazy_print(){
        for(int i = 0; i < lazy.size(); ++i){
            cerr << lazy[i] << " ";
        }
        cerr << "\n";
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<P>> input(n + 1);
    for(int i = 0; i < m; ++i){
        int l, r, a;
        cin >> l >> r >> a;
        --l;
        input[r].push_back(P(l, a));
    }

    // dp[i] := 一番右にある 1 が、左から i 番目にあるときの、スコアの最大値
    LazySegmentTree<ll> dp(n + 5, [](ll a, ll b){return max(a, b);},
                                  [](ll a, ll b){return a + b;},
                                  [](ll a, ll b){return a + b;},
                                  0LL, 0LL);

    for(int i = 0; i < n; ++i){
        // dp[i] = max(dp[j]) (j : [0, i)) で初期化
        dp.update(i, i + 1, dp.query(0, i));

        // 右端が i であるような区間 [l, r) に対して、dp テーブルを更新
        for(auto p : input[i + 1]){
            int l = p.first;
            ll a = p.second;
            dp.update(l, i + 1, a);
        }
    }

    cout << dp.query(0, n) << endl;
}