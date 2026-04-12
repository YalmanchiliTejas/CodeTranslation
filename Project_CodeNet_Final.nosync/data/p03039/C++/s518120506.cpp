#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

template <long long mod>
class Mod
{
public:
    long long value;
    Mod(long long x = 0)
    {
        set_value(x);
    }

    void set_value(const long long x)
    {
        this->value = x % mod;
    }

    friend ostream &operator<<(ostream &os, const Mod &x)
    {
        os << x.value;
        return os;
    }

    bool operator<(const long long x)
    {
        return this->value < x;
    }

    bool operator<(Mod<mod> x)
    {
        return *this < x.value;
    }

    bool operator<=(const long long x)
    {
        return this->value <= x;
    }

    bool operator<=(Mod<mod> x)
    {
        return *this <= x.value;
    }

    bool operator>(const long long x)
    {
        return this->value > x;
    }

    bool operator>(Mod<mod> x)
    {
        return *this > x.value;
    }

    bool operator>=(const long long x)
    {
        return this->value >= x;
    }

    bool operator>=(Mod<mod> x)
    {
        return *this >= x.value;
    }

    bool operator==(const long long x)
    {
        return this->value == x;
    }

    bool operator==(Mod<mod> x)
    {
        return *this == x.value;
    }

    Mod<mod> &operator=(const long long x)
    {
        set_value(x);
        return *this;
    }

    Mod<mod> &operator=(const Mod<mod> x)
    {
        *this = x.value;
        return *this;
    }

    Mod<mod> &operator+=(const long long x)
    {
        this->value = (this->value + x) % mod;
        return *this;
    }

    Mod<mod> &operator+=(const Mod<mod> x)
    {
        *this += x.value;
        return *this;
    }

    Mod<mod> &operator-=(const long long x)
    {
        this->value = (this->value - x) % mod;
        return *this;
    }

    Mod<mod> &operator-=(const Mod<mod> x)
    {
        *this -= x.value;
        return *this;
    }

    Mod<mod> &operator*=(const long long x)
    {
        this->value = (this->value * x) % mod;
        return *this;
    }

    Mod<mod> &operator*=(const Mod<mod> x)
    {
        *this *= x.value;
        return *this;
    }

    Mod<mod> &operator/=(const long long x)
    {
        long long a = x;
        long long b = mod;
        long long u = 1;
        long long v = 0;
        while (b)
        {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        u %= mod;
        if (u < 0)
            u += mod;
        *this *= Mod<mod>(u);
        return *this;
    }

    Mod<mod> &operator/=(const Mod<mod> x)
    {
        *this /= x.value;
        return *this;
    }

    Mod<mod> operator+(const long long x) const
    {
        return Mod<mod>(*this) += x;
    }

    Mod<mod> operator+(const Mod<mod> x) const
    {
        return Mod<mod>(*this) += x;
    }

    Mod<mod> operator-(const long long x) const
    {
        return Mod<mod>(*this) -= x;
    }

    Mod<mod> operator-(const Mod<mod> x) const
    {
        return Mod<mod>(*this) -= x;
    }

    Mod<mod> operator*(const long long x) const
    {
        return Mod<mod>(*this) *= x;
    }

    Mod<mod> operator*(const Mod<mod> x) const
    {
        return Mod<mod>(*this) *= x;
    }

    Mod operator/(const long long x) const
    {
        return Mod(*this) /= x;
    }

    Mod<mod> operator/(const Mod<mod> x) const
    {
        return Mod<mod>(*this) /= x;
    }

    Mod<mod> &operator++()
    {
        *this += 1;
        return *this;
    }

    Mod &operator--()
    {
        *this -= 1;
        return *this;
    }

    Mod<mod> operator++(auto)
    {
        Mod<mod> ret(*this);
        ++*this;
        return ret;
    }

    Mod<mod> operator--(auto)
    {
        Mod<mod> ret(*this);
        --*this;
        return ret;
    }
};

template <typename T, typename U>
T calcCombination(T x, U y)
{
    if (x < y)
    {
        return 0;
    }

    if ((x - y) < y)
    {
        T y = x - y;
    }

    T ans = 1;
    for (T i = 1; i <= y; i++)
    {
        ans *= x;
        ans /= i;
        x--;
    }
    return ans;
}

int main()
{
    Mod<MOD> N(0);
    Mod<MOD> M(0);
    Mod<MOD> K(0);
    cin >> N.value >> M.value >> K.value;

    Mod<MOD> ans(0);
    Mod<MOD> coef(calcCombination(N * M - 2, K - 2));
    for (Mod<MOD> i = 1; i < N; i++)
    {
        ans += (N - i) * M * M * i * coef;
    }

    for (Mod<MOD> i = 1; i < M; i++)
    {
        ans += (M - i) * N * N * i * coef;
    }
    cout << ans << endl;
}
