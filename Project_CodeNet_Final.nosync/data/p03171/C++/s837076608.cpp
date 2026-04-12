#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define FOR(i,a,b) for (int i=(a),for_##i##_max=(b);i<=(for_##i##_max);++i)
#define RFOR(i,a,b) for (int i=(a),rfor_##i##_min=(b);i>=(rfor_##i##_min);--i)
#define REP(i,n) for (int i=0,rep_##i##_len=(n);i<(rep_##i##_len);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)

using lli = long long int;

template <typename U, typename T>
std::vector<U> cumsum(std::vector<T> const &as) {
  std::vector<U> sum(as.size()+1, U());
  for (size_t i = 0; i < as.size(); ++i) {
    sum[i+1] = sum[i] + as[i];
  }
  return sum;
}

using namespace std;

void solve(int N, vector<lli> const &As) {
  vector<lli> sum = cumsum<lli>(As);
  vector<vector<lli>> dp(N+1, vector<lli>(N+1, 0));
  FOR(len, 1, N) for (int first = 0; len + first <= N; ++first) {
    auto const last = len + first;
    dp[len][first] = sum[last] - sum[first]
      - min(dp[len-1][first+1], dp[len-1][first]);
  }
  cout << 2 * dp[N][0] - (sum[N]-sum[0]) << endl;
}

int main() {
  int N; cin >> N;
  vector<lli> As;
  REP(i, N) {
    lli A;
    cin >> A;
    As.push_back(A);
  }
  solve(N, As);
  return 0;
}
