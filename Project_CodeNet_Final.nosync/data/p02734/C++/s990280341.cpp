#include <bits/stdc++.h>

using namespace std;

#define DUMP(x) std::cerr << (#x) << " = " << (x) << "\n"
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define EREP(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define RREP(i, a, b) for (int i = (int)(a)-1; i >= (int)(b); --i)
#define rep(i, n) REP(i, 0, n)
#define erep(i, n) EREP(i, 0, n)
#define rrep(i, n) RREP(i, n, 0)
#define ALL(r) r.begin(), r.end()
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define IMP cout << "IMPOSSIBLE\n"
#define Imp cout << "Impossible\n"
#define imp cout << "impossible\n"
#define M1 cout << "-1\n"
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)
{
    os << "{";
    rep(i, v.size()) os << v[i] << (i == (int)v.size() - 1 ? "" : ", ");
    os << "}";
    return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p) { return (os << "(" << p.first << ", " << p.second << ")"); }
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &m)
{
    bool first = true;
    os << "{";
    for (const auto e : m)
    {
        if (!first)
            os << ", ";
        os << "{" << e.first << ": " << e.second << "}";
        first = false;
    }
    os << "}";
    return os;
}
template <typename T>
T dup(T x, T y) { return (x + y - 1) / y; };
template <typename A, size_t N, typename T>
inline void arrayFill(A (&array)[N], const T &val) { std::fill((T *)array, (T *)(array + N), val); }
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
struct in
{
    const size_t n = 0;
    in() = default;
    in(size_t n) : n(n){};
    template <typename T>
    operator T()
    {
        T ret;
        cin >> ret;
        return ret;
    }
    template <typename T>
    operator vector<T>()
    {
        assert(n != 0);
        vector<T> ret(n);
        for (T &x : ret)
        {
            T tmp = in();
            x = tmp;
        }
        return ret;
    }
    template <typename T, typename U>
    operator pair<T, U>()
    {
        pair<T, U> ret;
        ret.first = in();
        ret.second = in();
        return ret;
    }
};

using ll = int64_t;
using vint = vector<int32_t>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pint = pair<int32_t, int32_t>;
using vpint = vector<pint>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using setint = set<int32_t>;
using setstr = set<string>;
using qint = queue<int32_t>;
using qpint = queue<pint>;

constexpr std::int32_t INF = 1001001001;
constexpr std::int64_t LINF = 1001001001001001001;

// constexpr int mod = 1'000'000'007;
constexpr int mod = 998'244'353;
class mint
{
private:
    std::int64_t m_x;

public:
    mint(std::int64_t m_x = 0) : m_x((m_x % mod + mod) % mod) {}
    std::int64_t get() const { return m_x; }
    mint operator-() const { return mint(-m_x); }
    mint &operator+=(const mint a)
    {
        if ((m_x += a.m_x) >= mod)
            m_x -= mod;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        if ((m_x += mod - a.m_x) >= mod)
            m_x -= mod;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (m_x *= a.m_x) %= mod;
        return *this;
    }
    mint &operator++() { return *this += 1; }
    mint operator++(int)
    {
        mint tmp = *this;
        ++*this;
        return tmp;
    }
    mint operator--() { return *this -= 1; }
    mint operator--(int)
    {
        mint tmp = *this;
        --*this;
        return tmp;
    }
    mint operator+(const mint a) const
    {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const
    {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const
    {
        mint res(*this);
        return res *= a;
    }

    mint pow(const std::int64_t t) const
    {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint &operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const
    {
        mint res(*this);
        return res /= a;
    }
};
istream &operator>>(istream &is, mint &a)
{
    ll x;
    is >> x;
    a = x;
    return is;
}
ostream &operator<<(ostream &os, const mint &a)
{
    os << a.get();
    return os;
}

mint dp[3005][3005][3];

void Main()
{
    int n = in(), s = in();
    vint a = in(n);

    arrayFill(dp, 0);
    dp[0][0][0] = 1;

    rep(i, n) rep(j, 3002)
    {
        dp[i + 1][j][0] += dp[i][j][0];
        dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1];
        dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
        if (j + a[i] <= 3000)
        {
            dp[i + 1][j + a[i]][1] += dp[i][j][0] + dp[i][j][1];
            dp[i + 1][j + a[i]][2] += dp[i][j][0] + dp[i][j][1];
        }
    }
    cout << dp[n][s][2] << endl;
}

signed main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
