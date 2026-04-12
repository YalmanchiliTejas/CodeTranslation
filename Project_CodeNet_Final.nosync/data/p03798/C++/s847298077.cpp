#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  int N;
  string s;
  cin >> N >> s;
  rep(i, 4) {
    vector<bool> res(N);
    res[0] = i&1;
    res[1] = i>>1;
    for (int j = 1; j < N-1; j++) {
      if (res[j]) {
        if (s[j] == 'o')
          res[j+1] = res[j-1];
        else
          res[j+1] = res[j-1]^1;
      } else {
        if (s[j] == 'o')
          res[j+1] = res[j-1]^1;
        else
          res[j+1] = res[j-1];
      }
    }
    if (res[N-1]) {
      if (s[N-1] == 'o' && res[N-2] != res[0] || s[N-1] == 'x' && res[N-2] == res[0])
        continue;
    } else {
      if (s[N-1] == 'o' && res[N-2] == res[0] || s[N-1] == 'x' && res[N-2] != res[0])
        continue;
    }
    if (res[0]) {
      if (s[0] == 'o' && res[N-1] != res[1] || s[0] == 'x' && res[N-1] == res[1])
        continue;
    } else {
      if (s[0] == 'o' && res[N-1] == res[1] || s[0] == 'x' && res[N-1] != res[1])
        continue;
    }
    rep(j, N)
      cout << (res[j] ? 'S' : 'W');
    cout << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}