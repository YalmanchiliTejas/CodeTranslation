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
  i64 N;
  std::cin >> N;
  std::vector<i64> A;
  tools::read(A, N);

  const std::array<std::function<bool(i64, i64)>, 2> comps = {
    std::less<i64>(),
    std::greater<i64>()
  };
  const std::array<std::function<i64(i64, i64)>, 2> zigzags = {
    [](const i64& i, const i64& n) {
      return (n - 1) / 2 + (i % 2 * 2 - 1) * (i + 1) / 2;
    },
    [](const i64& i, const i64& n) {
      return n / 2 + (i % 2 * (-2) + 1) * (i + 1) / 2;
    }
  };
  const std::array<i64, 2> sizes = {
    (N + 1) / 2,
    N / 2
  };

  i64 answer = 0;
  for (const auto& comp : comps) {
    for (const auto& zigzag1 : zigzags) {
      for (const auto& zigzag2 : zigzags) {
        std::vector<i64> aligned(N);
        std::sort(A.begin(), A.end(), comp);
        for (i64 i = 0; i < sizes[0]; ++i) {
          aligned[zigzag1(i, sizes[0]) * 2] = A[i];
        }
        std::reverse(A.begin(), A.end());
        for (i64 i = 0; i < sizes[1]; ++i) {
          aligned[zigzag2(i, sizes[1]) * 2 + 1] = A[i];
        }
        std::vector<i64> diffs;
        std::adjacent_difference(aligned.begin(), aligned.end(), std::back_inserter(diffs));
        diffs.erase(diffs.begin());
        std::transform(diffs.begin(), diffs.end(), diffs.begin(), [](const i64& diff) { return std::abs(diff); });
        answer = std::max(answer, std::accumulate(diffs.begin(), diffs.end(), static_cast<i64>(0)));
      }
    }
  }

  std::cout << answer << std::endl;
  return 0;
}