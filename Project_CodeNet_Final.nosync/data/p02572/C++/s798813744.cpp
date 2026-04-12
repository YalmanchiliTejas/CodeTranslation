#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PII;

// chmax, chmin
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}

template <typename T>
function<T(T, T)> op_max = [](T a, T b) -> T { return max(a, b); };
template <typename T>
function<T(T, T)> op_min = [](T a, T b) -> T { return min(a, b); };

template <typename T>
function<T(T, T)> op_sum = [](T a, T b) -> T { return a + b; };

using namespace std;
//********************  dumps ************************//

template <typename T>
void dump(const T &data, vector<int> &iter)
{
  cout << data << " ";
}
template <typename T>
void dump(const vector<T> &data, vector<int> &iter)
{
  for (auto elem : data)
    dump(elem, iter);
  cout << endl;
}

template <typename T>
void dump(const vector<vector<T>> &data, vector<int> &iter)
{
  for (auto elem : iter)
  {
    cout << "[" << elem << "]";
  }
  cout << endl;
  for (int i = 0; i < data.size(); i++)
  {
    iter.push_back(i);
    dump(data[i], iter);
    iter.pop_back();
  }
  cout << endl;
}

template <typename T>
void dump(const vector<T> &data, int dummy)
{
  for (int i = 0; i < data.size(); i++)
  {
    cout << "[" << i << "] " << data[i] << endl;
  }
}
template <typename T>
void dump(const T &data)
{ // T : data, U = base type val.
  vector<int> iter;
  dump(data, iter);
}
///////////////////////////////////////////////

const long long MOD = 1000000007;

const long long MOD_CONST = MOD;
long long mul_mod(long long a, long long b, const long long MOD)
{
  return b ? (mul_mod(a * 2, b / 2, MOD) + (b & 1 ? a : 0)) % MOD : 0;
}

long long bpow_mod(long long a, long long b, const long long MOD)
{
  return (b ? bpow_mod(a * a % MOD, b / 2, MOD) * (b & 1 ? a : 1) : 1) % MOD;
}

long long inv_mod(long long a, const long long MOD)
{
  return bpow_mod(a, MOD - 2, MOD);
}
template <long long param = MOD_CONST, bool fast = false>
class mint
{
private:
  using Z = int;
  using N = unsigned int;
  using ZZ = long long;
  using NN = unsigned long long;
  struct
  {
  } constexpr static exact{};
  // Using Z deliberately to avoid Z -> N promotion.
  template <class Ret = ZZ &>
  static auto modulo() -> std::enable_if_t<(param <= 0), Ret>
  {
    static ZZ mod = 0;
    return mod;
  }
  template <class Ret = const ZZ>
  static auto mod() -> std::enable_if_t<(param <= 0), Ret>
  {
    return modulo();
  }
  template <class Ret = const ZZ>
  static constexpr auto mod() -> std::enable_if_t<(param > 0), Ret>
  {
    return param;
  }

public:
  template <class Arg = ZZ>
  static void set_modulo(const std::enable_if_t<(param <= 0), Arg> mod)
  {
    modulo() = mod;
  }
  long long v;

  constexpr mint() : v(0) {}

  constexpr mint(long long v)
      : v(fast ? (v)
               : (v < 0 ? (v % mod() + mod()) % mod()
                        : (v >= mod() ? v % mod() : v))) {}
  constexpr long long get_mod() { return mod(); }
  long long get_val() { return v; }
  void take_mod() { v %= mod(); }
};
template <long long param, bool fast>
ostream &operator<<(ostream &os, mint<param, fast> &x)
{
  return os << (x.v % x.get_mod() + x.get_mod()) % x.get_mod();
}

template <long long param, bool fast, bool fast2>
bool operator==(mint<param, fast> &a, mint<param, fast2> b)
{
  return a.v == b.v;
}
template <long long param, bool fast, bool fast2>
mint<param, fast> &operator+=(mint<param, fast> &a, mint<param, fast2> b)
{
  return a = a.v + b.v;
}
template <long long param>
mint<param> &operator-=(mint<param> &a, mint<param> b)
{
  return a = a.v - b.v;
}
template <long long param>
mint<param> &operator*=(mint<param> &a, mint<param> b)
{
  return a = a.v * b.v;
}
template <long long param>
mint<param> &operator/=(mint<param> &a, mint<param> b)
{
  return a = a.v * inv_mod(b.v, a.get_mod());
}
template <long long param, bool fast, bool fast2>
mint<param, fast> operator+(mint<param, fast> a, mint<param, fast2> b)
{
  return a += b;
}
template <long long param>
mint<param> operator-(mint<param> a, mint<param> b)
{
  return a -= b;
}
template <long long param>
mint<param> operator*(mint<param> a, mint<param> b)
{
  return a *= b;
}
template <long long param>
mint<param> operator/(mint<param> a, mint<param> b)
{
  return a /= b;
}
template <long long param, bool fast>
mint<param, fast> &operator+=(mint<param, fast> &a, long long b)
{
  return a = a.v + b;
}
template <long long param>
mint<param> &operator-=(mint<param> &a, long long b)
{
  return a = a.v - b;
}
template <long long param>
mint<param> &operator*=(mint<param> &a, long long b)
{
  return a = a.v * b;
}
template <long long param>
mint<param> &operator/=(mint<param> &a, long long b)
{
  return a = a.v * inv_mod(b, a.get_mod());
}
template <long long param, bool fast>
mint<param, fast> operator+(mint<param> a, long long b)
{
  return a += b;
}
template <long long param>
mint<param> operator-(mint<param> a, long long b)
{
  return a -= b;
}
template <long long param>
mint<param> operator*(mint<param> a, long long b)
{
  return a *= b;
}
template <long long param>
mint<param> operator/(mint<param> a, long long b)
{
  return a /= b;
}

void solve(long long N, std::vector<long long> A)
{
  mint<> sum, sums;

  for (auto a : A)
  {
    sum += a;
    sums += a * a;
  }
  mint<> ans;
  ans = sum * sum - sums;
  ans /= 2;
  cout << ans << endl;
}

int main()
{
  cout << setprecision(10);
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &A[i]);
  }
  solve(N, std::move(A));
  return 0;
}
