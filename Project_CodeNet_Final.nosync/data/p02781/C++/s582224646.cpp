#include "iostream"
#include "string"
#include "vector"
#define rep(i, to) for (ll i = 0; i < (to); ++i)
#define rep1(i, to) for (ll i = 1; i <= (to); ++i)
#define all(vec) vec.begin(), vec.end()
#define unless(cond) if (!(cond))
using namespace std;
typedef long long ll;
template <typename T>
using V = vector<T>;

template <typename T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <typename T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

template <typename T>
void drop(const T& x) {
  cout << x << endl;
  exit(0);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string N;
  ll K;
  cin >> N >> K;

  V<V<V<ll>>> dp(N.size() + 1, V<V<ll>>(K + 1, V<ll>(2)));
  dp[0][0][1] = 1;

  rep(i, N.size()) {
    ll va = N[i] - '0';

    rep(k, K + 1) {
      if (va == 0) {
        dp[i + 1][k][1] += dp[i][k][1];
        dp[i + 1][k][0] += dp[i][k][0];
        if (k == K) continue;
        dp[i + 1][k + 1][0] += 9 * dp[i][k][0];
      } else {
        dp[i + 1][k][0] += dp[i][k][0] + dp[i][k][1];
        if (k == K) continue;
        dp[i + 1][k + 1][1] += dp[i][k][1];
        dp[i + 1][k + 1][0] += dp[i][k][0] * 9 + dp[i][k][1] * (va - 1);
      }
    }
  }

  cout << dp[N.size()][K][1] + dp[N.size()][K][0] << endl;

  return 0;
}
