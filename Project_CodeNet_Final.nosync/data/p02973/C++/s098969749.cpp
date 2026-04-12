//#define NDEBUG
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

namespace n91 {

using i8 = std::int_fast8_t;
using i32 = std::int_fast32_t;
using i64 = std::int_fast64_t;
using u8 = std::uint_fast8_t;
using u32 = std::uint_fast32_t;
using u64 = std::uint_fast64_t;
using isize = std::ptrdiff_t;
using usize = std::size_t;

constexpr usize operator"" _z(unsigned long long x) noexcept {
  return static_cast<usize>(x);
}

class rep {
  const usize f, l;

public:
  class itr {
    friend rep;
    usize i;
    constexpr itr(const usize x) noexcept : i(x) {}

  public:
    void operator++() noexcept { ++i; }
    constexpr usize operator*() const noexcept { return i; }
    constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
  };
  constexpr rep(const usize first, const usize last) noexcept
      : f(first), l(last) {}
  constexpr itr begin() const noexcept { return itr(f); }
  constexpr itr end() const noexcept { return itr(l); }
};
class revrep {
  const usize f, l;

public:
  class itr {
    friend revrep;
    usize i;
    constexpr itr(usize x) noexcept : i(x) {}

  public:
    void operator++() noexcept { --i; }
    constexpr usize operator*() const noexcept { return i; }
    constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
  };
  constexpr revrep(usize first, usize last) noexcept : f(--first), l(--last) {}
  constexpr itr begin() const noexcept { return itr(l); }
  constexpr itr end() const noexcept { return itr(f); }
};
template <class T> using vec_alias = std::vector<T>;
template <class T> auto md_vec(const usize n, const T &value) {
  return std::vector<T>(n, value);
}
template <class... Args> auto md_vec(const usize n, Args... args) {
  return std::vector<decltype(md_vec(args...))>(n, md_vec(args...));
}
template <class T> constexpr T difference(const T &a, const T &b) {
  return a < b ? b - a : a - b;
}
template <class T> T scan() {
  T ret;
  std::cin >> ret;
  return ret;
}

} // namespace n91

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <utility>

namespace n91 {

void main_() {
  const auto n = scan<usize>();
  std::vector<u32> a;
  a.reserve(n);
  std::copy_n(std::istream_iterator<u32>(std::cin), n, std::back_inserter(a));

  std::multiset<u32> s;
  for (const auto e : a) {
    if (!s.empty() && *s.begin() < e) {
      const auto itr = std::prev(s.lower_bound(e));
      s.erase(itr);
    }
    s.insert(e);
  }

  std::cout << s.size() << std::endl;
}

} // namespace n91

int main() {
  n91::main_();
  return 0;
}
