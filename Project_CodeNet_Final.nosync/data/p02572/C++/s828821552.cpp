#define DEBUG 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<class T>using numr=std::numeric_limits<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const ll LLINF = 1e16;
const int mod = 1000000007;
const int mod2 = 998244353;
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail) { std::cerr << " " << head; debug_impl(tail...); }
#if DEBUG
#define debug(...)\
    do {\
        std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
        debug_impl(__VA_ARGS__);\
        std::cerr << std::noboolalpha;\
    } while (false)
#else
#define debug(...) {}
#endif

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr>
std::istream& operator>> (std::istream& is, Container& v)
    { for (auto & x : v) { is >> x; } return is; }

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr >
std::ostream& operator<< (std::ostream& os, Container const& v) {
os << "{";
    for (auto it = v.begin(); it != v.end(); it++)
        {os << (it != v.begin() ? "," : "") << *it;}
    return os << "}";
}

template< int mod >
struct ModInt {
int x;

ModInt() : x(0) {}

ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
}

ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
}

ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
}

ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
}

ModInt operator-() const { return ModInt(-x); }

ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

bool operator==(const ModInt &p) const { return x == p.x; }

bool operator!=(const ModInt &p) const { return x != p.x; }

ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
    t = a / b;
    swap(a -= t * b, b);
    swap(u -= t * v, v);
    }
    return ModInt(u);
}

ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
    if(n & 1) ret *= mul;
    mul *= mul;
    n >>= 1;
    }
    return ret;
    }

friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
}

friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
}

static int get_mod() { return mod; }
};

using modint = ModInt< mod >;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<modint> a(n);
    cin >> a;
    modint s,s2 = 0;
    for(int i= 0;i<n;i++){
        s += a[i];
        s2 += a[i]*a[i];
    }
    cout << (s*s-s2)/2 << endl;
}