#ifndef DEBUG
#  define NDEBUG
#endif
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <utility>
#include <type_traits>
#include <limits>
#include <cassert>
#include <numeric>
#include <vector>
#include <set>

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
template <class T, class U>
istream& operator>> (istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
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


template <class T>
inline void chmin(T& x, T const& v) {
  x = min(x, v);
}
template <class T>
inline void chmax(T& x, T const& v) {
  x = max(x, v);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  Z N;
  cin >> N;
  vector<Z> As(N);
  cin >> As;
  vector<Z> osum(N + 2), esum(N + 2);
  for (auto i = N - 1; i >= 0; i--) {
    ix(osum, i) = ix(osum, i + 1);
    ix(esum, i) = ix(esum, i + 1);
    ix((i % 2 == 0 ? esum : osum), i) += ix(As, i);
  }
  Z ans = -INF;
  if (N == 2) {
    cout << max(ix(As, 0), ix(As, 1)) << endl;
    return 0;
  }
  if (N % 2 == 0) {
    for (auto i = 0; i < N; i += 2) {
      chmax(ans, ix(osum, i + 1) + ix(esum, 0) - ix(esum, i));
    }
  }
  else {
    multiset<Z> tails;
    for (auto i = 0; i < N; i += 2) {
      tails.insert(ix(esum, i + 2) + ix(osum, 0) - ix(osum, i));
    }
    for (auto i = 0; i < N; i += 2) {
      Z value = ix(esum, 0) - ix(esum, i) + *rbegin(tails) - (ix(osum, 0) - ix(osum, i));
      chmax(ans, value);
      auto it = tails.find(ix(esum, i + 2) + ix(osum, 0) - ix(osum, i));
      tails.erase(it);
    }
    assert(tails.empty());
  }
  cout << ans << endl;

}

