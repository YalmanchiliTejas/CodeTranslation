#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define rev(i,s,e) for(i64 (i) = (s);(i) --> (e);)
#define all(x) x.begin(),x.end()

template<class T>
static inline std::vector<T> ndvec(size_t&& n, T val) noexcept {
  return std::vector<T>(n, std::forward<T>(val));
}

template<class... Tail>
static inline auto ndvec(size_t&& n, Tail&&... tail) noexcept {
  return std::vector<decltype(ndvec(std::forward<Tail>(tail)...))>(n, ndvec(std::forward<Tail>(tail)...));
}

int main() {
  string N;
  cin >> N;
  i64 K;
  cin >> K;

  auto dp = ndvec(N.size() + 1, 5, 2, 0ll);
  dp[0][0][0] = 1;
  for(i64 i = 0;i < N.size();i++) {
    for(i64 k = 0;k <= K;k++) {
      rep(over, 0, 2) {
        i64 V = (i64)(N[i] - '0') + 1;
        rep(next, 0, (over ? 10ll : V)) {
          i64 nf = over || (next < V - 1);
          dp[i + 1][k + !!(next != 0)][nf] += dp[i][k][over];
        }
      }
    }
  }
  cout << dp[N.size()][K][0] + dp[N.size()][K][1] << endl;
}
