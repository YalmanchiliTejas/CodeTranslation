#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int64_t abs(int64_t n) {
  if (n < 0) {
    n = -n;
  }
  return n;
}
int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}
int64_t factorial(int64_t n) {
  if (n == 1) {
    return 1;
  }
  int64_t ans = factorial(n-1);
  return ans*n;
}

int main() {
  int64_t n;
  cin >> n;
  vector <int64_t> v(n);
  vector <int64_t> data(n);
  rep(i, n) {
    cin >> v.at(i);
    data.at(i) = v.at(i);
  }
  sort(v.begin(), v.end());
  double mid1 = (double)v.at((n/2)-1), mid2 = (double)v.at(n/2);
  double mid = (mid1+mid2)/2.0;
  rep(i, n) {
    if (data.at(i) <= mid) {
      cout << (int64_t)mid2 << endl;
    } else {
      cout<< (int64_t)mid1 << endl;
    }
  }
}