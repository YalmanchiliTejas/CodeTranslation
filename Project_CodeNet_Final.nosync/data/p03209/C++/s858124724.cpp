#include <bits/stdc++.h>
#include <cstddef>
#include <type_traits>

// lib/pow2.hpp
#ifndef POW2_HPP
#define POW2_HPP

/*
usage:

tools::pow2(5) => 32
*/


namespace tools {
  template <typename T, typename std::enable_if<std::is_unsigned<T>::value, std::nullptr_t>::type = nullptr>
  constexpr T pow2(const T x) {
    return static_cast<T>(1) << x;
  }

  template <typename T, typename std::enable_if<std::is_signed<T>::value, std::nullptr_t>::type = nullptr>
  constexpr T pow2(const T x) {
    return static_cast<T>(static_cast<typename std::make_unsigned<T>::type>(1) << static_cast<typename std::make_unsigned<T>::type>(x));
  }
}

#endif

// main.cpp

constexpr std::int_fast64_t layer_count(const std::int_fast64_t level) {
  return tools::pow2(level + 2) - 3;
}
constexpr std::int_fast64_t patty_count(const std::int_fast64_t level) {
  return tools::pow2(level + 1) - 1;
}
std::int_fast64_t patty_count(const std::int_fast64_t level, std::int_fast64_t x) {
  if (level == 0) return x;
  if (x <= 1) return 0;
  --x;
  if (x <= layer_count(level - 1)) return patty_count(level - 1, x);
  x -= layer_count(level - 1);
  if (x <= 1) return patty_count(level - 1) + 1;
  --x;
  if (x <= layer_count(level - 1)) return patty_count(level - 1) + 1 + patty_count(level - 1, x);
  return patty_count(level);
}

int main() {
  std::int_fast64_t n, x;
  std::cin >> n >> x;
  std::cout << patty_count(n, x) << std::endl;
  return 0;
}