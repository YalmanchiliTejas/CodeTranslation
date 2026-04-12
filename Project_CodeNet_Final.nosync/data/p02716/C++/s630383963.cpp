#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()

template<class T>
static inline std::vector<T> ndvec(size_t&& n, T val) noexcept {
  return std::vector<T>(n, std::forward<T>(val));
}

template<class... Tail>
static inline auto ndvec(size_t&& n, Tail&&... tail) noexcept {
  return std::vector<decltype(ndvec(std::forward<Tail>(tail)...))>(n, ndvec(std::forward<Tail>(tail)...));
}

template<class T, class Cond>
struct chain {
  Cond cond; chain(Cond cond) : cond(cond) {}
  bool operator()(T& a, const T& b) const {
    if(cond(a, b)) { a = b; return true; }
    return false;
  }
};
template<class T, class Cond>
chain<T, Cond> make_chain(Cond cond) { return chain<T, Cond>(cond); }


i64 N;
vector<i64> A;

int main() {
  cin >> N;
  A.resize(N);
  rep(i,0,N) {
    cin >> A[i];
  }
  vector<vector<i64>> res(N + 1, vector<i64>(2, -1e18));
  res[0][0] = 0;
  res[1][0] = A[0];
  res[2][1] = A[1];
  rep(i,2,N) {
    res[i + 1][0] = std::max(res[i + 1][0], res[i - 1][0] + A[i]);
    res[i + 1][1] = std::max(res[i + 1][1], res[i - 1][1] + A[i]);
    res[i + 1][1] = std::max(res[i + 1][1], res[i - 2][0] + A[i]);
  }
  if(N % 2 == 0) {
    cout << std::max(res[N][1], res[N - 1][0]) << endl;
    return 0;
  }
  std::vector<i64> dp(N, -1e18);
  dp[0] = std::max(A[0], 0ll);
  for(i64 i = 2; i < N; i += 2) {
    dp[i] = std::max(dp[i - 2] + A[i], std::max(res[i][1], res[i - 1][0]));
  }
  std::cout << dp[N - 1] << std::endl;
}
