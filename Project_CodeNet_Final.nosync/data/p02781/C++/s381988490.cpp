#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
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
template <int mod>
struct ModInt
{
    int x;

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
        x = (int)(1LL * x * p.x % mod);
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
        int a = x, b = mod, u = 1, v = 0, t;
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

    static int get_mod() { return mod; }
    static ModInt factorial(ll n)
    {
        ModInt<mod> tmp(n);
        for (int i = 1; i < n; i++)
        {
            tmp *= ModInt<mod>(n - i);
        }
        return tmp;
    }
    static ModInt Combination(ll n, ll k)
    {
        return factorial(n) / (factorial(n - k) * factorial(k));
    }
};
ll Pow(ll x, ll n)
{
    ll ret = 1;
    while (n > 0)
    {
        if (n & 1)
            ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

long long combination(long long N, long long R)
{
    if (R < 0 || R > N)
        return 0;
    if (R == 1)
        return N;
    else if (R == 2)
        return N * (N - 1) / 2;
    else
        return N * (N - 1) * (N - 2) / 6;
}

vector<ll[5][2]> memo;
string N;
int K, keta;
ll solve(int i, int k, bool smaller)
{
    if (k == 0)
    {
        return 1;
    }
    if (i == keta)
    {
        return 0;
    }
    if (smaller)
    {
        return combination(keta - i, k) * pow(9, k);
    }
    if (N[i] == '0')
    {
        return solve(i + 1, k, smaller);
    }
    ll zero = solve(i + 1, k, true);
    ll mid = solve(i + 1, k - 1, true) * (N[i] - '1');
    ll girigiri = solve(i + 1, k - 1, false);
    return zero + mid + girigiri;
}

int main()
{

    cin >> N;
    cin >> K;
    keta = N.size();
    cout << solve(0, K, false);
    return 0;
}