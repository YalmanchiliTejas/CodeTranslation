#pragma GCC target("avx2,avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <atcoder/all>
using namespace atcoder;
//using mint = modint998244353;
//using mint = modint1000000007;
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//using i128 = __int128_t;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
constexpr char ln = '\n';
template<class T1, class T2> inline bool chmax(T1 &a, T2 b) {if (a < b) {a = b; return true;} return false;}
template<class T1, class T2> inline bool chmin(T1 &a, T2 b) {if (a > b) {a = b; return true;} return false;}
inline int topbit(int x) {return x == 0 ? -1 : 31-__builtin_clz(x);}
inline int topbit(long long x) {return x == 0 ? -1 : 63-__builtin_clzll(x);}
inline int botbit(int x) {return x == 0 ? 32 : __builtin_ctz(x);}
inline int botbit(long long x) {return x == 0 ? 64 : __builtin_ctzll(x);}
inline int popcount(int x) {return __builtin_popcount(x);}
inline int popcount(long long x) {return __builtin_popcountll(x);}
inline int kthbit(long long x, int k) {return (x>>k)&1;}
inline void print() {cout << "\n";}
template<class T>
inline void print(const vector<T> &v) {
    for (auto itr = v.begin(); itr != v.end(); ++itr) cout << *itr << " ";
    print();
}
template<class T, class... Args>
inline void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
#ifdef MINATO_LOCAL
#define dump(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
inline void debug() {cerr << endl;}
template<class T>
inline void debug(const vector<T> &v) {
    for (auto itr = v.begin(); itr != v.end(); ++itr) cerr << *itr << " ";
    debug();
}
template<class T, class... Args>
inline void debug(const T &x, const Args &... args) {
    cerr << x << " ";
    debug(args...);
}
#else
#define dump(x) void(0)
inline void debug() {}
template<class T> inline void debug(const vector<T> &v) {}
template<class T, class... Args> inline void debug(const T &x, const Args &... args) {}
#endif
struct Fast_ios {Fast_ios() {cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20);};} fast_ios;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int op(int a, int b) { return max(a, b); }

int e() { return -1; }

int target;

bool f(int v) { return v < target; }

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    segtree<int, op, e> seg(a);

    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int x, v; cin >> x >> v;
            x--;
            seg.set(x, v);
        } else if (t == 2) {
            int l, r; cin >> l >> r;
            l--;
            cout << seg.prod(l,r) << ln;
        } else if (t == 3) {
            int p; cin >> p >> target;
            p--;
            cout << seg.max_right<f>(p) + 1 << ln;
        }
    }
}
