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

int main() {
  int n;
  cin >> n;
  vector <int64_t> v(n);
  rep(i, n) cin >> v.at(i);
  if (n%2 == 0) {
    rep(i, n/2) {
      cout << v.at(n-1-2*i) << ' ';
    }
    rep(i, n/2) {
      if (i == n/2-1) {
        cout << v.at(2*i) << endl;
      } else {
        cout << v.at(2*i) << ' ';
      }
    }
  } else {
    rep(i, n/2+1) {
      cout << v.at(n-1-2*i) << ' ';
    }
    rep(i, n/2) {
      if (i == n/2-1) {
        cout << v.at(1+2*i) << endl;
      } else {
        cout << v.at(1+2*i) << ' ';
      }
    }
  }
}