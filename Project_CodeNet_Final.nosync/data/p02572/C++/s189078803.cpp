#include <bits/stdc++.h>

#define debug(s) cout << s << endl
#define debug1(s, t) cout << s << " " << t << endl
#define debug2(s, t, u) cout << s << " " << t << " " << u << endl
#define printvec(v)       \
    for (auto &&i : v)    \
        cout << i << " "; \
    cout << endl
#define rep(n, i) for (int i = 0; i < n; i++)

using namespace std;
using i64 = long long;

template <int MOD>
struct Fp
{
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD)
    {
        if (val < 0)
            val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator-() const noexcept
    {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator+(const Fp &r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator-(const Fp &r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator*(const Fp &r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator/(const Fp &r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp &operator+=(const Fp &r) noexcept
    {
        val += r.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr Fp &operator-=(const Fp &r) noexcept
    {
        val -= r.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr Fp &operator*=(const Fp &r) noexcept
    {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp &operator/=(const Fp &r) noexcept
    {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b)
        {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr Fp &operator++() noexcept
    {
        val++;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr Fp operator++(int) noexcept
    {
        Fp temp = *this;
        ++*this;
        return temp;
    }
    constexpr Fp &operator--() noexcept
    {
        val--;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr Fp operator--(int) noexcept
    {
        Fp temp = *this;
        --*this;
        return temp;
    }
    constexpr bool operator==(const Fp &r) const noexcept
    {
        return this->val == r.val;
    }
    constexpr bool operator!=(const Fp &r) const noexcept
    {
        return this->val != r.val;
    }
    friend constexpr ostream &operator<<(ostream &os, const Fp<MOD> &x) noexcept
    {
        return os << x.val;
    }
};

template <int MOD>
constexpr Fp<MOD> powmod(const Fp<MOD> &a, long long n) noexcept
{
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return a * powmod(a, n - 1);
    Fp<MOD> pwmd = powmod(a, n / 2);
    return pwmd * pwmd;
}

using mint = Fp<1000000007>;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // 部分和
    vector<mint> parsum(N);
    mint ps = 0;
    for (int i = N - 1; i >= 1; i--)
    {
        ps += A[i];
        parsum[i] = ps;
    }

    // printvec(parsum);

    mint overallsum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        overallsum += (mint)A[i] * parsum[i + 1];
        // debug(overallsum);
    }

    cout << overallsum << endl;

    return 0;
}