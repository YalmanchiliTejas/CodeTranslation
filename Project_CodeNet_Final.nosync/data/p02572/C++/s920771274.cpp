#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rag(con) std::begin(con), std::end(con)

constexpr ll mod = 1e9 + 7;

ll pow(ll x, ll m)
{

    ll re = 1, y = 1;

    for (int i = 0; i < 60; ++i)
    {
        if (m & y)
            re = re * x % mod;
        x = x * x % mod;
        y *= 2;
    }

    return re;
}

ll inv(ll x)
{

    return pow(x, mod - 2);
}

class mint
{
    ll num = 0;

public:
    mint(ll x = 0) : num(x) {}

    mint operator+(const mint &rhs) const
    {
        return (num + rhs.num) % mod;
    }
    mint operator*(const mint &rhs) const
    {
        return num * rhs.num % mod;
    }
    mint operator-(const mint &rhs) const
    {
        return (num - rhs.num + mod) % mod;
    }
    mint operator/(const mint &rhs) const
    {
        return num * inv(rhs.num) % mod;
    }
    mint operator+=(const mint &rhs)
    {
        return *this = *this + rhs;
    }
    mint operator*=(const mint &rhs)
    {
        return *this = *this * rhs;
    }
    mint operator-=(const mint &rhs)
    {
        return *this = *this - rhs;
    }
    mint operator/=(const mint &rhs)
    {
        return *this = *this / rhs;
    }
    friend std::ostream &operator<<(std::ostream &os, const mint &rhs);
};

std::ostream &operator<<(std::ostream &os, const mint &rhs)
{

    os << rhs.num;

    return os;
}

int main()
{
    int n;

    std::cin >> n;

    std::vector<int> a(n);

    std::vector<mint> b(n);

    rep(i, n)
            std::cin >>
        a[i];

    for (int i = n - 2; i >= 0; --i)
        b[i] = b[i + 1] + (mint)a[i + 1];

    mint ans = 0;

    rep(i, n - 1)
    {
        ans += (mint)a[i] * b[i];
    }

    std::cout << ans << std::endl;

    return 0;
}