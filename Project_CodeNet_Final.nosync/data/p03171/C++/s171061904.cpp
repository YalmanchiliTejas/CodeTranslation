#include <bits/stdc++.h>

using namespace std;

//
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
//

const long long INF = 1LL << 60;

int N;
long long a[3030];
int visit[3030][3030];
long long memo[3030][3030];

long long dp(int L, int R) {
  if (L > R) return 0;
  if (visit[L][R]) return memo[L][R];
  visit[L][R] = 1;

  int diff = N - (R - L + 1);

  long long res = 0;
  if (diff % 2 == 0) {
    // X-Yを最大化
    res = -INF;
    chmax(res, dp(L + 1, R) + a[L]);
    chmax(res, dp(L, R - 1) + a[R]);
  } else {
    // X-Yを最小化
    res = INF;
    chmin(res, dp(L + 1, R) - a[L]);
    chmin(res, dp(L, R - 1) - a[R]);
  }

  return memo[L][R] = res;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  cout << dp(0, N - 1) << endl;

  return 0;
}