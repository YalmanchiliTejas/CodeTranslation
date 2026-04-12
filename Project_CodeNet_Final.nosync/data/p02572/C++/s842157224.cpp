#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <tuple>
#include <type_traits>
#include <vector>

// lib/quo.hpp
#ifndef QUO_H
#define QUO_H

/*
a == tools::quo(a, b) * b + tools::mod(a, b)
0 <= tools::mod(a, b) < std::abs(b)
*/

namespace tools {
  template <typename T>
  constexpr T quo(const T& lhs, const T& rhs) {
    return lhs > static_cast<T>(0)
      ? lhs / rhs
      : rhs > static_cast<T>(0)
        ? -((-lhs - 1 + rhs) / rhs)
        : (-lhs - 1 + -rhs) / -rhs;
  }
}

#endif

// lib/is_prime.hpp
#ifndef IS_PRIME_H
#define IS_PRIME_H


/*
usage:

static_assert(tools::is_prime(P), "P must be prime.");
*/

// Source: Stack Overflow ( https://stackoverflow.com/questions/18303632/compile-time-prime-checking/18306693#18306693 )
// Author: Casey ( https://stackoverflow.com/users/923854/casey )
// License: CC BY-SA 3.0
namespace tools {
  namespace detail {
    namespace is_prime {
      constexpr std::uint_fast32_t mid(const std::uint_fast32_t low, const std::uint_fast32_t high) {
        return (low + high) / 2;
      }

      // precondition: low*low <= n, high*high > n.
      constexpr std::uint_fast32_t ceilsqrt(const std::uint_fast32_t n, const std::uint_fast32_t low, const std::uint_fast32_t high) {
        return low + 1 >= high
          ? high
          : (mid(low, high) * mid(low, high) == n)
          ? mid(low, high)
          : (mid(low, high) * mid(low, high) <  n)
          ? ceilsqrt(n, mid(low, high), high)
          : ceilsqrt(n, low, mid(low, high));
      }

      // returns ceiling(sqrt(n))
      constexpr std::uint_fast32_t ceilsqrt(const std::uint_fast32_t n) {
        return n < 3
          ? n
          : ceilsqrt(n, 1, std::uint_fast32_t(1) << (std::numeric_limits<std::uint_fast32_t>::digits / 2));
      }

      // returns true if n is divisible by an odd integer in
      // [2 * low + 1, 2 * high + 1).
      constexpr bool find_factor(const std::uint_fast32_t n, const std::uint_fast32_t low, const std::uint_fast32_t high) {
        return low + 1 >= high
          ? (n % (2 * low + 1)) == 0
          : (find_factor(n, low, mid(low, high)) || find_factor(n, mid(low, high), high));
      }
    }
  }

  constexpr bool is_prime(const std::uint_fast32_t n) {
    return n > 1
      && (n == 2
        || (n % 2 == 1
          && (n == 3
            || !detail::is_prime::find_factor(n, 1, (detail::is_prime::ceilsqrt(n) + 1) / 2))));
  }
}

#endif

// lib/monoid.hpp
#ifndef MONOID_HPP
#define MONOID_HPP


namespace tools {
  template <typename T>
  class monoid {
  private:
    ::std::function<T(T, T)> m_operation;
    T m_identity;

  public:
    monoid(const ::std::function<T(T, T)>& operation, const T& identity) :
      m_operation(operation),
      m_identity(identity) {
    }
    monoid(const ::tools::monoid<T>&) = default;
    monoid(::tools::monoid<T>&&) = default;
    ::tools::monoid<T>& operator=(const ::tools::monoid<T>&) = default;
    ::tools::monoid<T>& operator=(::tools::monoid<T>&&) = default;
    virtual ~monoid() = default;

    T operation(const T& x, const T& y) const {
      return this->m_operation(x, y);
    }
    const T& identity() const {
      return this->m_identity;
    }

    template <typename U = T, typename ::std::enable_if<::std::is_integral<U>::value, ::std::nullptr_t>::type = nullptr>
    static ::tools::monoid<U> multiplies() {
      return ::tools::monoid<U>(::std::multiplies<U>(), 1);
    }
  };
}

#endif

// lib/util.hpp
#ifndef UTIL_HPP
#define UTIL_HPP


using i64 = ::std::int_fast64_t;
using u64 = ::std::uint_fast64_t;
using i32 = ::std::int_fast32_t;
using u32 = ::std::uint_fast32_t;

namespace tools {
  template <typename T>
  void read(::std::istream& is, ::std::vector<T>& vector, const typename ::std::vector<T>::size_type size) {
    vector.reserve(size);
    ::std::copy_n(::std::istream_iterator<T>(is), size, ::std::back_inserter(vector));
  }
  template <typename T>
  void read(::std::vector<T>& vector, const typename ::std::vector<T>::size_type size) {
    ::tools::read(::std::cin, vector, size);
  }

  template <typename T, ::std::size_t N>
  void read(::std::istream& is, ::std::array<T, N>& array) {
    ::std::copy_n(std::istream_iterator<T>(is), N, array.begin());
  }
  template <typename T, ::std::size_t N>
  void read(::std::array<T, N>& array) {
    ::tools::read(::std::cin, array);
  }
}

#endif

// lib/mod.hpp
#ifndef MOD_HPP
#define MOD_HPP


/*
a == tools::quo(a, b) * b + tools::mod(a, b)
0 <= tools::mod(a, b) < std::abs(b)
*/

namespace tools {
  template <typename T>
  constexpr T mod(const T& lhs, const T& rhs) {
    return lhs - ::tools::quo(lhs, rhs) * rhs;
  }
}

#endif

// lib/extgcd.hpp
#ifndef EXTGCD_HPP
#define EXTGCD_HPP


/*
usage:

const auto result = tools::extgcd(a, b);

// 0を単位元として追加したGCD
int gcd = result.gcd;

// a * x + b * y = gcd を満たす、無数にある(x, y)の組のうちの一つ
int x0 = result.x0;
int y0 = result.y0;
*/

namespace tools {
  namespace detail {
    namespace extgcd {
      template <typename T>
      class result {
      public:
        T gcd;
        T x0;
        T y0;
        result() = default;
        result(const T& gcd, const T& x0, const T& y0) :
          gcd(gcd), x0(x0), y0(y0) {
        }
      };
    }
  }
  template <typename T>
  ::tools::detail::extgcd::result<T> extgcd(T prev_r, T r) {
    T prev_s = 1;
    T prev_t = 0;
    T s = 0;
    T t = 1;
    while (r != 0) {
      const T q = ::tools::quo(prev_r, r);
      const T next_r = prev_r - q * r;
      prev_r = r;
      r = next_r;
      const T next_s = prev_s - q * s;
      prev_s = s;
      s = next_s;
      const T next_t = prev_t - q * t;
      prev_t = t;
      t = next_t;
    }
    return ::tools::detail::extgcd::result<T>(std::abs(prev_r), prev_s, prev_t);
  }
}

#endif

// lib/square.hpp
#ifndef SQUARE_HPP
#define SQUARE_HPP


/*
usage:

tools::square(5) => 25
*/

namespace tools {
  template <typename T>
  T square(const ::tools::monoid<T>& monoid, const T& x) {
    return monoid.operation(x, x);
  }

  template <typename T>
  T square(const T& x) {
    return ::tools::square(::tools::monoid<T>::multiplies(), x);
  }
}

#endif

// lib/pow.hpp
#ifndef POW_H
#define POW_H


/*
usage:

tools::pow(tools::monoid<int>::multiplies(), 2, 5) => 32
*/

namespace tools {
  template <typename T>
  T pow(const ::tools::monoid<T>& monoid, const T& base, const std::size_t exponent) {
    return exponent == 0
      ? monoid.identity()
      : exponent % 2 == 0
        ? ::tools::square(monoid, ::tools::pow(monoid, base, exponent / 2))
        : monoid.operation(::tools::pow(monoid, base, exponent - 1), base);
  }

  template <typename T>
  T pow(const T& base, const std::size_t exponent) {
    return ::tools::pow(::tools::monoid<T>::multiplies(), base, exponent);
  }
}

#endif

// lib/int_mod.hpp
#ifndef INT_MOD_HPP
#define INT_MOD_HPP


/*
usage:

constexpr const std::uint_fast32_t p = 3;
tools::int_mod<p>(5) + tools::int_mod<p>(4) // => 0
*/

namespace tools {
  template <::std::uint_fast32_t P>
  class int_mod {
  private:
    ::std::uint_fast32_t m_value;

    constexpr static ::std::uint_fast32_t add_impl(const ::std::uint_fast32_t lhs, const ::std::uint_fast32_t rhs) {
      return lhs + rhs - (lhs + rhs >= P ? P : 0u);
    }

    constexpr static ::std::uint_fast32_t sub_impl(const ::std::uint_fast32_t lhs, const ::std::uint_fast32_t rhs) {
      return lhs - rhs + (lhs < rhs ? P : 0u);
    }

    constexpr static ::std::uint_fast32_t mul_impl(const ::std::uint_fast32_t lhs, const ::std::uint_fast32_t rhs) {
      return static_cast<::std::uint_fast32_t>(static_cast<::std::uint_fast64_t>(lhs) * static_cast<::std::uint_fast64_t>(rhs) % static_cast<::std::uint_fast64_t>(P));
    }

    constexpr ::tools::int_mod<P> pow_impl(const ::std::uint_fast32_t exponent) const {
      return ::tools::pow(::tools::monoid<::tools::int_mod<P>>(::std::multiplies<::tools::int_mod<P>>(), ::tools::int_mod<P>(1)), *this, exponent);
    }

  public:
    int_mod() :
      m_value(0) {
    }

    explicit int_mod(const ::std::int_fast64_t& value) :
      m_value(static_cast<::std::uint_fast32_t>(::tools::mod<std::int_fast64_t>(value, P))) {
    }

    int_mod(const ::tools::int_mod<P>& other) :
      int_mod(other.m_value) {
    }

    constexpr explicit operator ::std::uint_fast32_t() const {
      return this->m_value;
    }

    ::tools::int_mod<P>& operator=(const ::tools::int_mod<P>& other) {
      this->m_value = other.m_value;
      return *this;
    }

    constexpr friend bool operator==(const ::tools::int_mod<P>& lhs, const ::tools::int_mod<P>& rhs) {
      return lhs.m_value == rhs.m_value;
    }

    constexpr friend bool operator!=(const ::tools::int_mod<P>& lhs, const ::tools::int_mod<P>& rhs) {
      return lhs.m_value != rhs.m_value;
    }

    constexpr friend ::tools::int_mod<P> operator+(const ::tools::int_mod<P>& lhs, const ::tools::int_mod<P>& rhs) {
      return ::tools::int_mod<P>(::tools::int_mod<P>::add_impl(lhs.m_value, rhs.m_value));
    }

    ::tools::int_mod<P>& operator+=(const ::tools::int_mod<P>& other) {
      this->m_value = ::tools::int_mod<P>::add_impl(this->m_value, other.m_value);
      return *this;
    }

    ::tools::int_mod<P>& operator++() {
      this->m_value = ::tools::int_mod<P>::add_impl(this->m_value, 1u);
      return *this;
    }

    ::tools::int_mod<P> operator++(int) {
      ::tools::int_mod<P> prev(*this);
      ++this;
      return prev;
    }

    constexpr friend ::tools::int_mod<P> operator-(const ::tools::int_mod<P>& lhs, const ::tools::int_mod<P>& rhs) {
      return ::tools::int_mod<P>(::tools::int_mod<P>::sub_impl(lhs.m_value, rhs.m_value));
    }

    ::tools::int_mod<P>& operator-=(const ::tools::int_mod<P>& other) {
      this->m_value = ::tools::int_mod<P>::sub_impl(this->m_value, other.m_value);
      return *this;
    }

    ::tools::int_mod<P>& operator--() {
      this->m_value = ::tools::int_mod<P>::sub_impl(this->m_value, 1u);
      return *this;
    }

    ::tools::int_mod<P> operator--(int) {
      ::tools::int_mod<P> prev(*this);
      --this;
      return prev;
    }

    constexpr friend ::tools::int_mod<P> operator*(const ::tools::int_mod<P>& lhs, const ::tools::int_mod<P>& rhs) {
      return ::tools::int_mod<P>(::tools::int_mod<P>::mul_impl(lhs.m_value, rhs.m_value));
    }

    ::tools::int_mod<P>& operator*=(const ::tools::int_mod<P>& other) {
      this->m_value = ::tools::int_mod<P>::mul_impl(this->m_value, other.m_value);
      return *this;
    }

    template <::std::uint_fast32_t SFINAE_P = P, typename ::std::enable_if<::tools::is_prime(SFINAE_P), ::std::nullptr_t>::type = nullptr>
    constexpr ::tools::int_mod<P> inv() const {
      return this->m_value > 0u
        ? ::tools::int_mod<P>(::tools::extgcd<::std::int_fast64_t>(P, this->m_value).y0)
        : (throw ::std::invalid_argument("cannot divide by zero"));
    }

    template <::std::uint_fast32_t SFINAE_P = P, typename ::std::enable_if<!::tools::is_prime(SFINAE_P), ::std::nullptr_t>::type = nullptr>
    constexpr ::tools::int_mod<P> pow(const ::std::int_fast32_t exponent) const {
      return exponent >= 0
        ? this->pow_impl(static_cast<::std::uint_fast32_t>(exponent))
        : (throw ::std::invalid_argument("exponent must be non-negative"));
    }

    template <::std::uint_fast32_t SFINAE_P = P, typename ::std::enable_if<::tools::is_prime(SFINAE_P), ::std::nullptr_t>::type = nullptr>
    constexpr ::tools::int_mod<P> pow(const ::std::int_fast32_t exponent) const {
      return exponent >= 0
        ? this->pow_impl(static_cast<::std::uint_fast32_t>(exponent))
        : this->pow_impl(static_cast<::std::uint_fast32_t>(-exponent)).inv();
    }

    template <::std::uint_fast32_t SFINAE_P = P, typename ::std::enable_if<::tools::is_prime(SFINAE_P), ::std::nullptr_t>::type = nullptr>
    constexpr friend ::tools::int_mod<P> operator/(const ::tools::int_mod<P>& lhs, const ::tools::int_mod<P>& rhs) {
      return lhs * rhs.inv();
    }

    template <::std::uint_fast32_t SFINAE_P = P, typename ::std::enable_if<::tools::is_prime(SFINAE_P), ::std::nullptr_t>::type = nullptr>
    ::tools::int_mod<P>& operator/=(const ::tools::int_mod<P>& other) {
      this->m_value = ::tools::int_mod<P>::mul_impl(this->m_value, other.inv().m_value);
      return *this;
    }

    friend ::std::istream& operator>>(::std::istream& is, ::tools::int_mod<P>& self) {
      return is >> self.m_value;
    }

    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::int_mod<P>& self) {
      return os << self.m_value;
    }
  };
}

namespace std {
  template <::std::uint_fast32_t P>
  struct hash<::tools::int_mod<P>> {
    using result_type = ::std::size_t;
    using argument_type = ::tools::int_mod<P>;
    ::std::size_t operator()(const argument_type& key) const {
      static const ::std::hash<::std::uint_fast32_t> hasher;
      return hasher(static_cast<::std::uint_fast32_t>(key));
    }
  };
}

#endif

// main.cpp

constexpr u32 P = 1000000007;

int main() {
  i64 N;
  std::cin >> N;
  std::vector<tools::int_mod<P>> A;
  tools::read(A, N);

  std::vector<tools::int_mod<P>> cumsum({tools::int_mod<P>(0)});
  std::partial_sum(A.begin(), A.end(), std::back_inserter(cumsum));

  tools::int_mod<P> answer(0);
  for (i64 i = 0; i < N; ++i) {
    answer += A[i] * (cumsum[N] - cumsum[i + 1]);
  }
  std::cout << answer << std::endl;
  return 0;
}