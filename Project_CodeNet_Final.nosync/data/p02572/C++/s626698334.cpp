#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
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

ll N;
ll A[201010];
ll cumrev[201010];

int main() {
  //
  cin >> N;
  rep(i, 0, N) { cin >> A[i]; }

  for (int i = N - 1; i >= 0; --i) {
    cumrev[i] = cumrev[i + 1] + A[i];
    cumrev[i] %= MOD;
  }

  ll ans = 0;
  for (int i = 0; i < N - 1; ++i) {
    ans += A[i] * cumrev[i + 1] % MOD;
    ans %= MOD;
  }

  cout << ans;
}

