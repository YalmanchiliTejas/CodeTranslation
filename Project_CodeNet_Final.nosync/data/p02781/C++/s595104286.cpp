#define NDEBUG

#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>
#include <set>
#include <map>

// [0, max)
#define FOR0(var, max) for (sl (var) = 0; (var) < (max); ++(var))
// [min, max)
#define FORi(var, min, max) for (sl (var) = (min); (var) < (max); ++(var))
// [min, max)
#define FORi_INV(var, min, max) for (sl (var) = (max) - 1; (var) + 1 > (min); --(var))
#define FORITER(var, iter) for (auto (iter) = (var).begin(); (iter) != (var).end(); (iter)++)
#define FORITER_INV(var, iter) for (auto (iter) = (var).rbegin(); (iter) != (var).rend(); (iter)++)

// a < b < c
#define LTLT(a, b, c) (((a) < (b)) && ((b) < (c)))
// a <= b < c
#define LELT(a, b, c) (((a) <= (b)) && ((b) < (c)))
// a < b <= c
#define LTLE(a, b, c) (((a) < (b)) && ((b) <= (c)))
// a <= b <= c
#define LELE(a, b, c) (((a) <= (b)) && ((b) <= (c)))

#ifndef NDEBUG
#  define MASSERT(cond) m_assert(cond, __LINE__, #cond);
#else
#  define MASSERT(...)
#endif

using namespace std;

using uc = unsigned char;
using ui = unsigned int;
using ul = unsigned long long int;

using sc = signed char;
using si = signed int;
using sl = signed long long int;

using ld = long double;

void m_assert(const bool& cond, const sl& line, const char *condstr) {
  if (!cond) {
    cerr << "Assertion Failed: " << condstr << " at line " << line << endl;
    exit(1);
  }
}

template <class T>
T powint(T x, sl y) {
  MASSERT(0 < y);
  T cur = x;
  T res = 1;
  while (y != 0) {
    if ((y & 1) == 1) {
      res = res * cur;
    }
    cur = cur * cur;
    y >>= 1;
  }
  return res;
}

template <class T>
T factorial(const T& n) {
  T res = 1;
  FOR0(i, n) {
    res *= i + 1;
  }
  return res;
}

template <class T>
T permutation(const T& n, const T& m) {
  return factorial(n) / factorial(n - m);
}

template <class T>
T combination(const T& n, const T& m) {
  T res = 1;
  FORi(i, n - m, n) {
    res *= i + 1;
  }
  FORi(i, 0, m) {
    res /= i + 1;
  }
  return res;
}

static string N;
static sl K;
static sl dp[100];

void solve(void) {
  sl M = N.size();
  sl j = 0;
  FOR0(i, M) {
    sl n = N[i] - '0';
    sl t = 0;
    if (j < K) {
      if (n != 0) {
        t += (n - 1) * combination(M - i - 1, K - j - 1) * powint(9, K - j - 1);
        t += combination(M - i - 1, K - j) * powint(9, K - j);
      }
    }
    if (i != 0) {
      t += dp[i - 1];
    }
    dp[i] = t;
    if (n != 0) {
      j++;
      if (j == K) {
        dp[i]++;
      }
    }
  }
  cout << dp[M - 1] << endl;
}

int main(void) {
  cin >> N;
  cin >> K;
  solve();
  return 0;
}