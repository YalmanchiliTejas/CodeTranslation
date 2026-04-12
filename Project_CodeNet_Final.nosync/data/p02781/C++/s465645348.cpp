#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

#if __cplusplus < 201103L
#error C++11 or higher expected.
#endif
// constexpr int CPPV = (__cplusplus / 100 % 100); // C++ Version
#define CPPV (__cplusplus / 100 % 100)

// define
#define endl "\n"
#ifdef LOCAL
#define lout cerr
#else
ostream devnull(0);
#define lout devnull
#endif
#define dump(x) lout << #x << " = " << (x) << endl;

#define all(a) (a).begin(), (a).end()

// rep
// Inspired by:
// https://github.com/kurokoji/.cpp-Template/blob/master/template/template2.cpp
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define rep(...)                                 \
  GET_MACRO(__VA_ARGS__, rep4, rep3, rep2, rep1) \
  (__VA_ARGS__)
#define rep1(N) rep2(_, N)
#define rep2(i, N) rep3(i, 0, N)
#define rep3(i, a, N) rep4(i, a, N, 1)
#define rep4(i, a, N, d) rep5(i, a, N, d, <)
#define rep5(i, a, N, d, o) \
  for (auto i = decltype(N)(a), i##_len = (N); i o i##_len; i += (d))

#define rrep(...)                                    \
  GET_MACRO(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1) \
  (__VA_ARGS__)
#define rrep1(a) rrep2(_, a)
#define rrep2(i, a) rrep3(i, a, 0)
#define rrep3(i, a, N) rrep4(i, a, N, -1)
#define rrep4(i, a, N, d) rep5(i, (a)-1, N, d, >=)

#define repc(...)                                    \
  GET_MACRO(__VA_ARGS__, repc4, repc3, repc2, repc1) \
  (__VA_ARGS__)
#define repc1(N) repc2(_, N)
#define repc2(i, N) repc3(i, 0, N)
#define repc3(i, a, N) repc4(i, a, N, 1)
#define repc4(i, a, N, d) rep5(i, a, N, d, <=)

// alias
using ll = long long;
using lint = long long;

// func
template <class C>
void vcin(C &c)
{
  for (auto &&a : c)
  {
    cin >> a;
  }
}
template <class C, class D>
void vcin(C &c, D &d)
{
  for (auto it1 = c.begin(), it2 = d.begin(); it1 != c.end() && it2 != d.end();
       it1++, it2++)
  {
    cin >> *it1 >> *it2;
  }
}
template <class C>
void vcout(const C &c, const string delimiter = " ")
{
  for (auto it = c.begin(); it != c.end(); it++)
  {
    if (it != c.begin())
      cout << delimiter;
    cout << *it;
  }
}
template <class T = int>
inline T input()
{
  T x;
  cin >> x;
  return (x);
}
template <typename T>
inline void chmax(T &x, const T y)
{
  if (x < y)
    x = y;
}
template <typename T>
inline void chmin(T &x, const T y)
{
  if (x > y)
    x = y;
}

#if CPPV >= 14
// http://beet-aizu.hatenablog.com/entry/2018/04/08/145516
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T &t, const V &v)
{
  t = v;
}
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T &t, const V &v)
{
  for (auto &e : t)
    fill_v(e, v);
}
#endif

constexpr int INF = 1 << 24;
constexpr lint LINF = 1LL << 48;

inline lint bit(int N)
{
  return 1LL << N;
}

inline bool bitof(lint N, int i)
{
  return (N >> i) & 1;
}

template <typename T>
inline bool between(T a, T x, T b)
{
  return a <= x && x <= b;
}

void solve();

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  solve();

  return 0;
}

void solve()
{
  string N;
  cin >> N;

  int k;
  cin >> k;

  vector<int> n;
  n.reserve(N.size());

  for (char c : N)
  {
    n.push_back(c - '0');
  }

  const int l = n.size();

  auto dp = make_v<int>(l + 1, 2, k + 1 + 1);

  dp[0][0][0] = 1;
  rep(i, l) repc(smaller, 0, 1) repc(j, k)
      repc(x, smaller ? 9 : n[i])
  {
    dp[i + 1][smaller || x < n[i]][j + (x != 0)] += dp[i][smaller][j];
  }

  cout << dp[l][false][k] + dp[l][true][k] << endl;
}
