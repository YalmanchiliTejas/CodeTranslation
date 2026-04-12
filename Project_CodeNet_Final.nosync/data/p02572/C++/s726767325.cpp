// 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

template <long long Modulus = 1000000007>
struct MInt
{
    long long x;
    static const long long mod = Modulus;
    
    MInt(long long a = 0) : x((a % mod + mod) % mod) {}

    // operator
    MInt& operator = (const MInt& a)
    {
        x = a.x;
        return *this;
    }
    MInt& operator = (const long long& a)
    {
        *this = MInt(a);
        return *this;
    }

    MInt operator -() const
    { 
        return MInt(-x);
    };

    MInt& operator +=(const MInt& a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }

    MInt& operator -=(const MInt& a)
    {
        if ((x += mod - a.x) > mod)
            x -= mod;
        return *this;
    }

    MInt& operator *=(const MInt& a)
    {
        x *= a.x;
        x = x % mod;
        return *this;
    }

    MInt operator+(const MInt& a) const
    {
        MInt res(*this);
        return res += a;
    }

    MInt operator-(const MInt& a) const
    {
        MInt res(*this);
        return res -= a;
    }

    MInt operator*(const MInt& a) const
    {
        MInt res(*this);
        return res *= a;
    }

    MInt pow(long long t) const
    {
        if (t == 0)
            return 1;
        MInt a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }

    // only for prime mod
    MInt Inv() const
    {
        return pow(mod - 2);
    }
    // only for prime mod
    MInt& operator/=(const MInt& a)
    {
        return (*this) *= a.Inv();
    }
    MInt operator/(const MInt& a) const
    {
        MInt res(*this);
        return res /= a;
    }
};

template <class TMInt = MInt<>>
struct Comb
{
    std::vector<TMInt> fact, invfact, inv;
    long long mod;
    Comb(int n) : fact(n+1), invfact(n+1), inv(n+1)
    {
        fact[0] = fact[1] = 1;
        mod = fact[0].mod;
        invfact[0] = invfact[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < n; ++i)
        {
            fact[i] = fact[i - 1] * TMInt(i);
            long long invx = inv[mod % i].x * (mod - mod / i) % mod;
            inv[i] = TMInt(invx);
            invfact[i] = invfact[i - 1] * inv[i];
        }
    }

    TMInt operator()(int n, int k)
    {
        if (k < 0 || n < k)
            return 0;
        return fact[n] * invfact[k] * invfact[n - k];
    }

    TMInt Perm(int n, int k)
    {
        if (k < 0 || n < k)
            return 0;
        return fact[n] * invfact[n - k];
    }
};

using modint = MInt<>;
using combination = Comb<modint>;


int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    modint ans = 0;

    modint sum = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += A[i];
    }
    
    for (int i = 0; i < N - 1; ++i)
    {
        sum -= A[i];
        modint b = sum * modint(A[i]);
        ans += b;
    }
    cout << ans.x << endl;
    return 0;
}
