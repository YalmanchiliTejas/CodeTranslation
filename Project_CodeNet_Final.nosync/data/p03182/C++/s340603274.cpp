#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>
#include <set>
#include <functional>
#include <iomanip>

using namespace std;

#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
#define dump(x)  ;
#endif

#define equals(a,b) (fabs((a)-(b)) < EPS)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back

//#define int long long

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

    template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

template <typename T>
void print_array(const T &ary, int size){
    REP(i,size){
        cout << ary[i] << " ";
    }
    cout << endl;
}

const int mod = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;
const double EPS = (1e-10);

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

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(12);

    int N,M; cin >> N >> M;

    auto f = [](LL a, LL b){ return max(a,b); };
    auto g = [](LL a, LL b, int c){return a+b;};
    auto h = [](LL a, LL b){return a+b;};
    LazySegmentTree<LL> seg(N+1,f,g,h,-LINF,0);
    REP(i,N+1){
        seg.set(i,0);
    }
    seg.build();
    vector<vector<pair<LL,LL>>> reg(N+10);

    REP(i,M){
        LL l,r,a; cin >> l >> r >> a;
        reg[r].eb(l,a);
    
    }
    FOR(i,1,N+1){

        //cout << seg.query(0,i) << endl;
        seg.update(i,i+1,seg.query(0,i) - seg[i]);
        //cout << seg.query(i,i+1) << endl;
        for(auto p : reg[i]){
            LL l,a;
            tie(l,a) = p;
            seg.update(l,i+1,a);
            
            //cout << l << " " << i << " " << a << endl;
        }
    }
    cout << seg.query(0,N+1) << endl;

}