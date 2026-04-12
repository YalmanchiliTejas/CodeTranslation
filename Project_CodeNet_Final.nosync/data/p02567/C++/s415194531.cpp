#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using VI = vector<int>;
using VL = vector<ll>;
using VS = vector<string>;
template<class T> using PQ = priority_queue<T, vector<T>, greater<T>>;
#define FOR(i,a,n) for(int i=(a);i<(n);++i)
#define eFOR(i,a,n) for(int i=(a);i<=(n);++i)
#define rFOR(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define erFOR(i,a,n) for(int i=(n);i>=(a);--i)
#define each(i, a) for(auto &i : a)
#define SORT(a) sort(a.begin(),a.end())
#define rSORT(a) sort(a.rbegin(),a.rend())
#define fSORT(a,f) sort(a.begin(),a.end(),f)
#define all(a) a.begin(),a.end()
#define out(y,x) ((y)<0||h<=(y)||(x)<0||w<=(x))
#define tp(a,i) get<i>(a)
#define line cout << "-----------------------------\n" 
#define ENDL(i,n) ((i) == (n) - 1 ? "\n" : " ")
#define elif else if
#define stop system("pause")
constexpr ll INF = 1000000000;
constexpr ll LLINF = 1LL << 60;
constexpr ll mod = 1000000007;
constexpr ll MOD = 998244353;
constexpr ld eps = 1e-10;
constexpr ld pi = 3.1415926535897932;
template<class T>inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; }return false; }
inline void init() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }
template<class T>inline istream& operator>>(istream& is, vector<T>& v) { for (auto& a : v)is >> a; return is; }
template<class T>inline istream& operator>>(istream& is, deque<T>& v) { for (auto& a : v)is >> a; return is; }
template<class T, class U>inline istream& operator>>(istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template<class T>inline vector<T> vec(size_t a) { return vector<T>(a); }
template<class T>inline vector<T> defvec(T def, size_t a) { return vector<T>(a, def); }
template<class T, class... Ts>inline auto vec(size_t a, Ts... ts) { return vector<decltype(vec<T>(ts...))>(a, vec<T>(ts...)); }
template<class T, class... Ts>inline auto defvec(T def, size_t a, Ts... ts) { return vector<decltype(defvec<T>(def, ts...))>(a, defvec<T>(def, ts...)); }
template<class T>inline void print(const T& a) { cout << a << "\n"; }
template<class T, class... Ts>inline void print(const T& a, const Ts&... ts) { cout << a << " "; print(ts...); }
template<class T>inline void print(const vector<T>& v) { for (int i = 0; i < v.size(); ++i)cout << v[i] << (i == v.size() - 1 ? "\n" : " "); }
template<class T>inline void print(const vector<vector<T>>& v) { for (auto& a : v)print(a); }
inline string reversed(const string& s) { string t = s; reverse(all(t)); return t; }

#include<atcoder/segtree>
using namespace atcoder;
int op(int a, int b) { return max(a, b); }
int e() { return -1; }
int target;
bool f(int v) { return v < target; }
int main() {
    init();

    int n, q; cin >> n >> q;
    VI a(n); cin >> a;
    segtree<int, op, e> seg(a);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, v; cin >> x >> v;
            --x;
            seg.set(x, v);
        }
        elif (t == 2) {
            int l, r; cin >> l >> r;
            --l;
            print(seg.prod(l, r));
        }
        else {
            int p;
            cin >> p >> target;
            --p;
            print(seg.max_right<f>(p) + 1);
        }
    }

    return 0;
}