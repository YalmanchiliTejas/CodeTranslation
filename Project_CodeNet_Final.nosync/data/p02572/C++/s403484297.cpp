#include <bits/stdc++.h>
using namespace std;

template <long long mod>
class Mod
{
    long long value;
    void set_value(const long long x)
    {
        this->value = x % mod;
    }

public:
    Mod()
    {
        set_value(0ll);
    }

    template <typename T>
    Mod(T x = 0)
    {
        set_value((long long)x);
    }

    friend std::istream &operator>>(std::istream &is, Mod &x)
    {
        long long tmp;
        is >> tmp;
        x.set_value(tmp);
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const Mod &x)
    {
        os << x.value;
        return os;
    }

    operator long long() const
    {
        return this->value;
    }

    template <typename T>
    bool operator<(const T x)
    {
        return this->value < (long long)x;
    }

    template <typename T>
    bool operator<=(const T x)
    {
        return this->value <= (long long)x;
    }

    template <typename T>
    bool operator>(const T x)
    {
        return this->value > (long long)x;
    }

    template <typename T>
    bool operator>=(const T x)
    {
        return this->value >= (long long)x;
    }

    template <typename T>
    bool operator==(const T x)
    {
        return this->value == (long long)x;
    }

    template <typename T>
    Mod &operator=(const T x)
    {
        set_value((long long)x);
        return *this;
    }

    template <typename T>
    Mod &operator&=(const T x)
    {
        set_value(this->value & (long long)x);
        return *this;
    }

    template <typename T>
    Mod &operator|=(const T x)
    {
        set_value(this->value | (long long)x);
        return *this;
    }

    template <typename T>
    Mod &operator^=(const T x)
    {
        set_value(this->value ^ (long long)x);
        return *this;
    }

    template <typename T>
    Mod &operator<<=(const T x)
    {
        set_value(this->value << (long long)x);
        return *this;
    }

    template <typename T>
    Mod &operator>>=(const T x)
    {
        set_value(this->value >> (long long)x);
        return *this;
    }

    template <typename T>
    Mod &operator+=(const T x)
    {
        set_value(this->value + (long long)x);
        return *this;
    }

    template <typename T>
    Mod &operator-=(const T x)
    {
        set_value(this->value - (long long)x + mod);
        return *this;
    }

    template <typename T>
    Mod &operator*=(const T x)
    {
        set_value(this->value * (long long)x);
        return *this;
    }

    template <typename T>
    Mod &operator/=(const T x)
    {
        long long a = (long long)x;
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
        *this *= Mod(u);
        return *this;
    }

    template <typename T>
    Mod operator&(const T x) const
    {
        return Mod(*this) &= x;
    }

    template <typename T>
    Mod operator|(const T x) const
    {
        return Mod(*this) |= x;
    }

    template <typename T>
    Mod operator^(const T x) const
    {
        return Mod(*this) ^= x;
    }

    template <typename T>
    Mod operator<<(const T x) const
    {
        return Mod(*this) <<= x;
    }

    template <typename T>
    Mod operator>>(const T x) const
    {
        return Mod(*this) >>= x;
    }

    template <typename T>
    Mod operator+(const T x) const
    {
        return Mod(*this) += x;
    }

    template <typename T>
    Mod operator-(const T x) const
    {
        return Mod(*this) -= x;
    }

    template <typename T>
    Mod operator*(const T x) const
    {
        return Mod(*this) *= x;
    }

    template <typename T>
    Mod operator/(const T x) const
    {
        return Mod(*this) /= x;
    }

    Mod &operator++()
    {
        *this += 1;
        return *this;
    }

    Mod &operator--()
    {
        this->set_value(--this->value);
        return *this;
    }

    Mod operator++(int)
    {
        Mod ret(*this);
        ++*this;
        return ret;
    }

    Mod operator--(int)
    {
        Mod ret(*this);
        --*this;
        return ret;
    }
};

int main()
{
    constexpr long long MOD = 1e9 + 7;
    size_t N;
    cin >> N;

    vector<Mod<MOD>> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<Mod<MOD>> accum(N);
    accum[0] = A[0];
    for (size_t i = 1; i < N; i++)
    {
        accum[i] = accum[i - 1] + A[i];
    }

    Mod<MOD> ans = 0;
    for (size_t i = 1; i < N; i++)
    {
        ans += A[i] * accum[i - 1];
    }

    cout << ans << endl;
}
