#include <bits/stdc++.h>
using namespace std;

//////////////////////////////   Begin Macros

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define in(x, a, b) (a <= x and x < b)
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define reprev(i, N) for (int i = (int)(N)-1; i >= 0; i--)
#define rep1(i, N) for (int i = 1; i <= (int)(N); i++)
#define rep1rev(i, N) for (int i = (int)(N); i >= 0; i--)
#define forbe(i, b, e) for (int i = (b); i < (e); i++)
#define forberev(i, b, e) for (int i = (e)-1; i >= (b); i--)
#define forfl(i, f, l) for (int i = (f); i <= (l); i++)
#define forflrev(i, f, l) for (int i = (l); i >= (f); i--)
using ll = long long;
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
istream &operator>>(istream &is, pair<T1, T2> &pa)
{
  is >> pa.first >> pa.second;
  return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{
  os << "(" << pa.first << "," << pa.second << ")";
  return os;
}
template <typename... Ts>
istream &operator>>(istream &is, tuple<Ts...> &theTuple)
{
  apply([&is](Ts &... tupleArgs) { ((is >> tupleArgs), ...); }, theTuple);
  return is;
}
template <typename... Ts>
ostream &operator<<(ostream &os, const tuple<Ts...> &theTuple)
{
  apply([&os](const Ts &... tupleArgs) {
    os << '(';
    size_t n(0);
    ((os << tupleArgs << (++n < sizeof...(Ts) ? "," : "")), ...);
    os << ')';
  },
        theTuple);
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

ll nC2(ll n)
{
  return n * (n - 1) / 2;
}

const int intinf = numeric_limits<int>::max();
const ll llinf = numeric_limits<ll>::max();
const pii udlr[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

//////////////////////////////   End Macros

// Modulo.h start----------------------------------------

#pragma once

#include <vector>
#include <iostream>
#include <cassert>

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
bool operator==(const Modint &lhs, const Modint &rhs) { return lhs.value == rhs.value; }
bool operator!=(const Modint &lhs, const Modint &rhs) { return !(lhs == rhs); }
Modint operator+(const Modint &lhs, const Modint &rhs) { return Modint(lhs) += rhs; }
Modint operator-(const Modint &lhs, const Modint &rhs) { return Modint(lhs) -= rhs; }
Modint operator*(const Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs; }
Modint operator/(const Modint &lhs, const Modint &rhs) { return Modint(lhs) /= rhs; }
istream &operator>>(istream &lhs, Modint &rhs) { return lhs >> rhs.value; }
ostream &operator<<(ostream &lhs, const Modint &rhs) { return lhs << rhs.value; }

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
    assert(0 <= n and n <= (int)fact.size());
    if (!(0 <= k and k <= n))
      return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
};

// Modulo.h end----------------------------------------------

void solve()
{
  int N;
  cin >> N;
  vector<Modint> A(N);
  cin >> A;

  Modint s = 0;
  rep(i, N)
      s += A[i];
  Modint ssq = s * s;
  Modint sisq = 0;
  rep(i, N)
      sisq += A[i] * A[i];

  cout << ((ssq - sisq) / 2) << endl;
}

int main()
{
  cerr << "start" << endl;
  // srand(time(0));
  cout << fixed << setprecision(15);

  solve();
  return 0;
}
