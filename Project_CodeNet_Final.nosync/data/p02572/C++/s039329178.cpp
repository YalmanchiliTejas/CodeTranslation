#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<iostream>
#include<vector>
using namespace std;
using i32 = int_fast32_t;
using i64 = int_fast64_t;
#define rep(i, n) for (i32 i = 0; i < (i32)(n); i++)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using P = pair<i64,i64>;
using i64 = int_fast64_t;
constexpr i64 MAX = 10000000;
constexpr i64 MOD = 1000000007;
i64 fac[MAX], finv[MAX], inv[MAX];
template <i64 modulus>
class modcal
{

public:
  i64 a;

  constexpr modcal(const i64 x = 0) noexcept : a(x % modulus) {}
  constexpr i64 &value() noexcept { return a; }
  constexpr const i64 &value() const noexcept { return a; }
  constexpr modcal operator+(const modcal rhs) const noexcept
  {
    return modcal(*this) += rhs;
  }
  constexpr modcal operator-(const modcal rhs) const noexcept
  {
    return modcal(*this) -= rhs;
  }
  constexpr modcal operator*(const modcal rhs) const noexcept
  {
    return modcal(*this) *= rhs;
  }
  constexpr modcal operator/(const modcal rhs) noexcept
  {
    return modcal(*this) /= rhs;
  }
  constexpr modcal &operator+=(const modcal rhs) noexcept
  {
    a += rhs.a;
    if (a >= modulus)
    {
      a -= modulus;
    }
    return *this;
  }
  constexpr modcal &operator-=(const modcal rhs) noexcept
  {
    if (a < rhs.a)
    {
      a += modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modcal &operator*=(const modcal rhs) noexcept
  {
    a = a * rhs.a % modulus;
    return *this;
  }
  constexpr modcal &operator/=(modcal rhs) noexcept
  {
    i64 exp = modulus - 2;
    while (exp)
    {
      if (exp % 2)
      {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }

  void COMninit()
  {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
      fac[i] = fac[i - 1] * i % modulus;
      inv[i] = MOD - inv[modulus % i] * (modulus / i) % modulus;
      finv[i] = finv[i - 1] * inv[i] % modulus;
    }
  }
  i64 COMn(i64 n, i64 k)
  {
    if (n < k)
      return 0;
    if (n < 0 || k < 0)
      return 0;
    return fac[n] * (finv[k] * finv[n - k] % modulus) % modulus;
  }
  constexpr modcal<1000000007> modpow(const modcal<1000000007> &a, i64 n)
  {
    if (n == 0)
      return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1)
      t = t * a;
    return t;
  }
};
using modc = modcal<1000000007>;
int main(){
ios::sync_with_stdio(false);
std::cin.tie(nullptr);
i64 n;
cin >> n;
vector<i64> a(n);
vector<modc> sum(n + 1);
rep(i,n){
    cin >> a[i];
    sum[i + 1] = sum[i] + a[i];
}
modc ans = 0;
for(i32 i = 1; i <n; i++){
    ans += (sum[n] - sum[i]) * a[i - 1];
}
cout << ans.a << endl;
}