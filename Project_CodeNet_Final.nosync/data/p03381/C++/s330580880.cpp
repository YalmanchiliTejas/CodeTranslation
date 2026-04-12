#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <functional>
#include <ostream>
#include <queue>
#include <random>
#include <string>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using ll = long long;

// #define DEBUG

inline void init() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
}

template <typename T>
std::ostream& operator << (std::ostream& os, std::vector<T>& v) {
  os << "[";
  for (int i = 0; i < int(v.size()); ++i) {
    os << v[i] << (i == int(v.size()) - 1 ? "" : ", ");
  }
  os << "]";

  return os;
}

template <typename T, typename U>
std::ostream& operator << (std::ostream& os, std::pair<T, U>& p) {
  os << "(" << p.first << ", " << p.second << ")";

  return os;
}

int main() {
  init();

  int N;
  std::vector<int> x;

  cin >> N;
  x.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> x[i];
  }

  auto v = x;

  std::sort(v.begin(), v.end());

  for (int i = 0; i < N; ++i) {
    if (x[i] < v[N / 2]) {
      cout << v[N / 2] << endl;
    }
    else {
      cout << v[N / 2 - 1] << endl;
    }
  }

  return 0;
}