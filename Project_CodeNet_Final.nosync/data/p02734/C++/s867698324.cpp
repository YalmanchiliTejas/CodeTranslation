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
    constexpr long long MOD = 998244353;
    int N, S;
    cin >> N >> S;
    vector<int> A(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    // (1 + x ^ A[0]) (1 + x ^ A[1]) ... (1 + x ^ A[N - 1])

    // P[0] P[1] ... P[N - 1]

    // P[0] +
    // P[0] P[1] + P[1] +
    // P[0] P[1] P[2] + P[1] P[2] + P[2] +
    // ...

    // P[0] +
    // P[1] (P[0] + 1) +
    // P[2] (P[1] (P[0] + 1) + 1) +
    // ...

    // Q[0] = P[0]
    // Q[1] = P[1] (Q[0] + 1)
    // Q[2] = P[2] (Q[1] + 1)
    // ...

    vector<vector<Mod<MOD>>> q(N + 1, vector<Mod<MOD>>(S + 1, 0));
    Mod<MOD> ans = 0;
    for (int i = 1; i <= N; i++)
    {
        q[i - 1][0]++;
        for (int j = 0; j <= S; j++)
        {
            q[i][j] += q[i - 1][j];
            if (A[i] + j <= S)
            {
                q[i][A[i] + j] += q[i - 1][j];
            }
        }
        ans += q[i].back();
    }

    cout << ans << endl;
}
