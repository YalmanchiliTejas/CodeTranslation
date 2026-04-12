// 状態: 上からの桁数i(「時刻」)と剰余r, O(D log K)
// 結果: Kの上i桁を数とみたときの、mod D でrとなる個数 (解よりも情報がD個多い)
// 遷移: O(1)

#pragma region Header
#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#define IFD(...)
#ifndef NDEBUG
#define NDEBUG
#endif
#endif
#include <utility>
#include <cstdint>
#include <cmath>
#include <cassert>
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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <boost/hana/functional/fix.hpp>
using boost::hana::fix;
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, b, a) for (int i = (b); i >= (a); --i)
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
#pragma endregion

template <u32 p>
struct modint
{
private:
    u32 data; // in [0,p)

    constexpr static inline i64 p_i64 = static_cast<i64>(p);

public:
    constexpr modint() noexcept
        : data(0) {}

    constexpr modint(i64 const x) noexcept
        : data(static_cast<u32>((x % p_i64 >= 0) ? x % p_i64 : x % p_i64 + p_i64)) {}

    constexpr modint(u32 const x, bool const) noexcept
        : data(x) {}

    // convert to u32
    constexpr u32 const &val() const noexcept
    {
        return data;
    }

    constexpr modint &operator+=(modint const x) noexcept
    {
        data += x.data;
        if (data >= p)
        {
            data -= p;
        }
        return *this;
    }

    constexpr modint &operator-=(modint const x) noexcept
    {
        if (data < x.data)
        {
            data += p;
        }
        data -= x.data;
        return *this;
    }

    constexpr modint &operator*=(modint const x) noexcept
    {
        data = static_cast<u32>(static_cast<u64>(data) * x.data % p);
        return *this;
    }

    constexpr modint &operator/=(modint x)
    {
        if (x.data == 0)
        {
            throw domain_error("Division by modint zero");
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

    constexpr modint &operator++() noexcept
    {
        return *this += modint(1, true);
    }

    constexpr modint operator++(int) noexcept
    {
        modint const ret(*this);
        ++(*this);
        return ret;
    }

    constexpr modint &operator--() noexcept
    {
        return *this -= modint(1, true);
    }

    constexpr modint operator--(int) noexcept
    {
        modint const ret(*this);
        --(*this);
        return ret;
    }

    constexpr modint operator-() const noexcept
    {
        return modint(0, true) -= *this;
    }

    constexpr modint operator+(modint const x) const noexcept
    {
        return modint(*this) += x;
    }

    constexpr modint operator-(modint const x) const noexcept
    {
        return modint(*this) -= x;
    }

    constexpr modint operator*(modint const x) const noexcept
    {
        return modint(*this) *= x;
    }

    constexpr modint operator/(modint const x) const
    {
        return modint(*this) /= x;
    }

    // x >= 0 のときべき乗を計算
    constexpr modint pow(u64 exp) const noexcept
    {
        modint ret(1, true), base(*this);
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

    constexpr modint inv() const noexcept
    {
        return modint(1, true) /= *this;
    }

    constexpr bool operator==(modint const x) const noexcept
    {
        return data == x.data;
    }
};

constexpr u32 mod = 1000'000'007;
using mint = modint<mod>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    vector<int> k;
    {
        string s;
        cin >> s;
        k.resize(s.size());
        transform(s.begin(), s.end(), k.begin(), [](char c) { return (int)c - (int)'0'; });
    }
    int d;
    cin >> d;

    // i桁目までみる -1したやつを[1]に入れる
    vector dp(2, vector<mint>(d, 0)), dptmp(2, vector<mint>(d));
    dp[0][0] = 1;
    rep(i, k.size())
    {
        fill(dptmp[0].begin(), dptmp[0].end(), 0);
        fill(dptmp[1].begin(), dptmp[1].end(), 0);

        rep(a, 10)
        {
            rep(r, d)
            {
                dptmp[0][(r + a) % d] += dp[a <= k[i] ? 0 : 1][r];
                dptmp[1][(r + a) % d] += dp[a <= k[i] - 1 ? 0 : 1][r];
            }
        }

        swap(dp, dptmp);
    }
    cout << (dp[0][0] - 1).val() << '\n';

    return 0;
}
