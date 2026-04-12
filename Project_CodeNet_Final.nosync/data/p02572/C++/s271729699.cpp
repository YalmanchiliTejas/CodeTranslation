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

template<int modulo> struct ModInt {
    int x;

    ModInt() : x(0) {}
    ModInt(ll y) : x(y >= 0 ? y % modulo : (modulo - (-y) % modulo) % modulo) {}

    ModInt& operator+=(const ModInt& p) {
        if ((x += p.x) >= modulo) x -= modulo;
        return *this;
    }
    ModInt& operator-=(const ModInt& p) {
        if ((x += modulo - p.x) >= modulo) x -= modulo;
        return *this;
    }
    ModInt& operator*=(const ModInt& p) {
        x = (int)(1LL * x * p.x % modulo);
        return *this;
    }
    ModInt& operator/=(const ModInt& p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt& p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt& p) const { return x == p.x; }
    bool operator!=(const ModInt& p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = modulo, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return ModInt(u);
    }

    ModInt pow(ll e) {
        ll a = 1, p = x;
        while (e > 0) {
            if (e % 2 == 0) {
                p = (p * p) % modulo;
                e /= 2;
            }
            else {
                a = (a * p) % modulo;
                e--;
            }
        }
        return ModInt(a);
    }

    friend ostream& operator<<(ostream& os, const ModInt<modulo>& p) {
        return os << p.x;
    }
    friend istream& operator>>(istream& is, ModInt<modulo>& a) {
        ll x;
        is >> x;
        a = ModInt<modulo>(x);
        return (is);
    }
};
using modint = ModInt<mod>;

int main() {
    init();

    int n; cin >> n;
    vector<modint> a(n); cin >> a;
    modint sum = 0, ans = 0;
    FOR(i, 0, n) {
        ans += sum * a[i];
        sum += a[i];
    }
    print(ans);

    return 0;
}