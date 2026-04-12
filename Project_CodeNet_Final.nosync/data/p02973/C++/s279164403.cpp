
/*****/

#define TRUE true
//#define FALSE false

#include <bits/stdc++.h>

/**/
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
/**/

using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<long long, long long>;
template <class T>
using vec = vector<T>;
template <class T>
using vec2 = vector<vector<T>>;
template <class T>
using vec3 = vector<vector<vector<T>>>;

constexpr int INF = numeric_limits<int>::max();
constexpr ll INFL = numeric_limits<ll>::max();
constexpr ll MOD = 1000000007; // 10^9+7

#ifdef TRUE

#define rep(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep1(i, n) for (ll i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; --i)
#define rrep1(i, n) for (ll i = (n); i > 0; --i)
#define step(i, a, n) for (ll i = (a), i##_len = (a) + (n); i < i##_len; ++i)
#define rstep(i, a, n) for (ll i = (a) + (n)-1, i##_len = (a); i >= i##_len; --i)
#define range(i, a, b) for (ll i = (a), i##_len = (b); i < i##_len; ++i)
#define rrange(i, a, b) for (ll i = (b)-1, i##_len = (a); i >= i##_len; --i)

std::string strMulti(const int n, const std::string &t)
{
    std::string out = "";
    for (int i = 0; i < n; i++)
    {
        out += t;
    }
    return out;
}
std::string tab(const int n)
{
    return string(n, '\t');
}
std::string join(const vector<string> &v, const char *delim = 0)
{
    std::string s;
    if (!v.empty())
    {
        s += v[0];
        for (decltype(v.size()) i = 1, c = v.size(); i < c; ++i)
        {
            if (delim)
                s += delim;
            s += v[i];
        }
    }
    return s;
}

string to_string(string &s) { return '"' + s + '"'; }
string to_string(char &c) { return string({'\'', c, '\''}); }
template <class T1, class T2>
string to_string(pair<T1, T2> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <class Tuple, size_t... I>
string _to_string_tuple(Tuple &&t, std::index_sequence<I...>) { return "(" + join({to_string(std::get<I>(t))...}, ", ") + ")"; }
template <class... Args>
string to_string(tuple<Args...> t) { return _to_string_tuple(std::forward<tuple<Args...>>(t), std::make_index_sequence<std::tuple_size<std::decay_t<tuple<Args...>>>::value>{}); }
template <class T>
string to_string(vector<T> ar)
{
    vector<string> texts(ar.size());
    for (size_t i = 0; i < ar.size(); ++i)
    {
        texts[i] = to_string(ar[i]);
    }
    return "{" + join(texts, ", ") + "}";
}
template <class T>
string to_string(set<T> s)
{
    vector<string> texts(s.size());
    int i = 0;
    for (auto e : s)
    {
        texts[i] = to_string(e);
        i++;
    }
    return "{" + join(texts, ", ") + "}";
}
template <class T1, class T2>
string to_string(map<T1, T2> m)
{
    vector<string> texts(m.size());
    int i = 0;
    for (auto e : m)
    {
        texts[i] = to_string(e);
        i++;
    }
    return "{" + join(texts, ", ") + "}";
}
template <class T>
string to_string(initializer_list<T> il)
{
    vector<string> texts(il.size());
    size_t i = 0;
    for (T v : il)
    {
        texts[i] = to_string(v);
        i++;
    }
    return "{" + join(texts, ", ") + "}";
}

void debug(string name);
void debugn(string name);
template <class T>
void debug(string name, T v);
template <class T>
void debugn(string name, T v);
template <class T>
void debug(string name, initializer_list<T> il);
template <class T>
void debugn(string name, initializer_list<T> il);
template <class... Args>
void debug(string name, Args... args);
template <class... Args>
void debugn(string name, Args... args);
void debugdo(function<void()> func);

#ifdef DEBUG_BUILD
#define debugvar(x) debugn(#x, (x))
#define debugvartab(x, t) debugn(tab(t) + #x, (x))
void debug(string name)
{
    std::cerr << name;
}
void debugn(string name) { std::cerr << name << '\n'; }
template <class T>
void debug(string name, T v) { std::cerr << name << " = " << to_string(v); }
template <class T>
void debugn(string name, T v) { std::cerr << name << " = " << to_string(v) << '\n'; }
template <class T>
void debug(string name, initializer_list<T> il) { std::cerr << name << " = " << to_string(il); }
template <class T>
void debugn(string name, initializer_list<T> il) { std::cerr << name << " = " << to_string(il) << '\n'; }
template <class... Args>
void debug(string name, Args... args) { std::cerr << name << " = " << to_string(tuple<Args...>(args...)); }
template <class... Args>
void debugn(string name, Args... args) { std::cerr << name << " = " << to_string(tuple<Args...>(args...)) << '\n'; }
void debugdo(function<void()> func) { func(); }
#else
#define debugvar(x)
#define debugvartab(x, t)
void debug(string name)
{
}
void debugn(string name) {}
template <class T>
void debug(string name, T v) {}
template <class T>
void debugn(string name, T v) {}
template <class T>
void debug(string name, initializer_list<T> il) {}
template <class T>
void debugn(string name, initializer_list<T> il) {}
template <class... Args>
void debug(string name, Args... args) {}
template <class... Args>
void debugn(string name, Args... args) {}
void debugdo(function<void()> func) {}
#endif

#define all(x) (x).begin(), (x).end()
#define pair(a, b) make_pair(a, b)

template <class T>
bool chmax(T &a, const T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T divup(const T a, const T b) { return (a + (b - 1)) / b; }
template <class T>
bool cmp_2nd(pair<T, T> a, pair<T, T> b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}
ll modpow(ll x, ll n, const ll &p)
{
    ll ret = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            (ret *= x) %= p;
        }
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}
template <class T>
T modinv(T a, const T &p)
{
    T b = p, u = 1, v = 0;
    while (b)
    {
        T t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= p;
    if (u < 0)
    {
        u += p;
    }
    return u;
}
template <class T>
T math_P(T m, T n)
{
    T ret = 1;
    for (T i = m; i > m - n; i--)
    {
        ret *= i;
    }
    return ret;
}
template <class T>
T math_C(T m, T n)
{
    T ret = math_P(m, n);
    for (T i = 2; i <= n; i++)
    {
        ret /= i;
    }
    return ret;
}
ll extended_euclidean(ll u, ll v)
{
    ll r0 = u;
    ll r1 = v;
    ll s0 = 1;
    ll s1 = 0;
    ll t0 = 0;
    ll t1 = 1;
    while (r1 != 0)
    {
        ll q = r0 / r1;
        ll r = r0 - q * r1;
        ll s = s0 - q * s1;
        ll t = t0 - q * t1;
        r0 = r1;
        s0 = s1;
        t0 = t1;
        r1 = r;
        s1 = s;
        t1 = t;
    }
    if (t0 < 0)
    {
        return t0 + u;
    }
    else
    {
        return t0;
    }
}
ll math_C_mod(ll n, ll c, const ll &p)
{
    ll upe = 1;
    ll dow = 1;
    for (ll i = 1; i < c + 1; ++i)
    {
        upe = upe * n % p;
        dow = dow * i % p;
        n -= 1;
    }
    return (upe * extended_euclidean(p, dow)) % p;
}
template <class T>
T math_gcd(T a, T b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return math_gcd(b, a % b);
    }
}
template <class T>
T math_lcm(T a, T b) { return a / math_gcd(a, b) * b; }
template <class T>
T SumStep(T a, T n, T d) { return n * (2 * a + (n - 1) * d) / 2; }
template <class T>
T SumRange(T a, T b, T d) { return SumStep(a, (b - a) / d, d); }

#endif

/*****/

void Main()
{
    int N;
    cin >> N;
    vec<ll> A(N);
    rep(i, N) cin >> A[i];

    vec<ll> C;
    C.emplace_back(-A[0]);
    range(i, 1, N)
    {
        debugvar(i);

        auto itr = upper_bound(all(C), -A[i]);

        debugvartab(itr - C.begin(), 1);

        if (itr == C.end())
        {
            C.emplace_back(-A[i]);
        }
        else
        {
            *itr = -A[i];
        }

        debugvartab(C, 1);
    }

    cout << C.size() << endl;
}

/*****/

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cout << std::fixed << std::setprecision(10);

    Main();
    std::cerr << flush;
    std::cout << flush;

    return 0;
}
