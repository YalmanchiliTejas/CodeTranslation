#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
// #define MOD 998244353
#define MEM_SIZE 101010
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()

template <typename T>
void DEBUG(T e)
{
  if (DEBUG_OUT == false)
    return;
  std::cout << e << " ";
}
template <typename T>
void DEBUG(const std::vector<T> &v)
{
  if (DEBUG_OUT == false)
    return;
  for (const auto &e : v)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}
template <typename T>
void DEBUG(const std::vector<std::vector<T>> &vv)
{
  if (DEBUG_OUT == false)
    return;
  for (const auto &v : vv)
  {
    DEBUG(v);
  }
}
template <class T, class... Ts>
void DEBUG(T d, Ts... e)
{
  if (DEBUG_OUT == false)
    return;
  DEBUG(d);
  DEBUG(e...);
}
template <class T>
void corner(bool flg, T hoge)
{
  if (flg)
  {
    cout << hoge << endl;
    abort();
  }
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

//BELOW

struct mint
{
  int x; // typedef long long int;
  mint(int x = 0) : x((x % MOD + MOD) % MOD) {}
  mint &operator+=(const mint a)
  {
    if ((x += a.x) >= MOD)
      x -= MOD;
    return *this;
  }
  mint &operator-=(const mint a)
  {
    if ((x += MOD - a.x) >= MOD)
      x -= MOD;
    return *this;
  }
  mint &operator*=(const mint a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const
  {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const
  {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const
  {
    mint res(*this);
    return res *= a;
  }
  mint pow(int t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // for prime MOD
  mint inv() const
  {
    return pow(MOD - 2);
  }
  mint &operator/=(const mint a)
  {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const
  {
    mint res(*this);
    return res /= a;
  }
};

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit()
{
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

int COM(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int PERM(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[n - k] % MOD) % MOD;
}

int MCOM(int n, int k)
{
  //n個のものから重複を許してr個選ぶ。
  //Choose R from N types of things, allowing for duplication.
  return COM(n + k - 1, k);
}
//solve

//-----CODE------//

//BELOW
void solve(void)
{
  int n, m, k;
  cin >> n >> m >> k;
  mint res = 0;
  COMinit();
  for (int i = 1; i < n; i++)
  {
    mint x = (n - i);
    x *= m;
    x *= m;
    x *= COM(n * m - 2, k - 2);
    res += x * i;
  }

  for (int i = 1; i < m; i++)
  {
    mint x = (m - i);
    x *= n;
    x *= n;
    x *= COM(n * m - 2, k - 2);
    res += x * i;
  }
  cout << res.x << endl;

  return;
}

int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(11);
  solve();

  return 0;
}
