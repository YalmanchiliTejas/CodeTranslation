// #include <bits/stdc++.h>
#include <iostream> // cout, endl, cin
#include <iomanip> // setprecision
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath> // pow

#define int long long

// loop
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 	// a ~ b-1	(ascending)
#define REP(i, n) FOR(i, 0, n)							// 0 ~ n-1
#define NREP(i, n) FOR(i, 1, n + 1)						// 1 ~ n
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)	// a ~ b	(descending)
#define RREP(i, n) RFOR(i, n, 0)						// n ~ 0
#define RNREP(i, n) RFOR(i, n, 1)						// n ~ 1
 
// container operation
#define all(v) v.begin(), v.end()
#define EACH(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
#define ASORT(c) std::sort((c).begin(), (c).end())
#define DSORT(c) std::sort((c).begin(), (c).end(), std::greater<decltype(c)::value_type>())
#define SIZE(x) ((int)(x).size())

// type alias
using VI = std::vector<int>;
using VII = std::vector<VI>;
using VB = std::vector<bool>;
using VBB = std::vector<VB>;
using VS = std::vector<std::string>;
using PII = std::pair<int, int>;

// union of two containers
template <typename T>
void container_union(T &c1, T &c2, T &c3) {
  std::vector<int> vec;
  std::set_union(c1.begin(), c1.end(),
                 c2.begin(), c2.end(),
                 std::back_inserter(vec));
  T tmp(vec.begin(), vec.end());
  c3 = tmp;
}

// chmax, chmin
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

// LIS, 2-dimentional LIS
// INF must be greater than any element
// O(nlog(n))
int LIS(std::vector<int> &v, int INF) {
  int n = SIZE(v);
  VI dp(n, INF);
  REP(i, n) {
    *std::lower_bound(all(dp), v.at(i)) = v.at(i);
  }
  return std::lower_bound(all(dp), INF) - dp.begin();
}
// INF must be greater than any second element
// O(nlog(n))
int LIS2D(std::vector<PII> &v, int INF) {
  int n = SIZE(v);
  REP(i, n) {
    v.at(i).second *= -1;
  }
  ASORT(v);

  VI snd(n);
  REP(i, n) {
    v.at(i).second *= -1;
    snd.at(i) = v.at(i).second;
  }

  return LIS(snd, INF);
}

// grid-search
std::vector<int> dx = {1, -1, 0,  0};
std::vector<int> dy = {0,  0, 1, -1};
 
// debug
#define check(x) std::cout << #x << " = " << x << '\n'
 
// print
#define cout(x) std::cout << x << '\n'
 
// yes/no
std::string yes = "Yes";
std::string no = "No";
std::string YES = "YES";
std::string NO = "NO";

void solve();

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout << std::fixed << std::setprecision(10);
  solve();
  return 0;
}

void solve() {
  int r, g, b;
  std::cin >> r >> g >> b;
  int i = 100 * r + 10 * g + b;
  if (i % 4 == 0) {
    cout(YES);
  } else {
    cout(NO);
  }
}
