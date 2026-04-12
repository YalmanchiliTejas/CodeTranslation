#include <iostream>
#include <algorithm>
#include <ostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <cstring>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

template <typename T, typename U>
std::ostream& operator << (std::ostream& out, std::pair<T, U> p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}

template <typename T>
std::ostream& operator << (std::ostream& out, std::vector<T> v) {
  out << "[";
  for (int i = 0; i < v.size(); ++i) {
    out << v[i] << (i == (v.size() - 1) ? "" : ", ");
  }
  out << "]";
  return out;
}

int main() {
  int x;
  cin >> x;
  if (x == 3 or x == 5 or x == 7) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }

  return 0;
}