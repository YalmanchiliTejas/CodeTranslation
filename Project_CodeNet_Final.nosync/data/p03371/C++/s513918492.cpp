// C++11
#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <cmath>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

#define LOCAL 1

#if LOCAL
#define pv(val) cerr << #val << '=' << (val) << endl
#define pvn(name, val) cerr << name << '=' << (val) << endl
#define pl cerr << '@' << __LINE__ << endl
#else
#define pv(val)
#define pvn(name, val)
#define pl
#endif

template <class T>
ostream& operator<<(ostream& os, vector<T> const& vec) {
  if (vec.empty()) {
    os << "{}";
  } else {
    os << '{';
    for (size_t i = 0; i < vec.size() - 1; i++) os << vec[i] << ", ";
    os << vec.back() << '}';
  }
  return os;
}

template <class T, size_t S>
ostream& operator<<(ostream& os, array<T, S> const& arr) {
  if (arr.empty()) {
    os << "{}";
  } else {
    os << '{';
    for (size_t i = 0; i < arr.size() - 1; i++) os << arr[i] << ", ";
    os << arr.back() << '}';
  }
  return os;
}

int main(void)
{
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = 0;
  if(A + B > 2 * C){
    int d = min(X, Y);
    ans += d * 2 * C;
    if(X > Y){
      if(A < 2 * C) ans += A * (X - Y);
      else ans += 2*C*(X-Y);
    }else{
      if(B < 2*C) ans += B * (Y - X);
      else ans += 2*C * (Y-X);
    }
  }else{
    ans += A * X;
    ans += B * Y;
  }
  cout << ans << endl;

  return 0;
}