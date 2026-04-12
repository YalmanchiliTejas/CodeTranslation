#include <bits/stdc++.h>
#define elif else if
#define ALL(a) a.begin(), a.end()
#define INN(n) int n; cin >> n;
#define INNVEC(n, a) int n; cin >> n; vector<int> a(n); for (int i=0;i<n;i++) cin >> a[i];
using namespace std;
using LL = long long;
using LD = long double;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;
using TI = tuple<int, int, int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
template <class T> int bcnt(const T &a) { return __builtin_popcount(a); }
template <> int bcnt(const int64_t &a) { return __builtin_popcount(a); }
template <class T> int blen(const T &a) { return a ? 1 + blen(a / 2) : 0; }
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
template <class T = int> T inf() { return numeric_limits<T>::max() / 2; }
template <class T> T sign(const T &a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
template <class T> T floor(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? abs(a) / abs(b) : -(abs(a) + abs(b) - 1) / abs(b);
}
template <class T> T ceil(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? (abs(a) + abs(b) - 1) / abs(b) : -abs(a) / abs(b);
}
template <class T> bool chmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T> bool chmax(T &a, T b) { return b > a ? a = b, true : false; }
template <class T> auto min(const T &a) { return *min_element(ALL(a)); } 
template <class T> auto max(const T &a) { return *max_element(ALL(a)); }
template <class T> auto sum(const T &a) { return accumulate(ALL(a), (typename T::value_type)0); }
template <> auto sum(const vector<int> &a) { return accumulate(ALL(a), 0LL); }
template <> auto sum(const vector<string> &a) { return accumulate(ALL(a), string()); }
template <class T> void uniq(T &a) { sort(a); a.erase(unique(ALL(a)), a.end()); }
template <class T> auto vect(const T &v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T& v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
template <class T> void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
template <class T> void in(vector<T> &vec) { for (auto& v: vec) cin >> v; }
void ou() { cout << endl; }
template<class T> void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
template <class T> void ou(const vector<T> &vec) {
    cout << (int)vec.size() << ' ';
    bool first = true;
    for (auto& v: vec) { cout << (first ? "" : " "); cout << v; first = 0; }
    cout << '\n';
}

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
    out << "["; bool first = true;
    for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
    return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
    out << "["; bool first = true;
    for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
    return out;
}
template <typename T>
ostream& operator <<(ostream& out, const deque<T>& a) {
    out << "["; bool first = true;
    for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
    return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
    out << "{"; bool first = true;
    for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
    return out;
}
template <typename T>
ostream& operator <<(ostream& out, const unordered_set<T>& a) {
    out << "{"; bool first = true;
    for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
    return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
    out << "{"; bool first = true;
    for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0;} out << "}";
    return out;
}
template<class T> inline void YES(T condition) { 
    if(condition) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
template<class T> inline void Yes(T condition) {
    if(condition) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
template<class T> T gcd(T a, T b) {
    while (b) {
        T tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
template<class T> T lcm(T a, T b){
    return a / gcd(a, b) * b;
}

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}

long long qpow(long long a, long long b, int MOD) {
    if (b == 0) return 1;
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

const int MOD = 1e9 + 7;
const int maxn = 2e6;
const LD eps = 1e-8;
const LD pi = acos(-1);
// const int INF = 2e9;
int fac[maxn + 5];
int invfac[maxn + 5];
void init() {
    fac[0] = 1;
    for (int i = 1; i <= maxn; i++) fac[i] = 1LL * fac[i - 1] * i % MOD;
    invfac[maxn] = (int)(qpow(fac[maxn], MOD - 2, MOD));
    for (int i = maxn - 1; i >= 0; i--) invfac[i] = 1LL * invfac[i + 1] * (i + 1) % MOD;
}
int C(int n, int k) {
    assert(0 <= k && n >= k);
    int tmp = (int)(1LL * invfac[k] * invfac[n - k] % MOD);
    return (int)(1LL * fac[n] * tmp % MOD);
}
    // vector<int> fa(n);
    // vector<int> sz(n, 1);
    // iota(fa.begin(), fa.end(), 0);
    // function<int(int)> Find = [&](int x) {
    //     return x == fa[x] ? x : fa[x] = Find(fa[x]);
    // };
    // function<bool(int, int)> Union = [&](int x, int y) {
    //     int px = Find(x), py = Find(y);
    //     if (px == py) return false;
    //     if (sz[px] > sz[py]) swap(px, py);
    //     fa[px] = py;
    //     sz[py] += sz[px];
    //     return true;
    // };

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<LL> a(n);
    LL s = 0;
    for (auto &v: a) { cin >> v; s += v; }
    LL ans = 0;
    for (auto &v: a) {
        s -= v;
        ans += (s % MOD) * v;
        ans %= MOD;
    }
    cout << ans << '\n';
    

    return 0;
}
