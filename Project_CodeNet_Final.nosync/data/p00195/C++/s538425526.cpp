//四則演算 #pragma GCC target("avx")
//並列計算 #pragma GCC optimize("O3")
//条件分岐を減らす #pragma GCC optimize("unroll-loops")
//浮動小数点演算 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define SORT(i) sort(i.begin(),i.end())
#define rSORT(i) sort(i.rbegin(),i.rend())
#define fSORT(i,a) sort(i.begin(),i.end(),a)
#define all(i) i.begin(),i.end()
#define out(y,x) ((y)<0||h<=(y)||(x)<0||w<=(x))
#define line cout << "-----------------------------\n" 
#define ENDL(i,n) ((i) == (n) - 1 ? "\n" : " ")
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
inline void print() { cout << "\n"; }
template<class T, class... Ts>inline void print(const T& a, const Ts&... ts) { cout << a << " "; print(ts...); }
template<class T>inline void print(const vector<T>& v) { for (int i = 0; i < v.size(); ++i)cout << v[i] << (i == v.size() - 1 ? "\n" : " "); }
template<class T>inline void print(const vector<vector<T>>& v) { for (auto& a : v)print(a); }
inline string reversed(const string& s) { string t = s; reverse(all(t)); return t; }

void solve(int num, int val) {
    FOR(i, 1, 5) {
        int s1, s2; cin >> s1 >> s2;
        if (chmax(val, s1 + s2))num = i;
    }
    cout << char('A' + num) << " " << val << "\n";
}

int main() {
    init();

    for (int s1, s2; cin >> s1 >> s2 && s1 != 0;)solve(0, s1 + s2);

    return 0;
}
