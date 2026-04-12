#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I32_MAX
#define MOD 1000000007
// #define MOD 998244353
#define MEM_SIZE 201010
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
inline bool chmax(T1 &a, T2 b)
{
  return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b)
{
  return a > b && (a = b, true);
}

vector<int> divisor(int n)
{
  vector<int> ret;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      ret.push_back(i);
      if (i * i != n)
        ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

template <typename T>
map<T, T> prime_factor(T n)
{
  map<T, T> ret;
  for (T i = 2; i * i <= n; i++)
  {
    T tmp = 0;
    while (n % i == 0)
    {
      tmp++;
      n /= i;
    }
    ret[i] = tmp;
  }
  if (n != 1)
    ret[n] = 1;
  return ret;
}
/*  divisor_num(n)
    入力：整数 n
    出力：nの約数の個数
    計算量：O(√n)
*/
template <typename T>
T divisor_num(T N)
{
  map<T, T> pf = prime_factor(N);
  T ret = 1;
  for (auto p : pf)
  {
    ret *= (p.second + 1);
  }
  return ret;
}

void solve(void)
{
  int n, x, m;
  cin >> n >> x >> m;
  int p = x;
  map<int, int> mp;
  int cnt = 0;
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    if (mp[p] == 2)
      break;
    res += p;
    mp[p] += 1;
    p = p * p;
    p %= m;
    cnt += 1;
  }
  if (cnt == n)
  {
    cout << res << endl;
    return;
  }
  int r = n - cnt;
  int cycle_sum = 0;
  int cycle_num = 0;
  for (auto &&x : mp)
  {
    if (x.second == 2)
    {
      cycle_sum += x.first;
      cycle_num += 1;
    }
  }
  res += cycle_sum * (r / cycle_num);
  for (int i = 0; i < r % cycle_num; i++)
  {
    res += p;
    // mp[p] += 1;
    p = p * p;
    p %= m;
  }
  cout << res << endl;

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
