#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

constexpr int SINT_MAX = std::numeric_limits<int>::max();
constexpr int SINT_MIN = std::numeric_limits<int>::min();

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

template<class T>
T choose(bool b, T t, T f)
{
    if (b) return t;
    else return f;    
}

const char *YesNo(bool b)
{
    return choose(b, "Yes", "No");
}

const char *YESNO(bool b)
{
    return choose(b, "YES", "NO");
}

template<class NumT>
NumT diffabs(NumT l, NumT r)
{
    if (l < r) return r-l;
    else return l-r;    
}

struct myinout_t {} io;

template<class T>
myinout_t &operator >>(myinout_t &my, T &i)
{
    cin >> i;
    return my;
}

myinout_t &operator >>(myinout_t &my, int &i)
{
    int r = scanf("%d", &i);
    if (r != 1) exit(EXIT_FAILURE);
    return my;
}

myinout_t &operator >>(myinout_t &my, ll &i)
{
    int r = scanf("%lld", &i);
    if (r != 1) exit(EXIT_FAILURE);
    return my;
}

template<class T>
myinout_t &operator <<(myinout_t &my, const T &i)
{
    cout << i;
    return my;
}

myinout_t &operator <<(myinout_t &my, int i)
{
    printf("%d", i);
    return my;
}

myinout_t &operator <<(myinout_t &my, ll i)
{
    printf("%lld", i);
    return my;
}

myinout_t &operator <<(myinout_t &my, double i)
{
    printf("%.20f", i);
    return my;
}

constexpr char BR = '\n';


#include <iostream>
#include <vector>
#include <numeric>

 
constexpr uint_fast64_t MOD = 1e9 + 7;
 
template<class StoreT, class AddT, class MulT, StoreT MOD>
class ModInt
{
    using self_type = ModInt<StoreT, AddT, MulT, MOD>;
    StoreT i;
 
public:
    using int_type = StoreT;

    ModInt()
        : i(0)
    {}
    ModInt(StoreT i)
    {
        while(i < 0) i += MOD;
        this->i = i;
    }
 
    ModInt(const self_type& i) = default;
    constexpr self_type &operator=(const self_type& i) = default;
 
    constexpr StoreT getI() const noexcept
    {
        return i;
    }

    constexpr static StoreT getMOD() noexcept
    {
        return MOD;
    }
 
    ModInt& operator +=(self_type rhs)
    {
        AddT i64 = static_cast<AddT>(i);
        StoreT a32 = static_cast<StoreT>((i64 + rhs.i) % MOD);
        i = a32;
        return *this;
    }
 
    constexpr ModInt operator +(self_type rhs) const noexcept
    {
        self_type newInt(*this);
        newInt += rhs;
        return newInt;
    }
 
    ModInt& operator -=(self_type rhs)
    {
        AddT i64 = static_cast<AddT>(i);
        StoreT a32 = static_cast<StoreT>((i64 + MOD - rhs.i) % MOD);
        i = a32;
        return *this;
    }
 
    constexpr ModInt operator -(self_type rhs) const noexcept
    {
        self_type newInt(*this);
        newInt -= rhs;
        return newInt;
    }
 
    ModInt& operator *=(self_type rhs)
    {
        MulT i64 = static_cast<MulT>(i);
        StoreT a32 = static_cast<StoreT>((i64 * rhs.i) % MOD);
        i = a32;
        return *this;
    }
 
    constexpr ModInt operator *(self_type rhs) const noexcept
    {
        self_type newInt(*this);
        newInt *= rhs;
        return newInt;
    }
 
    constexpr ModInt operator /(self_type rhs) const noexcept
    {
        self_type newInt(*this);
        self_type rhsInv = rhs.inv();
        newInt *= rhsInv;
        return newInt;
    }
 
    constexpr bool operator ==(self_type rhs) const noexcept
    {
        return i == rhs.i;
    }
 
    constexpr bool operator <(self_type rhs) const noexcept
    {
        return i < rhs.i;
    }
 
    constexpr bool operator >(self_type rhs) const noexcept
    {
        return rhs < *this;
    }
 
    constexpr ModInt pow(int n) const noexcept
    {
        ModInt a = *this;
        ModInt res = 1;
 
        while (n > 0)
        {
            if (n & 1)
            {
                res *= a;
            }
            a *= a;
            n >>= 1;
        }
        return res;
    }

    constexpr static ModInt pow(int base, int n) noexcept
    {
        ModInt b(base);
        return b.pow(n);
    }
 
    constexpr self_type inv() const noexcept
    {
        return pow(MOD - 2);
    }
};
 
template<class StoreT, class AddT, class MulT, StoreT MOD>
std::ostream& operator <<(std::ostream& ost, ModInt<StoreT, AddT, MulT, MOD> i)
{
    ost << i.getI();
    return ost;
}
 
using UModInt = ModInt<uint_fast32_t, uint_fast32_t, uint_fast64_t, MOD>;
using SModInt = ModInt<int_fast32_t, int_fast32_t, int_fast64_t, MOD>;
 

template<class ModIntT>
class BinomialFactory
{
    using int_type = typename ModIntT::int_type;
    std::vector<ModIntT> fac;
    std::vector<ModIntT> finv;
    std::vector<int_type> inv;
 
public:
    explicit BinomialFactory(int_type N)
    : fac(N+1, 1), finv(N+1, 1), inv(N+1, 1)
    {
        const auto MOD = ModIntT::getMOD();
        for (int_type i = 2; i <= N; i++)
        {
            fac[i] = fac[i - 1] * i;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i];
        }
    }
 
    ModIntT bi(int_type n, int_type r) const
    {
        if (r == 0 || r == n) return 1;
 
        return fac[n] * finv[n - r] * finv[r];
    }
};


///////////////////////////////////////////////////

int main()
{
    int N;
    io >> N;
    vi A(N);
    for (int i = 0; i < N; i++)
        io >> A[i];
    
    
    SModInt T, L;
    for (int i = 0; i < N; i++)
    {
        L += A[i];
        SModInt t = A[i];
        t *= A[i];
        T += t;
    }

    SModInt ans = (L * L - T) / 2;
    cout << ans << BR;
}