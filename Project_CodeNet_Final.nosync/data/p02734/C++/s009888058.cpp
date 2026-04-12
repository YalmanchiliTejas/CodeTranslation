#include <bits/stdc++.h>
using namespace std;

//////////////////////////////   Begin Macros

#define all(x) (x).begin(), (x).end()
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define reprev(i, N) for (int i = (int)(N)-1; i >= 0; i--)
#define rep1(i, N) for (int i = 1; i <= (int)(N); i++)
#define rep1rev(i, N) for (int i = (int)(N); i >= 0; i--)
#define forbe(i, b, e) for (int i = (b); i < (e); i++)
#define forberev(i, b, e) for (int i = (e)-1; i >= (b); i--)
#define forfl(i, f, l) for (int i = (f); i <= (l); i++)
#define forflrev(i, f, l) for (int i = (l); i >= (f); i--)
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T>
bool chmax(T &m, const T q)
{
  if (m < q)
  {
    m = q;
    return true;
  }
  else
    return false;
}
template <typename T>
bool chmin(T &m, const T q)
{
  if (m > q)
  {
    m = q;
    return true;
  }
  else
    return false;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return {l.first + r.first, l.second + r.second}; }
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return {l.first - r.first, l.second - r.second}; }
template <typename T>
pair<T, T> operator*(const pair<T, T> &l, const T &r) { return {l.first * r, l.second * r}; }
template <typename T>
pair<T, T> operator/(const pair<T, T> &l, const T &r) { return {l.first / r, l.second / r}; }
template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
  for (auto &v : vec)
    is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
  os << "[";
  for (auto v : vec)
    os << v << ",";
  os << "]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec)
{
  os << "deq[";
  for (auto v : vec)
    os << v << ",";
  os << "]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{
  os << "(" << pa.first << "," << pa.second << ")";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp)
{
  os << "{";
  for (auto v : mp)
    os << v.first << "=>" << v.second << ",";
  os << "}";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp)
{
  os << "{";
  for (auto v : mp)
    os << v.first << "=>" << v.second << ",";
  os << "}";
  return os;
}

template <typename T>
void reset(vector<T> &v, const T reset_to)
{
  for (auto &x : v)
    x = reset_to;
}
inline int popcount(const unsigned int x) { return __builtin_popcount(x); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

const int intinf = numeric_limits<int>::max();
const ll llinf = numeric_limits<ll>::max();
const pii udlr[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

//////////////////////////////   End Macros

// Modulo.h start----------------------------------------

#pragma once

#include <vector>
#include <iostream>
#include <cassert>

struct Modint;
std::vector<Modint> fact_mod;
std::vector<Modint> rev_fact_mod;

using namespace std;

// a x + b y = gcd(a, b)
int extgcd(const int a, const int b, int &x, int &y)
{
  // O(log max(a,b))
  int g = a;
  x = 1;
  y = 0;
  if (b != 0)
    g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

int inv_mod(const int a, const int mod)
{
  int x, y;
  if (extgcd(a, mod, x, y) == 1)
    return (x + mod) % mod;
  else // unsolvable
    return 0;
}

struct Modint
{
  static int mod;
  long long value;
  Modint(long long value = 0LL) : value((value % mod + mod) % mod) {}
  inline bool operator==(const Modint &rhs) const { return value == rhs.value; }
  inline bool operator!=(const Modint &rhs) const { return !(*this == rhs); }
  inline Modint operator+() const { return *this; }
  inline Modint operator-() const { return Modint(-value); }
  inline Modint &operator+=(const Modint &rhs)
  {
    if ((value += rhs.value) >= mod)
      value -= mod;
    return *this;
  }
  inline Modint &operator-=(const Modint &rhs)
  {
    if ((value += mod - rhs.value) >= mod)
      value -= mod;
    return *this;
  }
  inline Modint &operator*=(const Modint &rhs)
  {
    (value *= rhs.value) %= mod;
    return *this;
  }
  Modint pow(long long k) const
  {
    assert(k >= 0);
    if (k == 0)
      return 1;
    Modint res = pow(k / 2);
    res *= res;
    if (k % 2 == 1)
      res *= *this;
    return res;
  }

  // for prime mod
  Modint inv() const { return pow(mod - 2); }
  inline Modint &operator/=(const Modint &rhs) { return *this *= rhs.inv(); }
};
int Modint::mod = 1000000007;
Modint operator+(const Modint &lhs, const Modint &rhs) { return Modint(lhs) += rhs; }
Modint operator-(const Modint &lhs, const Modint &rhs) { return Modint(lhs) -= rhs; }
Modint operator*(const Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs; }
Modint operator/(const Modint &lhs, const Modint &rhs) { return Modint(lhs) /= rhs; }
ostream &operator>>(std::ostream &lhs, const Modint &rhs) { return lhs >> rhs.value; }
ostream &operator<<(std::ostream &lhs, const Modint &rhs) { return lhs << rhs.value; }

struct Combination
{
  std::vector<Modint> fact, ifact;
  Combination(int n = 0) : fact(n + 1), ifact(n + 1)
  {
    assert(n >= 0);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
      fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; i--)
      ifact[i - 1] = ifact[i] * i;
  }
  Modint operator()(int n, int k)
  {
    assert(0 <= n and n <= fact.size());
    if (!(0 <= k and k <= n))
      return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
};

// Modulo.h end----------------------------------------------

void solve()
{
  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  cin >> A;

  Modint::mod = 998244353;

  vector<vector<Modint>> dpLR(N + 1, vector<Modint>(S + 1, 0));
  vector<vector<Modint>> dplR(N + 1, vector<Modint>(S + 1, 0));
  vector<vector<Modint>> dplr(N + 1, vector<Modint>(S + 1, 0));
  dpLR[0][0] = 1;
  rep(n, N)
  {
    forfl(s, 0, S)
    {
      dpLR[n + 1][s] = dpLR[n][s];
      dplR[n + 1][s] = dpLR[n][s] + dplR[n][s];
      dplr[n + 1][s] = dpLR[n][s] + dplR[n][s] + dplr[n][s];
    }

    forfl(s, 0, S - A[n])
    {
      dplR[n + 1][s + A[n]] += dpLR[n][s] + dplR[n][s];
      dplr[n + 1][s + A[n]] += dpLR[n][s] + dplR[n][s];
    }
  }

  cout << dplr[N][S] << endl;
}

int main()
{
  solve();
  return 0;
}
