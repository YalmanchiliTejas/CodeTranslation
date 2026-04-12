#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

// lib/util.hpp
#ifndef UTIL_HPP
#define UTIL_HPP


typedef std::int_fast64_t i64;
typedef std::uint_fast64_t u64;
typedef std::int_fast32_t i32;
typedef std::uint_fast32_t u32;

namespace tools {
  template <typename T>
  void read(std::vector<T>& vector, const typename std::vector<T>::size_type size) {
    vector.reserve(size);
    std::copy_n(std::istream_iterator<T>(std::cin), size, std::back_inserter(vector));
  }

  template <typename T, std::size_t N>
  void read(std::array<T, N>& array) {
    std::copy_n(std::istream_iterator<T>(std::cin), N, array.begin());
  }
}

#endif

// main.cpp

int main() {
  i64 H, W;
  std::cin >> H >> W;
  std::vector<std::string> A;
  tools::read(A, H);

  for (i64 y = 0; y < H; ++y) {
    for (i64 x = 0; x < W; ++x) {
      if (A[y][x] == '.') continue;
      const char L = x > 0 ? A[y][x - 1] : '.';
      const char R = x < W - 1 ? A[y][x + 1] : '.';
      const char U = y > 0 ? A[y - 1][x] : '.';
      const char D = y < H - 1 ? A[y + 1][x] : '.';
      if (y == 0 && x == 0) {
        if (L == '.' && R == '#' && U == '.' && D == '.') continue;
        if (L == '.' && R == '.' && U == '.' && D == '#') continue;
      } else if (y == H - 1 && x == W - 1) {
        if (L == '#' && R == '.' && U == '.' && D == '.') continue;
        if (L == '.' && R == '.' && U == '#' && D == '.') continue;
      } else {
        if (L == '.' && R == '#' && U == '#' && D == '.') continue;
        if (L == '#' && R == '.' && U == '.' && D == '#') continue;
        if (L == '#' && R == '#' && U == '.' && D == '.') continue;
        if (L == '.' && R == '.' && U == '#' && D == '#') continue;
      }
      goto FAILED;
    }
  }

  std::cout << "Possible" << std::endl;
  return 0;

FAILED:
  std::cout << "Impossible" << std::endl;
  return 0;
}