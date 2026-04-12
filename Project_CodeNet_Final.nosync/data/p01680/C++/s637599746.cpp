//#define NDEBUG
#include <algorithm>
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

  struct rep {
    struct itr {
      usize i;
      constexpr itr(const usize i) noexcept : i(i) {}
      void operator++() noexcept { ++i; }
      constexpr usize operator*() const noexcept { return i; }
      constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
    };
    const itr f, l;
    constexpr rep(const usize f, const usize l) noexcept
      : f(std::min(f, l)), l(l) {}
    constexpr auto begin() const noexcept { return f; }
    constexpr auto end() const noexcept { return l; }
  };
  struct revrep {
    struct itr {
      usize i;
      constexpr itr(const usize i) noexcept : i(i) {}
      void operator++() noexcept { --i; }
      constexpr usize operator*() const noexcept { return i; }
      constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
    };
    const itr f, l;
    constexpr revrep(const usize f, const usize l) noexcept
      : f(l - 1), l(std::min(f, l) - 1) {}
    constexpr auto begin() const noexcept { return f; }
    constexpr auto end() const noexcept { return l; }
  };
  template <class T> auto md_vec(const usize n, const T& value) {
    return std::vector<T>(n, value);
  }
  template <class... Args> auto md_vec(const usize n, Args... args) {
    return std::vector<decltype(md_vec(args...))>(n, md_vec(args...));
  }
  template <class T> constexpr T difference(const T& a, const T& b) noexcept {
    return a < b ? b - a : a - b;
  }
  template <class T> void chmin(T& a, const T& b) noexcept {
    if (b < a)
      a = b;
  }
  template <class T> void chmax(T& a, const T& b) noexcept {
    if (a < b)
      a = b;
  }
  template <class T> T scan() {
    T ret;
    std::cin >> ret;
    return ret;
  }

} // namespace n91
#include <cstdint>

namespace n91 {

  constexpr std::uint_fast64_t totient(std::uint_fast64_t x) noexcept {
    using u64 = std::uint_fast64_t;
    u64 ret = x;
    for (u64 i = static_cast<u64>(2); i * i <= x; ++i) {
      if (x % i == static_cast<u64>(0)) {
        ret -= ret / i;
        x /= i;
        while (x % i == static_cast<u64>(0)) {
          x /= i;
        }
      }
    }
    if (x != static_cast<u64>(1)) {
      ret -= ret / x;
    }
    return ret;
  }

  template <std::uint_fast64_t Modulus,
    std::uint_fast64_t InverseExp =
    totient(Modulus) - static_cast<std::uint_fast64_t>(1)>
    class modint {
    using u64 = std::uint_fast64_t;

    static_assert(Modulus < static_cast<u64>(1) << static_cast<u64>(32),
      "Modulus must be less than 2**32");

    u64 a;

    constexpr modint& negate() noexcept {
      if (a != static_cast<u64>(0)) {
        a = Modulus - a;
      }
      return *this;
    }

    public:
      constexpr modint(const u64 x = static_cast<u64>(0)) noexcept
        : a(x% Modulus) {}
      constexpr u64& value() noexcept { return a; }
      constexpr const u64& value() const noexcept { return a; }
      constexpr modint operator+() const noexcept { return modint(*this); }
      constexpr modint operator-() const noexcept { return modint(*this).negate(); }
      constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
      }
      constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
      }
      constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
      }
      constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
      }
      constexpr modint& operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
          a -= Modulus;
        }
        return *this;
      }
      constexpr modint& operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
          a += Modulus;
        }
        a -= rhs.a;
        return *this;
      }
      constexpr modint& operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
      }
      constexpr modint& operator/=(modint rhs) noexcept {
        u64 exp = InverseExp;
        while (exp) {
          if (exp % static_cast<u64>(2) != static_cast<u64>(0)) {
            *this *= rhs;
          }
          rhs *= rhs;
          exp /= static_cast<u64>(2);
        }
        return *this;
      }
      constexpr bool operator==(const modint rhs) const noexcept {
        return a == rhs.a;
      }
      constexpr bool operator!=(const modint rhs) const noexcept {
        return a != rhs.a;
      }
  };

  template <class T, std::uint_fast64_t v> class modint_constant {
  public:
    static constexpr T value = static_cast<T>(v);

    using value_type = T;
  };

} // namespace n91
#include <cassert>
#include <cstddef>
#include <utility>
#include <vector>

namespace n91 {

  class incremental_connectivity {
  protected:
    class node_type;

  public:
    using container_type = std::vector<node_type>;
    using size_type = typename container_type::size_type;
    class connected_component {
      friend incremental_connectivity;
      const node_type& root;
      constexpr connected_component(const node_type& root) noexcept
        : root(root) {}

    public:
      constexpr size_type representative() const noexcept { return root.parent; }
      constexpr size_type size() const noexcept { return root.size; }
      constexpr bool operator==(const connected_component& rhs) const noexcept {
        return &root == &rhs.root;
      }
      constexpr bool operator!=(const connected_component& rhs) const noexcept {
        return &root != &rhs.root;
      }
    };

  protected:
    class node_type {
    public:
      size_type parent, size;
    };
    container_type tree;

  public:
    incremental_connectivity() : tree() {}
    explicit incremental_connectivity(const size_type size) : tree(size, { 0, 1 }) {
      for (size_type i = 0; i < size; ++i)
        tree[i].parent = i;
    }

    bool empty() const { return tree.empty(); }
    size_type size() const { return tree.size(); }

    connected_component find_cc(size_type x) {
      while (tree[x].parent != x) {
        x = tree[x].parent = tree[tree[x].parent].parent;
      }
      return connected_component(tree[x]);
    }

    std::pair<size_type, size_type> unite(size_type x, size_type y) {
      assert(x < size());
      assert(y < size());
      x = find_cc(x).representative();
      y = find_cc(y).representative();
      if (x != y) {
        if (tree[x].size < tree[y].size)
          std::swap(x, y);
        tree[x].size += tree[y].size;
        tree[y].parent = x;
      }
      return { x, y };
    }
  };

} // namespace n91
#include <functional>
#include <utility>

namespace n91 {

  template <class T, class U, class Operate = std::multiplies<T>>
  constexpr T power(T base, U exp, const Operate & oper = Operate(),
    T iden = static_cast<T>(1)) {
    while (exp != static_cast<U>(0)) {
      if (exp % static_cast<U>(2) != static_cast<U>(0)) {
        iden = oper(iden, base);
      }
      exp /= static_cast<U>(2);
      base = oper(base, base);
    }
    return iden;
  }

} // namespace n91

#include <algorithm>
#include <iostream>
#include <limits>
#include <tuple>
#include <utility>

namespace n91 {

  void main_() {
    using mint = modint<1000000007>;
    while (true) {

      const usize n{ scan<usize>() };
      const usize m{ scan<usize>() };
      if (n == 0) {
        return;
      }
      incremental_connectivity uf(n);
      usize cnt = n;
      for (const auto i : rep(0, m)) {
        usize a{ scan<usize>() - 1 };
        usize b{ scan<usize>() - 1 };
        std::tie(a, b) = uf.unite(a, b);
        if (a != b) {
          --cnt;
        }
      }
      mint ans = power(static_cast<mint>(2), cnt);
      if (cnt != n) {
        ans += static_cast<mint>(1);
      }
      std::cout << ans.value() << std::endl;
    }
  }

} // namespace n91

int main() {
  n91::main_();
  return 0;
}

