// ===== 2020/01/25 09:36:25 =====

// includes.hpp

#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <vector>

// cin.cpp

template <typename T, int M, int N> struct tuple_getter {
  static void get(std::istream &is, T &x) {
    is >> std::get<M>(x);
    tuple_getter<T, M + 1, N>::get(is, x);
  }
};

template <typename T, int N> struct tuple_getter<T, N, N> {
  static void get(std::istream &is, T &x) { is >> std::get<N>(x); }
};

template <typename... Args>
std::istream &operator>>(std::istream &is, std::tuple<Args...> &t) {
  tuple_getter<std::tuple<Args...>, 0, sizeof...(Args) - 1>::get(is, t);
  return is;
}

template <typename T, typename U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
  for (T &x : v) is >> x;
  return is;
}

// const_value.hpp

namespace sub {
template <typename T>
constexpr typename std::enable_if<std::is_integral<T>::value, T>::type
inf_sub() {
  return std::numeric_limits<T>::max() / 2 - 1000;
}

template <typename T>
constexpr typename std::enable_if<std::is_floating_point<T>::value, T>::type
inf_sub() {
  return std::min(std::numeric_limits<T>::max() / 2 - 1000, T(1e50));
}
}  // namespace sub

template <typename T> constexpr T inf() {
  static_assert(std::is_arithmetic<T>::value, "T must be arithmetic value");
  return sub::inf_sub<T>();
}

template <typename T> constexpr T zero() {
  static_assert(std::is_arithmetic<T>::value, "T must be arithmetic value");
  return T(0);
}

const long double pi = acos(-1.0);

// cout.cpp

template <typename T, int M, int N> struct tuple_printer {
  static void print(std::ostream &os, const T &x) {
    os << std::get<M>(x) << " ";
    tuple_printer<T, M + 1, N>::print(os, x);
  }
};

template <typename T, int N> struct tuple_printer<T, N, N> {
  static void print(std::ostream &os, const T &x) { os << std::get<N>(x); }
};

template <typename... Args>
std::ostream &operator<<(std::ostream &os, const std::tuple<Args...> &t) {
  tuple_printer<std::tuple<Args...>, 0, sizeof...(Args) - 1>::print(os, t);
  return os;
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
  os << p.first << " " << p.second;
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << " ";
    os << *it;
  }
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << " ";
    os << *it;
  }
  return os;
}

// macros.hpp

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

// misc.hpp

template <typename T> T &chmin(T &a, const T &b) { return a = std::min(a, b); }

template <typename T> T &chmax(T &a, const T &b) { return a = std::max(a, b); }

// range.hpp

class range {
  class index_type {
    int x;

  public:
    index_type(int x_) : x(x_) {}
    int operator*() const { return x; }
    bool operator!=(index_type &r) { return x < r.x; }
    void operator++() { ++x; }
  };
  index_type i, n;

public:
  range(int n_) : i(0), n(n_) {}
  range(int i_, int n_) : i(i_), n(n_) {}
  index_type &begin() { return i; }
  index_type &end() { return n; }
};

// typedef.hpp

using ll = long long;
using ld = long double;

// template.cpp

using namespace std;

// main.cpp

struct yes_no : std::numpunct<char> {
  string_type do_truename() const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

struct Initialize {
  Initialize() {
    std::locale loc(std::locale(), new yes_no);
    std::cout << std::boolalpha << std::setprecision(11) << std::fixed;
    std::cout.imbue(loc);
  }
};

const Initialize initialize;

const string yes = "Yes";
const string no = "No";
template <typename T> vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args> auto table(int n, Args... args) {
  auto val = table(args...);
  return vector<decltype(val)>(n, move(val));
}

void solve(long long N, long long M) {
  cout << (N == M) << endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  solve(N, M);
  return 0;
}

// ===== 2020/01/25 09:36:25 =====
