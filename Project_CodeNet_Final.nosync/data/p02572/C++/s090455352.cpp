#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

class ModInt
{
public:
    int64_t x;
    ModInt(int64_t x = 0) : x((x % MOD + MOD) % MOD) {}
    ModInt operator-() const { return ModInt(-x); }
    ModInt &operator+=(const ModInt a)
    {
        if ((x += a.x) >= MOD)
            x -= MOD;
        return *this;
    }
    ModInt &operator-=(const ModInt a)
    {
        if ((x += MOD - a.x) >= MOD)
            x -= MOD;
        return *this;
    }
    ModInt &operator*=(const ModInt a)
    {
        (x *= a.x) %= MOD;
        return *this;
    }
    ModInt operator+(const ModInt a) const { return ModInt(*this) += a; }
    ModInt operator-(const ModInt a) const { return ModInt(*this) -= a; }
    ModInt operator*(const ModInt a) const { return ModInt(*this) *= a; }
    ModInt pow(int64_t n) const
    {
        if (n == 0)
            return 1;
        ModInt t = pow(n >> 1);
        t *= t;
        if (n & 1)
            t *= *this;
        return t;
    }
    ModInt inv() const { return pow(MOD - 2); }
    ModInt &operator/=(const ModInt a) { return *this *= a.inv(); }
    ModInt operator/(const ModInt a) const { return ModInt(*this) /= a; }
};
istream &operator>>(istream &is, const ModInt &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x; }

void solve(int N, vector<int> A)
{
    vector<ModInt> acc(N + 1);
    for (int i = N - 1; i >= 0; i--)
    {
        acc.at(i) = acc.at(i + 1) + A.at(i);
    }
    ModInt res = 0;
    for (int i = 0; i < N - 1; i++)
    {
        res += acc.at(i + 1) * A.at(i);
    }
    cout << res << endl;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }
    solve(N, move(A));
    return 0;
}
