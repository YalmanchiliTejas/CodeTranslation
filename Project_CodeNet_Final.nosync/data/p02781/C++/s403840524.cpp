#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

// lib/util.hpp
#ifndef UTIL_HPP
#define UTIL_HPP


typedef ::std::int_fast64_t i64;
typedef ::std::uint_fast64_t u64;
typedef ::std::int_fast32_t i32;
typedef ::std::uint_fast32_t u32;

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

// main.cpp

int main() {
  std::string N;
  i64 K;
  std::cin >> N >> K;

  const i64 STRICT = 0;
  const i64 LOOSE = 1;
  std::vector<std::array<i64, 2>> dp(K + 1, std::array<i64, 2>({0, 0}));
  dp[1][STRICT] = 1;
  dp[1][LOOSE] = (N[0] - '0') - 1;

  for (i64 i = 1; i < static_cast<i64>(N.size()); ++i) {
    const i64 N_i = N[i] - '0';
    std::vector<std::array<i64, 2>> new_dp(K + 1, std::array<i64, 2>({0, 0}));
    new_dp[1][LOOSE] = 9;
    for (i64 j = 0; j <= K; ++j) {
      new_dp[j][STRICT] += dp[j][STRICT] * (N_i == 0 ? 1 : 0);
      new_dp[j][LOOSE] += dp[j][STRICT] * (N_i == 0 ? 0 : 1) + dp[j][LOOSE];
      if (j + 1 <= K) {
        new_dp[j + 1][STRICT] += dp[j][STRICT] * (N_i == 0 ? 0 : 1);
        new_dp[j + 1][LOOSE] += dp[j][STRICT] * (N_i == 0 ? 0 : N_i - 1) + dp[j][LOOSE] * 9;
      }
    }
    dp.swap(new_dp);
  }

  std::cout << dp[K][STRICT] + dp[K][LOOSE] << std::endl;
  return 0;
}