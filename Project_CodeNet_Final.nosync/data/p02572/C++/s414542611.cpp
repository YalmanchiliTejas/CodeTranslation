#include <bits/stdc++.h>
using namespace std;
#define all(n) begin(n), end(n)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
const int MAX_N = 1e6 + 1;
vector<long long> factorialMemo(MAX_N, -1);        //factorialMemo[i] := i! mod p
vector<long long> inverseFactorialMemo(MAX_N, -1); // inverseFactorialMemo[i] := (factorialMemo[i])^(-1)
bool initFinished = false;
template <long long mod>
struct ModInt
{
    long long x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p)
    {
        if ((x += p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p)
    {
        if ((x += mod - p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p)
    {
        x = (1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p)
    {
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

    ModInt inverse() const
    {
        long long a = x, b = mod, u = 1, v = 0, t;
        while (b > 0)
        {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const
    {
        ModInt ret(1), mul(x);
        while (n > 0)
        {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p)
    {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a)
    {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    static long long get_mod() { return mod; }
    static void factorialInit()
    {
        factorialMemo[0]=1;
        for (ll i = 0; i < MAX_N-1; i++)
        {
            factorialMemo[i+1]=ModInt<mod>(factorialMemo[i]*(i+1)).x;
        }
        initFinished=true;
    }
    static ModInt factorial(ll n)
    {
        if(!initFinished)
        {
            factorialInit();
        }
        return factorialMemo[n];
    }
    
    static ModInt Combination(ll n, ll k)
    {
        if (n < k)
            return 0;
        return factorial(n) / (factorial(n - k) * factorial(k));
    }
};
using mint = ModInt<(int)1e9+7>;
int main()
{
    int N;
    cin>>N;
    vector<mint> A(N),acc(N+1);
    for (size_t i = 0; i < N; i++)
    {
        cin>>A[i];
    }
    partial_sum(all(A),acc.begin()+1);
    mint ans = 0;
    for (size_t i = 0; i < N; i++)
    {
        ans += A[i]*(acc.back()-acc[i+1]);
    }
    cout<<ans;
    return 0;
}