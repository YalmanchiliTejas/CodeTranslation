#include <bits/stdc++.h>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;

main() {
  char buf[4] = {};
  cin >> buf >> buf + 1 >> buf + 2;

  istringstream ss(buf);
  int64_t n;
  ss >> n;

  if (n % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}