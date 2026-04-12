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
  i64 N;
  std::cin >> N;
  std::vector<i64> A;
  tools::read(A, N);

  std::vector<i64> search;
  for (i64 i = N - 1; i >= 0; --i) {
    auto it = std::upper_bound(search.begin(), search.end(), A[i]);
    if (it == search.end()) {
      search.push_back(A[i]);
    } else {
      search[std::distance(search.begin(), it)] = A[i];
    }
  }

  std::cout << search.size() << std::endl;
  return 0;
}