#pragma region Header
#ifdef DEBUG
#include "debug.hpp"
#else
#define NDEBUG
#define debug(...)
#define IFD(...)
#endif
#include <utility>
#include <cstdint>
#include <cmath>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <string>
#include <functional>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <iostream>
#include <iomanip>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); ++i)
#define repd(i, n) for (int i = static_cast<int>(n) - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = static_cast<int>(a); i <= static_cast<int>(b); ++i)
#define FORD(i, b, a) for (int i = static_cast<int>(b); i >= static_cast<int>(a); --i)
template <typename T>
int SZ(T const &x)
{
    return static_cast<int>(x.size());
}
template <class T>
bool chmax(T &a, T const &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, T const &b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}
// 素数 p に対する \mathbb{F}_p の実装
// 四則演算, ++, --, pow, inv, ==

// 使い方
// constexpr int mod = 998244353;
// using m32 = mint<mod>;
// m32 x;

#pragma region Header
#include <stdexcept>
#include <cstdint>
using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#pragma endregion

// F_pを表すクラス
template <u32 p>
struct mint
{
private:
    u32 data; // in [0,p)

    constexpr static inline i64 p_i64 = static_cast<i64>(p);

public:
    constexpr mint() noexcept
        : data(0) {}

    constexpr mint(i64 const x) noexcept
        : data(static_cast<u32>((x % p_i64 >= 0) ? x % p_i64 : x % p_i64 + p_i64)) {}

    constexpr mint(u32 const x, bool const) noexcept
        : data(x) {}

    // convert to u32
    constexpr u32 const &val() const noexcept
    {
        return data;
    }

    constexpr mint &operator+=(mint const x) noexcept
    {
        data += x.data;
        if (data >= p)
        {
            data -= p;
        }
        return *this;
    }

    constexpr mint &operator-=(mint const x) noexcept
    {
        if (data < x.data)
        {
            data += p;
        }
        data -= x.data;
        return *this;
    }

    constexpr mint &operator*=(mint const x) noexcept
    {
        data = static_cast<u32>(static_cast<u64>(data) * x.data % p);
        return *this;
    }

    constexpr mint &operator/=(mint x)
    {
        if (x.data == 0)
        {
            throw domain_error("Division by mint zero");
        }
        u32 exp = p - 2;
        // (*this) * (x ** exp) : invariant
        while (exp > 0)
        {
            if (exp & 1)
            {
                *this *= x;
            }
            x *= x;
            exp /= 2;
        }
        return *this;
    }

    constexpr mint &operator++() noexcept
    {
        return *this += mint(1, true);
    }

    constexpr mint operator++(int) noexcept
    {
        mint const ret(*this);
        ++(*this);
        return ret;
    }

    constexpr mint &operator--() noexcept
    {
        return *this -= mint(1, true);
    }

    constexpr mint operator--(int) noexcept
    {
        mint const ret(*this);
        --(*this);
        return ret;
    }

    constexpr mint operator-() const noexcept
    {
        return mint(0, true) -= *this;
    }

    constexpr mint operator+(mint const x) const noexcept
    {
        return mint(*this) += x;
    }

    constexpr mint operator-(mint const x) const noexcept
    {
        return mint(*this) -= x;
    }

    constexpr mint operator*(mint const x) const noexcept
    {
        return mint(*this) *= x;
    }

    constexpr mint operator/(mint const x) const
    {
        return mint(*this) /= x;
    }

    // x >= 0 のときべき乗を計算
    constexpr mint pow(u64 exp) const noexcept
    {
        mint ret(1, true), base(*this);
        // ret * (base ** exp) : invariant, == (*this) ** x
        while (exp > 0)
        {
            if (exp & 1)
            {
                ret *= base;
            }
            base *= base;
            exp /= 2;
        }
        return ret;
    }

    constexpr mint inv() const noexcept
    {
        return mint(1, true) /= *this;
    }

    constexpr bool operator==(mint const x) const noexcept
    {
        return data == x.data;
    }
};
#pragma endregion

constexpr u32 mod = 1000'000'007;
using m32 = mint<mod>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;
    vector a_s(n, 0);
    rep(i, n)
    {
        cin >> a_s[i];
    }
    
    m32 diag = accumulate(a_s.begin(), a_s.end(), m32(), [](m32 acc, int x) {
        return acc + m32(x) * m32(x);
    });
    m32 suma = accumulate(a_s.begin(), a_s.end(), m32(), [](m32 acc, int x) {
        return acc + m32(x);
    });
    cout << ((suma * suma - diag) / 2).val() << endl;

    return 0;
}
