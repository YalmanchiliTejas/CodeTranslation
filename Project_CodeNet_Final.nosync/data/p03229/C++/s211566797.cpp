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

  int n; cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(all(a));
  sort(rall(b));

  int64 ans1 = 0, ans2 = 0;
  deque<int> dq1, dq2;
  // ・・・小大小・・・
  dq1.push_back(b[0]);
  int pos1 = 1, pos2 = 0;
  while ((int) dq1.size() < n) {
    dq1.push_back(a[pos2]); ++pos2;
    if ((int) dq1.size() < n) {
      dq1.push_front(a[pos2]); ++pos2;
    }
    if ((int) dq1.size() < n) {
      dq1.push_back(b[pos1]); ++pos1;
    }
    if ((int) dq1.size() < n) {
      dq1.push_front(b[pos1]); ++pos1;
    }
  }

  // ・・・大小大・・・
  dq2.push_back(a[0]);
  int pos3 = 0, pos4 = 1;
  while ((int) dq2.size() < n) {
    dq2.push_back(b[pos3]); ++pos3;
    if ((int) dq2.size() < n) {
      dq2.push_front(b[pos3]); ++pos3;
    }
    if ((int) dq2.size() < n) {
      dq2.push_back(a[pos4]); ++pos4;
    }
    if ((int) dq2.size() < n) {
      dq2.push_front(a[pos4]); ++pos4;
    }
  }

  for (int i = 1; i < n; ++i){
    ans1 += (int64) abs(dq1[i] - dq1[i - 1]);
    ans2 += (int64) abs(dq2[i] - dq2[i - 1]);
  }
  print(max(ans1, ans2));

  return 0;
}