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
#include <string>
#include <utility>
#include <vector>
#define FOR(i,a,b) for (int i=(a),for_##i##_max=(b);i<=(for_##i##_max);++i)
#define RFOR(i,a,b) for (int i=(a),rfor_##i##_min=(b);i>=(rfor_##i##_min);--i)
#define REP(i,n) for (int i=0,rep_##i##_len=(n);i<(rep_##i##_len);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)

namespace { // Basics

template<typename T>
void chmin(T &x, T y) {
  x = std::min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
  x = std::max(x, y);
}

template<typename T>
const auto minimum = static_cast<T const &(*)(T const &, T const &)>(std::min);

template<typename T>
const auto maximum = static_cast<T const &(*)(T const &, T const &)>(std::max);

template<typename T>
T constexpr infty = std::numeric_limits<T>::max / 3;
template<>
auto constexpr infty<int> = 1'100'100'100;
template<>
auto constexpr infty<long long int> = 100'500'400'300'200'100LL;

using lli = long long int;
using ld = long double;

} // namespace

using namespace std;

int main() {
  // cout << fixed << setprecision(10);

  int N;
  while (cin >> N && N) {
    vector<lli> scores;
    REP(i, N) {
      lli S; cin >> S;
      scores.push_back(S);
    }
    sort(begin(scores), end(scores));
    scores[0] = scores[N-1] = 0;
    cout << accumulate(begin(scores), end(scores), 0) / (N-2) << endl;
  }
  return 0;
}

