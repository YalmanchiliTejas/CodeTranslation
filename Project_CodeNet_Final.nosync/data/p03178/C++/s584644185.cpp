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

    friend istream &operator>>(istream &is, Mod &x)
    {
        long long tmp;
        is >> tmp;
        x.set_value(tmp);
        return is;
    }

    friend ostream &operator<<(ostream &os, const Mod &x)
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

    Mod operator++(auto)
    {
        Mod ret(*this);
        ++*this;
        return ret;
    }

    Mod operator--(auto)
    {
        Mod ret(*this);
        --*this;
        return ret;
    }
};

int main()
{
    const long long MOD = 1'000'000'007;

    string K;
    int D;
    cin >> K >> D;

    int N = K.size();

    vector<int> digit(N);
    for (int i = 0; i < N; i++)
    {
        digit[i] = K[i] - '0';
    }

    vector<vector<Mod<MOD>>> dp(N, vector<Mod<MOD>>(D, 0));
    for (int i = 0; i < 10; i++)
    {
        dp.back()[i % D]++;
    }

    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < D; k++)
            {
                dp[i - 1][(j + k) % D] += dp[i][k];
            }
        }
    }

    long long current = 0;
    Mod<MOD> ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < digit[i]; j++)
        {
            ans += dp[i + 1][(2 * D - (current + j)) % D];
        }
        current += digit[i];
        current %= D;
    }
    for (int i = 0; i <= digit.back(); i++)
    {
        if ((current + i) % D == 0)
        {
            ans++;
        }
    }

    // minus 1 to remove 0
    cout << ans - 1 << endl;
}
