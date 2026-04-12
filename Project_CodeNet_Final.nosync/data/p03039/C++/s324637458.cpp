#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
using namespace std;

typedef long long ll;

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

// MOD付き計算だけでもできるように計算は別クラスで
// static付き
class ModCalcBase 
{
  using mod_type = long long;
  static constexpr mod_type M = 1000000007;
public:
  template <class Reference, class Body>
  static void add(Reference& lval, Body body) noexcept
  {
    lval += (Reference)body % M;
    lval %= M;
  }

  template <class Reference, class Thead, class ...Args>
  static void add(Reference& lval, Thead head, Args... body) noexcept
  {
    lval += (Reference)head % M;
    lval %= M;
    add(lval, body...);
  }

  template <class Reference, class Body>
  static void mul(Reference& lval, Body body) noexcept
  {
    lval *= (Reference)body % M;
    lval %= M;
  }

  template <class Reference, class Thead, class ...Args>
  static void mul(Reference& lval, Thead head, Args... body) noexcept
  {
    lval *= (Reference)head % M;
    lval %= M;
    mul(lval, body...);
  }

  // 返り値が負数になってはいけない
  template <class Reference, class Body>
  static void sub(Reference& lval, Body body) noexcept
  {
    lval -= (Reference)body % M;
    lval += M;
    lval %= M;
  }

  template <class Reference, class Thead, class ...Args>
  static void sub(Reference& lval, Thead head, Args... body) noexcept
  {
    lval -= (Reference)head % M;
    lval += M;
    lval %= M;
    sub(lval, body...);
  }
};

// こっちのクラスは値を持つ。operatorを実装しているのでいろいろできる。
class ModCalc : public ModCalcBase 
{
  using value_type = long long;
  using reference = value_type&;
public:
  value_type value;
  
  ModCalc(value_type value = 0)
    : value(value) {}

  // 値の変更はメソッドを使って欲しい。。。
  const value_type&
  operator ()() const
  {
    return value;
  }

  value_type
  operator +(const ModCalc& rhs) const noexcept
  {
    value_type tmp = value;
    add(tmp, rhs.value);
    return tmp;
  }

  value_type
  operator -(const ModCalc& rhs) const noexcept
  {
    value_type tmp = value;
    sub(tmp, rhs.value);
    return tmp;
  }

  value_type 
  operator *(const ModCalc& rhs) const noexcept
  {
    value_type tmp = value;
    mul(tmp, rhs.value);
    return tmp;
  }
    
  ModCalc&
  operator +=(const ModCalc& rhs) noexcept
  {
    add(value, rhs.value);
    return *this;
  }

  ModCalc&
  operator -=(const ModCalc& rhs) noexcept
  {
    sub(value, rhs.value);
    return *this;
  }

  ModCalc&
  operator *=(const ModCalc& rhs) noexcept
  {
    mul(value, rhs.value);
    return *this;
  }

  friend std::ostream& operator <<(std::ostream& os, const ModCalc& rhs);
};

std::ostream& operator <<(std::ostream& os, const ModCalc& rhs)
{
  os << rhs();
  return os;
}

template <uint64_t N>
class Combination {
  using _Tp = long long;
public: 
  array<_Tp, N> fac, finv, inv;

  constexpr
  Combination() {
    init();     
  }

  constexpr
  void init() {
    fac[0] = fac[1] = 1;        
    finv[0] = finv[1] = 1;      
    inv[1] = 1; 
    for(int i = 2; i < N; i++){    
      fac[i] = fac[i-1] * i % MOD;      
      inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;        
      finv[i] = finv[i-1] * inv[i] % MOD;       
    }
  }

  // n!! * k!^(-1) * ((n - k)!)^(-1)   
  constexpr
  _Tp comb(_Tp n, _Tp k) const {
    if (n < k) return 0;        
    if (n < 0 || k < 0) return 0;       
    return fac[n] * (finv[k]* finv[n - k] % MOD) % MOD; 
  }

  constexpr
  _Tp operator ()(_Tp n, _Tp k) const {
    return comb(n, k);
  }
};

int main() {
  ll n,m,k;
  cin >> n >> m >> k;
  ModCalc ans1, ans2;

  ll total = n * m;
  Combination<200100> comb;

  for (int d = 1; d < n; ++d) {
    ans1 += d * (n - d);
  }

  ans1 *= m * m % MOD;

  for (int d = 1; d < m; ++d) {
    ans2 += d * (m - d);
  }

  ans2 *= n * n % MOD;

  ModCalc res(ans1 + ans2);
  res *= comb(total - 2, k - 2);

  cout << res << endl;
}