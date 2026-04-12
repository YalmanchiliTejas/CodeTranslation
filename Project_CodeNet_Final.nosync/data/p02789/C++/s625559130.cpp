#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

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
struct frep {
  struct itr {
    int i;
    constexpr itr(int i_): i(i_) { }
    constexpr void operator ++ () { ++i; }
    constexpr int operator * () const { return i; }
    constexpr bool operator != (itr x) const { return i != x.i; }
  };
  const itr l, r;
  constexpr frep(int l_, int r_): l(std::min(l_, r_)), r(r_) {}
  constexpr itr begin() const { return l; }
  constexpr itr end() const { return r; }
};

// [l, r) from r to l
struct brep {
  struct itr {
    int i;
    constexpr itr(int i_): i(i_) { }
    constexpr void operator ++ () { --i; }
    constexpr int operator * () const { return i; }
    constexpr bool operator != (itr x) const { return i != x.i; }
  };
  const itr r, l;
  constexpr brep(int r_, int l_): r(std::max(l_, r_) - 1), l(l_ - 1) {}
  constexpr itr begin() const { return r; }
  constexpr itr end() const { return l; }
};

template <class T>
inline T scan() {
  T res;
  std::cin >> res;
  return res;
}

int main() {
  int N, M;
  std::cin >> N >> M;
  std::cout << (N == M ? "Yes" : "No") << '\n';
  return 0;
}
