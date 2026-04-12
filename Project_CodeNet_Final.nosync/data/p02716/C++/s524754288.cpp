
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>

template <class T, class U>
inline bool chmin(T &lhs, const U &rhs) {
  if (lhs > rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

template <class T, class U>
inline bool chmax(T &lhs, const U &rhs) {
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
  constexpr range(int l_, int r_): l(l_), r(std::max(l_, r_)) { }
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
  const itr l, r;
  constexpr revrange(int l_, int r_): l(l_ - 1), r(std::max(l_, r_) - 1) { }
  constexpr itr begin() const { return r; }
  constexpr itr end() const { return l; }
};

constexpr long long inf = (1ll << 60);

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (int &x: A) {
    std::cin >> x;
  }
  if (N % 2 == 0) {
    std::vector<long long> pref(N / 2 + 1), suff(N / 2 + 1);
    for (int i: range(0, N)) {
      if (i % 2 == 0) pref[i / 2 + 1] += A[i];
      else suff[i / 2 + 1] += A[N - i];
    }
    for (int i: range(0, N / 2)) {
      pref[i + 1] += pref[i];
      suff[i + 1] += suff[i];
    }
    long long ans = -inf;
    for (int i: range(0, N / 2 + 1)) {
      chmax(ans, pref[i] + suff[N / 2 - i]);
    }
    std::cout << ans << '\n';
    return 0;
  }
  else {
    std::vector<long long> pref(N + 1), suff(N + 1);
    for (int i: range(0, N)) {
      if (i % 2 == 0) {
        pref[i + 1] += A[i];
        suff[i + 1] += A[N - i - 1];
      }
    }
    for (int i: range(0, N)) {
      pref[i + 1] += pref[i];
      suff[i + 1] += suff[i];
    }
    std::vector<long long> fr(N + 1, -inf), ba(N + 1, -inf);
    fr[0] = 0;
    ba[0] = 0;
    for (int i: range(0, N)) {
      if (i % 2 == 1) {
        chmax(fr[i + 1], pref[i + 1]);
        chmax(ba[i + 1], suff[i + 1]);
        chmax(fr[i + 1], fr[i - 1] + A[i]);
        chmax(ba[i + 1], ba[i - 1] + A[N - i - 1]);
      }
    }
    long long ans = -inf, sum = 0;
    for (int i: range(0, N - 1)) {
      if (i % 2 == 0) {
        chmax(ans, fr[i] + suff[N - i - 2]);
      }
      else {
        sum += A[i];
        chmax(ans, pref[i] + ba[N - i - 2]);
      }
    }
    std::cout << std::max(ans, sum) << '\n';
  }
  return 0;
}
