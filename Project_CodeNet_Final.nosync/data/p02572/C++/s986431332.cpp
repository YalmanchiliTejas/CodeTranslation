#include <bits/stdc++.h>
using namespace std;

#define int long long
#define itn int
#define For(i, a, b) for (int i = (a); i <= static_cast<int>(b); i++)
#define Forr(i, a, b) for (int i = (a); i >= static_cast<int>(b); i--)
#define rep(i, n) For(i, 0, n - 1)
#define repall(i, arr) for (auto& i : (arr))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define dump(x) cerr << #x << " = " << (x) << '\n'
#define dump2(x, y) \
    cerr << #x << " = " << (x) << " " << #y << " = " << (y) << '\n'
#define SZ(x) ((int)(x).size())
#define bit(n) (1LL << (n))
constexpr int MOD = 1e9 + 7;

template <typename T>
using pq = priority_queue<T>;
template <typename T>
using pqr = priority_queue<T, vector<T>, greater<T>>;
const int INF = LLONG_MAX / 2;
using P = pair<int, int>;
using vec = vector<int>;
template <typename T>
using mat = vector<vector<T>>;

// clang-format off
template <typename T1, typename T2>
ostream& operator<<(ostream& stream, const pair<T1, T2>& p) { return stream << p.first << "," << p.second; }
template <typename T>
void print(const vector<T> vec) { rep (i, vec.size() - 1) cout << vec[i] << ' '; cout << vec[vec.size() - 1] << '\n'; }
template <typename Arg>
void print(const Arg arg) { cout << arg << '\n'; }
template <typename Head, typename... Args>
void print(const Head head, const Args... args) { cout << head << " "; print(args...); }
template <typename T, typename U>
void init(vector<T>& v, vector<U>& w) { rep (i, v.size()) cin >> v[i] >> w[i]; }
template <typename T>
void init(vector<T>& v) { rep (i, v.size()) cin >> v[i]; }
template <typename T>
T sum_(vector<T> vec, T init = 0) { return std::accumulate(all(vec), T(init)); }
template<typename T>
bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<typename T>
bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template <typename T>
int index(const T& vec, const typename T::iterator it) { return distance(vec.begin(), it); }
template <typename T = int>
mat<T> mmat(int n, int m=0) { return mat<T>(n, vector<T>(m)); }
template <typename T = int>
vector<T> ivec(int n) { vector<T> v(n); init(v); return v; }
// clang-format on

class mint {
    using ll = long long;
    ll num;

public:
    mint(ll x = 0) : num(x % MOD) {}
    mint operator+=(const mint& x) noexcept {
        this->num += x.num;
        if (this->num >= MOD) this->num %= MOD;
        return *this;
    }
    mint operator-=(const mint& x) noexcept {
        if (this->num < x.num) this->num += MOD;
        this->num -= x.num;
        return *this;
    }
    mint operator*=(const mint& x) noexcept {
        this->num = (this->num * x.num) % MOD;
        return *this;
    }
    mint operator/=(mint x) noexcept {
        ll exp = MOD - 2;
        while (exp) {
            if (exp % 2) *this *= x;
            x *= x;
            exp /= 2;
        }
        return *this;
    }
    mint operator%=(const mint& x) noexcept {
        this->num %= x.num;
        return *this;
    }
    mint operator+(const mint& x) const noexcept { return mint(*this) += x; }
    mint operator-(const mint& x) const noexcept { return mint(*this) -= x; }
    mint operator*(const mint& x) const noexcept { return mint(*this) *= x; }
    mint operator/(const mint& x) const noexcept { return mint(*this) /= x; }
    mint operator%(const mint& x) const noexcept { return mint(*this) %= x; }
    mint operator&(const mint& x) const noexcept { return this->num & x.num; }
    bool operator==(const mint& x) const noexcept { return this->num == x.num; }
    bool operator!=(const mint& x) const noexcept { return not((*this) == x); }
    explicit operator bool() const noexcept { return this->num != 0; }
    explicit operator int() const noexcept { return this->num; }

    mint pow(mint _n) {
        mint r = mint(*this);
        mint re = 1;
        int n = (int)_n;
        for (; n; n /= 2) {
            if (n & 1) re *= r;
            r *= r;
        }
        return re;
    }

    mint inv() { return this->pow(MOD - 2); }

    friend ostream& operator<<(ostream&, const mint&);
};

ostream& operator<<(ostream& stream, const mint& x) { return stream << x.num; }

void yn(bool tf) { print(tf ? "Yes" : "No"); }
void YN(bool tf) { print(tf ? "YES" : "NO"); }

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
// -------------------------------------------------------------------
// sort 1 2 3 4
// pqr 1 2 3 must impl >

signed main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<mint> a(n);
    int tmp;
    rep (i, n) {
        cin >> tmp;
        a[i] = mint(tmp);
    }
    vector<mint> rui(n);
    rui[0] = a[0];
    For(i, 1, n - 1) rui[i] = rui[i - 1] + a[i];

    mint ans = 0;
    For(i, 1, n - 1) ans += a[i] * rui[i - 1];

    print(ans);

    return 0;
}
