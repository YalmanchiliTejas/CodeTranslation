#line 1 "main.cpp"

/**
 * @title Template
 */

#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>
#include <vector>
#include <array>
#include <cassert>

#line 2 "/Users/kodamankod/Desktop/Programming/Library/other/chmin_chmax.cpp"

template <class T, class U>
constexpr bool chmin(T &lhs, const U &rhs) {
  if (lhs > rhs) { lhs = rhs; return true; }
  return false;
}

template <class T, class U>
constexpr bool chmax(T &lhs, const U &rhs) {
  if (lhs < rhs) { lhs = rhs; return true; }
  return false;
}

/**
 * @title Chmin/Chmax
 */
#line 2 "/Users/kodamankod/Desktop/Programming/Library/other/range.cpp"

#line 4 "/Users/kodamankod/Desktop/Programming/Library/other/range.cpp"

class range {
public:
  class iterator {
  private:
    int64_t M_position;

  public:
    constexpr iterator(int64_t position) noexcept: M_position(position) { }
    constexpr void operator ++ () noexcept { ++M_position; }
    constexpr bool operator != (iterator other) const noexcept { return M_position != other.M_position; }
    constexpr int64_t operator * () const noexcept { return M_position; }

  };

  class reverse_iterator {
  private:
    int64_t M_position;
  
  public:
    constexpr reverse_iterator(int64_t position) noexcept: M_position(position) { }
    constexpr void operator ++ () noexcept { --M_position; }
    constexpr bool operator != (reverse_iterator other) const noexcept { return M_position != other.M_position; }
    constexpr int64_t operator * () const noexcept { return M_position; }

  };
  
private:
  const iterator M_first, M_last;

public:
  constexpr range(int64_t first, int64_t last) noexcept: M_first(first), M_last(std::max(first, last)) { }
  constexpr iterator begin() const noexcept { return M_first; }
  constexpr iterator end() const noexcept { return M_last; }
  constexpr reverse_iterator rbegin() const noexcept { return reverse_iterator(*M_last - 1); } 
  constexpr reverse_iterator rend() const noexcept { return reverse_iterator(*M_first - 1); } 

};

/**
 * @title Range
 */
#line 2 "/Users/kodamankod/Desktop/Programming/Library/other/rev.cpp"

#include <type_traits>
#include <iterator>
#line 6 "/Users/kodamankod/Desktop/Programming/Library/other/rev.cpp"

template <class T>
class rev_impl {
public:
  using iterator = decltype(std::rbegin(std::declval<T>()));

private:
  const iterator M_begin;
  const iterator M_end;

public:
  constexpr rev_impl(T &&cont) noexcept: M_begin(std::rbegin(cont)), M_end(std::rend(cont)) { }
  constexpr iterator begin() const noexcept { return M_begin; }
  constexpr iterator end() const noexcept { return M_end; }

};

template <class T>
constexpr decltype(auto) rev(T &&cont) {
  return rev_impl<T>(std::forward<T>(cont));
}

/**
 * @title Reverser
 */
#line 2 "/Users/kodamankod/Desktop/Programming/Library/algebraic/modular.cpp"

#include <cstdint>
#line 5 "/Users/kodamankod/Desktop/Programming/Library/algebraic/modular.cpp"

template <class Modulus>
class modular {
public:
  using value_type = uint32_t;
  using cover_type = uint64_t;
  static constexpr value_type mod() { return Modulus::value(); }

  template <class T>
  static constexpr value_type normalize(T value_) noexcept {
    if (value_ < 0) {
      value_ = -value_;
      value_ %= mod();
      if (value_ == 0) return 0;
      return mod() - value_;
    }
    return value_ % mod();
  }

private:
  value_type value;

public:
  constexpr modular() noexcept : value(0) { }
  template <class T>
  explicit constexpr modular(T value_) noexcept : value(normalize(value_)) { }
  template <class T>
  explicit constexpr operator T() const noexcept { return static_cast<T>(value); }

  constexpr value_type get() const noexcept { return value; }
  constexpr value_type &extract() noexcept { return value; }
  constexpr modular operator - () const noexcept { return modular(mod() - value); }
  constexpr modular operator ~ () const noexcept { return inverse(*this); }

  constexpr modular operator + (const modular &rhs) const noexcept { return modular(*this) += rhs; }
  constexpr modular& operator += (const modular &rhs) noexcept { 
    if ((value += rhs.value) >= mod()) value -= mod(); 
    return *this; 
  }

  constexpr modular operator - (const modular &rhs) const noexcept { return modular(*this) -= rhs; }
  constexpr modular& operator -= (const modular &rhs) noexcept { 
    if ((value += mod() - rhs.value) >= mod()) value -= mod(); 
    return *this; 
  }

  constexpr modular operator * (const modular &rhs) const noexcept { return modular(*this) *= rhs; }
  constexpr modular& operator *= (const modular &rhs) noexcept { 
    value = (cover_type) value * rhs.value % mod();
    return *this;
  }

  constexpr modular operator / (const modular &rhs) const noexcept { return modular(*this) /= rhs; }
  constexpr modular& operator /= (const modular &rhs) noexcept { return (*this) *= inverse(rhs); }

  constexpr bool zero() const noexcept { return value == 0; }
  constexpr bool operator == (const modular &rhs) const noexcept { return value == rhs.value; }
  constexpr bool operator != (const modular &rhs) const noexcept { return value != rhs.value; }

  friend std::ostream& operator << (std::ostream &stream, const modular &rhs) { return stream << rhs.value; }
  friend constexpr modular inverse(modular val) noexcept { return power(val, mod() - 2); }
  friend constexpr modular power(modular val, cover_type exp) noexcept { 
    modular res(1);
    for (; exp > 0; exp >>= 1, val *= val) if (exp & 1) res *= val;
    return res;
  }

};

template <uint32_t Val>
struct modulus_impl { static constexpr uint32_t value() noexcept { return Val; } };
template <uint32_t Val>
using mint32_t = modular<modulus_impl<Val>>;

struct runtime_mod { static uint32_t &value() noexcept { static uint32_t val = 0; return val; } };
using rmint32_t = modular<runtime_mod>;

/**
 * @title Modint
 */
#line 18 "main.cpp"

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

constexpr i32 inf32 = (i32(1) << 30) - 1;
constexpr i64 inf64 = (i64(1) << 62) - 1;

using m32 = mint32_t<1000000007>;

int main() {
  size_t N;
  std::cin >> N;
  std::vector<m32> A(N);
  m32 sum;
  for (auto &x: A) {
    std::cin >> x.extract();
    sum += x;
  }
  m32 ans = sum * sum;
  for (const auto x: A) {
    ans -= x * x;
  }
  std::cout << ans / m32(2) << '\n';
  return 0;
}
