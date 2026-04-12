
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <tuple>

template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
  if (lhs > rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
  if (lhs < rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

// [l, r) from l to r
struct range {
  struct itr {
    int i;
    constexpr itr(int i_): i(i_) { }
    constexpr void operator ++ () { ++i; }
    constexpr int operator * () const { return i; }
    constexpr bool operator != (itr x) const { return i != x.i; }
  };
  const itr l, r;
  constexpr range(int l_, int r_): l(l_), r(std::max<int>(l_, r_)) { }
  constexpr itr begin() const { return l; }
  constexpr itr end() const { return r; }
};

// [l, r) from r to l
struct revrange {
  struct itr {
    int i;
    constexpr itr(int i_): i(i_) { }
    constexpr void operator ++ () { --i; }
    constexpr int operator * () const { return i; }
    constexpr bool operator != (itr x) const { return i != x.i; }
  };
  const itr r, l;
  constexpr revrange(int l_, int r_): l(l_ - 1), r(std::max<int>(l_, r_) - 1) { }
  constexpr itr begin() const { return r; }
  constexpr itr end() const { return l; }
};

template <class T>
struct fix_point: private T {
  explicit constexpr fix_point(T &&func): T(std::forward<T>(func)) { }
  template <class... Args>
  constexpr decltype(auto) operator () (Args &&... args) const {
    return T::operator()(*this, std::forward<Args>(args)...);
  }
};

template <class T>
constexpr decltype(auto) make_fix_point(T &&func) {
  return fix_point<T>{std::forward<T>(func)};
}

int main() {
  int N;
  std::cin >> N;
  std::vector<int> degree(N);
  std::vector<std::vector<int>> graph(N);
  for (int i: range(0, N - 1)) {
    int x, y;
    std::cin >> x >> y;
    --x; --y;
    graph[x].push_back(y);
    graph[y].push_back(x);
    ++degree[x];
    ++degree[y];
  }
  bool answer = true;
  if (make_fix_point([&](auto &&dfs, int u, int p) -> bool {
    int count = 0;
    for (int v: graph[u]) {
      if (v != p) {
        if (dfs(v, u)) {
          ++count;
        }
      }
    }
    if (count >= 2) {
      answer = false;
    }
    return count == 0;
  })(0, -1)) {
    answer = false;
  }
  std::cout << (answer ? "Second" : "First") << '\n';
  return 0;
}
