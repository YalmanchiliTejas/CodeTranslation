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
string K;
int D;
int keta;
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

using mint = ModInt<(int)1e9 + 7>;
//unordered_map<tuple<int, int, bool>, mint> memo;
vector<vvint> memo(10001, vvint(101, vint(2, -1)));
mint solve(int i, int res, bool smaller) //iケタまで決定したとき、残りの桁で各桁の和をDで割ったあまりがresになるような数字」の数
{
    if (res < 0)
    {
    }
    if (memo[i][res][smaller] != -1)
    {
        return memo[i][res][smaller];
    }
    if (i == keta)
    {
        memo[i][res][smaller] = res == 0;
        return memo[i][res][smaller];
    }
    int now = K[i] - '0';
    if (smaller)
    {
        mint sm = 0;
        rep(j, 10)
        {
            sm += solve(i + 1, ((res - j) % D + D) % D, true);
        }
        memo[i][res][smaller] = sm.x;
        return memo[i][res][smaller];
    }
    else
    {
        mint tmp(0);
        rep(j, now)
        {
            tmp += solve(i + 1, ((res - j) % D + D) % D, true);
        }
        tmp += solve(i + 1, ((res - now) % D + D) % D, false);
        memo[i][res][smaller] = tmp.x;
        return memo[i][res][smaller];
    }
}
int main()
{
    cin >> K >> D;
    keta = K.size();

    cout << solve(0, D, false) - 1;
    return 0;
}