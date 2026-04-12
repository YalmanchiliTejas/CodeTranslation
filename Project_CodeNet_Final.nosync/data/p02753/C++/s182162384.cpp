#include <bits/stdc++.h>

using namespace std;

#define DUMP(x) std::cerr << (#x) << " = " << (x) << "\n"
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define EREP(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define RREP(i, a, b) for (int i = (int)(a)-1; i >= (int)(b); --i)
#define rep(i, n) REP(i, 0, n)
#define erep(i, n) EREP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; --i)
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
    for (auto e : m)
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
        for (auto &x : ret)
            x = in();
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

void Main()
{
    string s;
    cin >> s;
    set<char> st;
    rep(i, s.size())
    {
        st.insert(s[i]);
    }
    if (st.size() == 1)
        No;
    else
        Yes;
}

signed main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
