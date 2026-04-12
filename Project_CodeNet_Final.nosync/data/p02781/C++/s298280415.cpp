
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <string>
#include <tuple>

template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
  if (lhs > rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
  if (lhs < rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

// [l, r) from l to r
struct range {
  struct itr {
    int i;
    constexpr itr(int i_): i(i_) { }
    constexpr void operator ++ () { ++i; }
    constexpr int operator * () const { return i; }
    constexpr bool operator != (itr x) const { return i != x.i; }
  };
  const itr l, r;
  constexpr range(int l_, int r_): l(std::min<int>(l_, r_)), r(r_) {}
  constexpr itr begin() const { return l; }
  constexpr itr end() const { return r; }
};

// [l, r) from r to l
struct revrange {
  struct itr {
    int i;
    constexpr itr(int i_): i(i_) { }
    constexpr void operator ++ () { --i; }
    constexpr int operator * () const { return i; }
    constexpr bool operator != (itr x) const { return i != x.i; }
  };
  const itr r, l;
  constexpr revrange(int l_, int r_): r(std::max<int>(l_, r_) - 1), l(l_ - 1) {}
  constexpr itr begin() const { return r; }
  constexpr itr end() const { return l; }
};

template <class T>
inline T scan() {
  T res;
  std::cin >> res;
  return res;
}

std::string N;
int K;
long long dp[102][4][2];

int main() {
  std::cin >> N >> K;
  std::reverse(N.begin(), N.end());
  N += std::string(100, '0');
  dp[101][0][1] = 1;
  for (int i: revrange(0, 101)) {
    for (int j: range(0, 4)) {
      for (int k: range(0, 10)) {
        int nj = (k > 0 ? j + 1 : j);
        if (nj > K) {
          continue;
        }
        dp[i][nj][0] += dp[i + 1][j][0];
      }
      for (int k: range(0, 10)) {
        int nj = (k > 0 ? j + 1 : j);
        if (nj > K) {
          continue;
        }
        if (k == N[i] - '0') {
          dp[i][nj][1] += dp[i + 1][j][1];
        } 
        else if (k < N[i] - '0') {
          dp[i][nj][0] += dp[i + 1][j][1];
        }
      }
    }
  }
  std::cout << dp[0][K][0] + dp[0][K][1] << '\n';
  return 0;
}
