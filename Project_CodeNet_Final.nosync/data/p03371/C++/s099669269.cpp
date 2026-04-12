#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
int A, B, C, X, Y;

int main() {
  cin >> A >> B >> C >> X >> Y;

  if (2 * C <= A && 2 * C <= B) {
    cout << max(X, Y) * 2 * C << endl;
    return 0;
  } else if (2 * C <= A) {
    if (X >= Y) {
      cout << X * 2 * C << endl;
      return 0;
    } else {
      cout << X * 2 * C + (Y - X) * B << endl;
      return 0;
    }
  } else if (2 * C <= B) {
    if (Y >= X) {
      cout << Y * 2 * C << endl;
      return 0;
    } else {
      cout << Y * 2 * C + (X - Y) * A << endl;
    }
  } else if (2 * C <= A + B) {
    if (X >= Y) {
      cout << Y * 2 * C + (X - Y) * A << endl;
    } else {
      cout << X * 2 * C + (Y - X) * B << endl;
    }
  } else {
    cout << A * X + B * Y << endl;
  }
}