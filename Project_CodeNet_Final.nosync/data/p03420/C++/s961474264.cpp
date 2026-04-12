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
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
// text macro replacement
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define print(x) cout << (x) << '\n'
#define debug(x) cout << #x << ": " << (x) << '\n'
// variadic template
template<typename T> inline void chmin(T &a, T b) {if (a > b) a = b; return;}
template<typename T> inline void chmax(T &a, T b) {if (a < b) a = b; return;}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int64 n, k; cin >> n >> k;

  int64 ans = 0;

  for (int64 b = 1; b <= n; ++b) {
    int64 p = n / b, q = n % b;
    ans += p * max((int64) 0, b - k) + max((int64) 0, q - k + 1);
  }

  print(ans - (k == (int64) 0 ? n : (int64) 0));

  return 0;
}