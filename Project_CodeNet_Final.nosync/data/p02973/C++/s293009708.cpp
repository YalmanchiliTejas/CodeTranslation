#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
template <typename Abelian>
struct BIT {
  BIT(int n, const Abelian UNITY = 0) : n(n), UNITY(UNITY) {
    ++n;
    dat.assign(n, UNITY);
  }

  void add(int idx, Abelian value) {
    while (idx < n) {
      dat[idx] += value;
      idx += idx & -idx;
    }
  }

  Abelian sum(int idx) {
    Abelian res = UNITY;
    while (idx > 0) {
      res += dat[idx];
      idx -= idx & -idx;
    }
    return res;
  }

  int lower_bound(Abelian value) {
    if (value < UNITY) return 0;
    int res = 0, exponent = 1;
    while (exponent < n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      if (res + mask < n && dat[res + mask] < value) {
        value -= dat[res + mask];
        res += mask;
      }
    }
    return res + 1;
  }

private:
  int n;
  const Abelian UNITY;
  vector<Abelian> dat;
};
// BIT<long long> bit(n, 単位元 = 0) = 要素数 n の BIT を考える
// bit.add(idx, value) = (a[idx] += value)
// bit.sum(idx) = Σ_[i=1,idx]a[i]
// bit.lower_bound(value) = min{k : Σ_[i=1,k]a[i] >= value}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<int> a(n), com;
  REP(i, n) {
    cin >> a[i];
    com.emplace_back(a[i]);
  }
  sort(ALL(com));
  com.erase(unique(ALL(com)), com.end());
  REP(i, n) a[i] = lower_bound(ALL(com), a[i]) - com.begin() + 1;
  int ans = 0;
  BIT<int> bit(n);
  REP(i, n) {
    int s = bit.sum(a[i] - 1);
    if (s == 0) {
      ++ans;
      bit.add(a[i], 1);
      continue;
    }
    int idx = bit.lower_bound(s);
    bit.add(idx, -1);
    bit.add(a[i], 1);
  }
  cout << ans << '\n';
  return 0;
}
