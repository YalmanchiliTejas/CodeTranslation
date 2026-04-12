#pragma region
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define debug(x) cerr << #x << ": " << x << '\n'
#define INF 1e9
using namespace std;
template <class T = int>
T in() {
  T x;
  cin >> x;
  return (x);
}

typedef long long ll;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

#pragma endregion

int main() {
  int a = in(), b = in(), c = in(), x = in(), y = in();

  ll min = INF;
  min = a * x + b * y;
  ll tmp, tmp2;
  if (x > y) {
    tmp = 2 * c * y + (x - y) * a;
    tmp2 = 2 * c * x;
    chmin(tmp, tmp2);
  } else if (x == y) {
    tmp = 2 * c * x;
  } else {
    tmp = 2 * c * x + (y - x) * b;
    tmp2 = 2 * c * y;
    chmin(tmp, tmp2);
  }
  chmin(min, tmp);

  cout << min << endl;
  return 0;
}
