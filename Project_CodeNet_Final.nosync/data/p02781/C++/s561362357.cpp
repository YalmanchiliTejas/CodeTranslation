#ifndef DEBUG
#  define NDEBUG
#endif
#include <iostream>
#include <string>
#include <iterator>
#include <utility>
#include <type_traits>
#include <limits>
#include <cassert>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// template {{{
// misc {{{
using Z = long long;
[[maybe_unused]]
constexpr Z INF = numeric_limits<Z>::max() / 3;
// }}}

// debug {{{
template <class T>
using enable_if_sequence_t = enable_if_t<
  is_same<
    typename iterator_traits<
      typename remove_cv_t<remove_reference_t<T>>::iterator
    >::iterator_category,
    random_access_iterator_tag>{}>;
#ifdef NDEBUG
# define dump(x)
# define debug if (0)
template <class T>
inline T&& ix(T&& value) { return value; }
template <class T, class Index, class... Indices, class = enable_if_sequence_t<T>>
inline auto&& ix(T&& container, Index index, Indices... indices) {
  return ix(container[index], indices...);
}
#else
# define dump(x) do { \
    cerr << "\e[33m[dump: " << __LINE__ << "] " << (#x) << " = " << x << "\e[0m" << endl; \
  } while (0);
# define debug
template <class T>
inline auto&& ix_impl([[maybe_unused]] int line, [[maybe_unused]] const char* code, T&& value) {
  return value;
}
template <class T, class Index, class... Indices, class = enable_if_sequence_t<T>>
inline auto&& ix_impl(int line, const char* code, T&& container, Index index, Indices... indices) {
  if (index < 0) {
    cerr << "\e[31mix: negative index at line " << line << ", ix(" << code << ")\e[0m" << endl;
    exit(1);
  }
  int size = container.size();
  if (index >= size) {
    cerr << "\e[31mix: index out of range at line " << line << ", ix(" << code << ")\n"
      << "index = " << index << " whereas size = " << size << "\e[0m" << endl;
    exit(1);
  }
  return ix_impl(line, code, container[index], indices...);
}
#define ix(...) ix_impl(__LINE__, #__VA_ARGS__, __VA_ARGS__)
#endif
// }}}

// IO {{{
template <class T, class U>
ostream& operator<< (ostream& os, pair<T, U> p) {
  os << '(' << p.first << ", " << p.second << ')';
  return os;
}
template <class T>
false_type is_container_impl(...);
template <class T, class = typename T::iterator>
true_type is_container_impl(T);
template <class T>
struct is_container : decltype(is_container_impl<T>(declval<T>())) {};
template <>
struct is_container <string> : std::false_type {};
template <class Container, class = enable_if_t<is_container<Container>{}>>
istream& operator>> (istream& is, Container& cont) {
  for (auto& v : cont) is >> v;
  return is;
}
template <class Container, class = enable_if_t<is_container<Container>{}>>
ostream& operator<< (ostream& os, Container const& cont) {
  bool first = true;
  constexpr char sep =
    is_container<typename Container::value_type>{} ? '\n' : ' ';
  for (auto const& v : cont) {
    if (!first) {
      os << sep;
    }
    first = false;
    os << v;
  }
  return os;
}
// }}}
// }}}


Z comb(Z n, Z k) {
  if (n < k) return 0;
  Z res = 1;
  for (auto i = 0; i < k; i++) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}

Z count_nums(string const& N, Z K, bool tight, map<Z, Z>& digits) {
  dump(digits);
  dump(tight);
  if (digits.size() == K) {
    return 1;
  }
  Z total = 0;
  Z start = digits.empty() ? N.size() - 1 : begin(digits)->first - 1;
  bool has_nonzero = false;
  for (auto i = start; i >= 0; i--) {
    dump(i);
    assert(!digits.count(i));
    for (auto j = 1; j < 10; j++) {
      bool next_tight = false;
      if (!has_nonzero && tight) {
        if (ix(N, i) - '0' < j) break;
        if (ix(N, i) - '0' == j) {
          next_tight = true;
        }
      }
      if (next_tight) {
        digits[i] = j;
        total += count_nums(N, K, next_tight, digits);
        digits.erase(i);
      }
      else {
        Z p = 1;
        Z rest_choice = K - digits.size() - 1;
        for (auto i = 0; i < rest_choice; i++)
          p *= 9;
        dump(j);
        total += comb(i, rest_choice) * p;
        dump(total);
      }
    }
    if (ix(N, i) != '0')
      has_nonzero = true;
  }
  return total;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string N;
  Z K;
  cin >> N >> K;
  reverse(begin(N), end(N));
  map<Z, Z> m;
  cout << count_nums(N, K, true, m) << endl;
}

