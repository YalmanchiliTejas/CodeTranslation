#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using VI = vector<int>;
using VL = vector<ll>;
template<class T> using PQ = priority_queue<T, vector<T>, greater<T>>;
#define FOR(i,a,n) for(int (i)=(a);(i)<(n);++(i))
#define eFOR(i,a,n) for(int (i)=(a);(i)<=(n);++(i))
#define rFOR(i,a,n) for(int (i)=(n)-1;(i)>=(a);--(i))
#define erFOR(i,a,n) for(int (i)=(n);(i)>=(a);--(i))
#define each(i, a) for(auto &i : a)
#define SORT(i) sort((i).begin(),(i).end())
#define rSORT(i,a) sort((i).begin(),(i).end(),(a))
#define all(i) (i).begin(),(i).end()
#define out(y,x) ((y) < 0 || h <= (y) || (x) < 0 || w <= (x))
#define line cout << "------------------------\n" 
#define ENDL(i,n) ((i) == (n) - 1 ? "\n" : " ")
#define stop system("pause") //comment out this on AOJ.
constexpr ll INF = 1000000000;
constexpr ll LLINF = 1LL << 60;
constexpr ll mod = 1000000007;
constexpr ll MOD = 998244353;
constexpr ld eps = 1e-10; //1e-9?
constexpr ld pi = 3.1415926535897932;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
inline void init() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }
template<class T>inline istream& operator>>(istream& is, vector<T>& v) { for (auto& elemnt : v)is >> elemnt; return is; }
template<class T, class U>inline istream& operator>>(istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template<class T>inline vector<T> vec(size_t a) { return vector<T>(a); }
template<class T>inline vector<T> defvec(T def, size_t a) { return vector<T>(a, def); }
template<class T, class... Ts>inline auto vec(size_t a, Ts... ts) { return vector<decltype(vec<T>(ts...))>(a, vec<T>(ts...)); }
template<class T, class... Ts>inline auto defvec(T def, size_t a, Ts... ts) { return vector<decltype(defvec<T>(def, ts...))>(a, defvec<T>(def, ts...)); }

template<int mod> struct ModInt {
    int x;

    ModInt() : x(0) {}
    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt& operator+=(const ModInt& p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt& operator-=(const ModInt& p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt& operator*=(const ModInt& p) {
        x = (int)(1LL * x * p.x % mod);
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
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return ModInt(u);
    }

    ModInt pow(int e) {
        long long a = 1, p = x;
        while (e > 0) {
            if (e % 2 == 0) { p = (p * p) % mod; e /= 2; }
            else { a = (a * p) % mod; e--; }
        }
        return ModInt(a);
    }

    friend ostream& operator<<(ostream& os, const ModInt<mod>& p) {
        return os << p.x;
    }
    friend istream& operator>>(istream& is, ModInt<mod>& a) {
        long long x;
        is >> x;
        a = ModInt<mod>(x);
        return (is);
    }
};
using modint = ModInt<mod>;

template<class T> class segtree {
    int n = 1;
    vector<T> dat;
    T def;

public:
    segtree(int _n, T _def) : def(_def) {
        while (n < _n)n *= 2;
        dat.resize(2 * n, def);
    }

    T fun(T x, T y) { return x + y; }

    void update(int i, T a) {
        i += n;
        dat[i] += a;
        while (i > 1) {
            i /= 2;
            dat[i] = fun(dat[2 * i], dat[2 * i + 1]);
        }
    }

    T value(int l, int r) {
        l += n, r += n;

        T ret = def;
        for (; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                ret = fun(ret, dat[l]);
                l++;
            }
            if (r & 1) {
                --r;
                ret = fun(ret, dat[r]);
            }
        }

        return ret;
    }
};

class unionfind {
    VI par, rank;
    int forest_num;
public:
    unionfind(int n) : par(n), rank(n, 1), forest_num(n) {
        FOR(i, 0, n)par[i] = i;
    }
    int root(int x) {
        if (par[x] == x)return x;
        return par[x] = root(par[x]);
    }
    int size(int x) {
        if (par[x] == x)return rank[x];
        return size(par[x]);
    }
    void unite(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx == ry)return;
        if (rank[rx] < rank[ry]) {
            par[rx] = ry;
            rank[ry] += rank[rx];
        }
        else {
            par[ry] = rx;
            rank[rx] += rank[ry];
        }
        --forest_num;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int fnum() { return forest_num; }
};

ll gcd(ll a, ll b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

const int nCk_MAX = 510000;
ll fac[nCk_MAX], finv[nCk_MAX], inv[nCk_MAX];
bool Pre = true;
void cominit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < nCk_MAX; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
ll com(int n, int k) {
    if (Pre) {
        cominit();
        Pre = false;
    }
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
    init();

    int n, a, b, c, d, x, y, h, w;
    int m; cin >> n >> m;
    cout << (n == m ? "Yes\n" : "No\n");
}
