#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int n;
  cin >> n;
  vector<long> a(n);
  for (long &x : a) {
    cin >> x;
  }
  vector<long> b(n, 0);
  for (int i = n - 2; i >= 0; i--) {
    b.at(i) = (b.at(i + 1) + a.at(i + 1)) % (1000000000 + 7);
  }
  long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a.at(i) % (1000000000 + 7) * b.at(i) % (1000000000 + 7);
    sum = sum % (1000000000 + 7);
  }
  cout << sum << endl;
}
