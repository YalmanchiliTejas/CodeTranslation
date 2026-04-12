
/**
 *      purpose : 
 *      author  : kyomukyomupurin
 *      created : 
**/

// input/output
#include <iostream>
#include <fstream>
#include <sstream>
// container class
#include <array>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// math, algorithm
#include <algorithm>
#include <cmath>
#include <complex>
#include <numeric>
// etc
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstring>
#include <chrono>
#include <iomanip>
#include <random>
#include <utility>
// using-directive
using namespace std;
// alias template
using int64 = int64_t;
using vi = vector<int>;
using vl = vector<int64_t>;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
// text macro replacement
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define print(x) cout << (x) << '\n'
#define debug(x) cerr << #x << ": " << (x) << '\n'
// variadic template
template<typename T> inline void chmin(T &a, T b) {if (a > b) a = b; return;}
template<typename T> inline void chmax(T &a, T b) {if (a < b) a = b; return;}
// constant
const int INF = (1<<30) - 1;
const int64_t INF64 = (1LL<<62) - 1;
const int MOD = 1000000007;

int n;
int64 a[3030];
//int64 dp[3030][3030];
int64 memo[3030][3030];
bool used[3030][3030];

int64 dp(int left, int right) {
  if (left > right) return 0;
  if (used[left][right]) return memo[left][right];
  used[left][right] = true;

  int turn = (left + right + 1) - n;

  int64 res;

  if (turn % 2 == 0) {
    res = -INF64;
    chmax(res, dp(left + 1, right) + a[left]);
    chmax(res, dp(left, right - 1) + a[right]);
  } else {
    res = INF64;
    chmin(res, dp(left + 1, right) - a[left]);
    chmin(res, dp(left, right - 1) - a[right]);
  }
  
  memo[left][right] = res;

  return memo[left][right];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  rep(i, n) cin >> a[i];

  cout << dp(0, n - 1) << '\n';
  
  return 0;
}