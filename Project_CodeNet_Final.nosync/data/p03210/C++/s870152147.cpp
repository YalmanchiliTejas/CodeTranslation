#include "bits/stdc++.h"
using namespace std;

// #define int long long

signed main(void) {
  int num; // num
  // num = 0; // count, result
  // num = numeric_limits<int>::min(); // max
  num = numeric_limits<int>::max(); // min
  int n;

  cin >> n;

  if (n == 3 || n == 5 || n == 7)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
