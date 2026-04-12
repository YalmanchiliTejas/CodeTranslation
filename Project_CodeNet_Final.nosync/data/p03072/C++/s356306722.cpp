#include <algorithm>
#include <array>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
#define FOR(i,a,b) for (int i=(a),for_##i##_max=(b);i<=(for_##i##_max);++i)
#define RFOR(i,a,b) for (int i=(a),rfor_##i##_min=(b);i>=(rfor_##i##_min);--i)
#define REP(i,n) for (int i=0,rep_##i##_len=(n);i<(rep_##i##_len);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)
constexpr int INF = 100100100;

template<typename T>
void chmin(T &x, T y) {
  x = std::min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
  x = std::max(x, y);
}

using namespace std;

int main() {
  // cout << fixed << setprecision(10);
  int N; cin >> N;
  int max_h = 0;
  int ans = 0;
  REP(i, N) {
    int H; cin >> H;
    if (H >= max_h) {
      ++ans;
      max_h = H;
    }
  }
  cout << ans << endl;
  return 0;
}
