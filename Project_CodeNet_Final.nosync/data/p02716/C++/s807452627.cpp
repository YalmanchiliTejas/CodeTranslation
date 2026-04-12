#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef int64_t I;
typedef vector<I> vI;
typedef pair<I, I> II;
typedef vector<II> vII;
typedef vector<vII> vvII;

template<typename T>
ostream& operator<<(ostream& os, vector<T> const& v) {
  os << "[";
  for (size_t i = 0; i < v.size(); i++) {
    os << (i == 0 ? "" : ",") << v[i];
  }
  return os << "]";
}

template<typename S, typename T>
ostream& operator<<(ostream& os, tuple<S, T> const& v) {
  return os << "<" << get<0>(v) << "," << get<1>(v) << ">";
}

template<typename S, typename T, typename U>
  ostream& operator<<(ostream& os, tuple<S, T, U> const& v) {
  return os << "<" << get<0>(v) << "," << get<1>(v) << "," << get<2>(v) << ">";
}

int main() {
  I n; cin >> n;
  vI a;
  for (I i = 0; i < n; i++) {
    I x; cin >> x;
    a.push_back(x);
  }
  vI sums(n);
  sums[0] = a[0];
  sums[1] = a[1];
  for (I i = 2; i < n; i+=2) {
    sums[i] = sums[i - 2] + a[i];
  }
  for (I i = 3; i < n; i+=2) {
    sums[i] = max(sums[i - 2] + a[i], sums[i - 3] + a[i]);
  }
  if (n % 2 == 0) {
    cout << max(sums[n - 2], sums[n - 1]) << endl;
  } else {
    I m = sums[n - 2];
    for (I i = 0; i < n; i += 2) {
      m = max(m, sums[n - 1] - a[i]);
    }
    for (I i = 1; i < n; i += 2) {
      m = max(m, sums[n - 1] - sums[i - 1] + sums[i] - a[i]);
    }
    cout << m << endl;
  }
}

