#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;

const ll INF = 1LL << 32;

ll n;

char solve(const string& str, string& ans) {
  char ret;
  for (ll i = 1; i < n; i++) {
    string diff = (ans[i - 1] == 'S') ? "W" : "S";
    string same = (ans[i - 1] == 'S') ? "S" : "W";
    string add;
    if (ans[i] == 'S') {
      if (str[i] == 'o')
        add = same;
      else
        add = diff;
    } else {
      if (str[i] == 'o')
        add = diff;
      else
        add = same;
    }
    if (i < n - 1)
      ans += add;
    else
      ret = add[0];
  }  // i

  assert(ret == 'S' || ret == 'W');

  return ret;
}  // solve

int main() {
  string str;
  cin >> n >> str;

  string ans = "SS";
  char chk_goal;
  char goal;
  if (str[0] == 'o')
    goal = 'S';
  else
    goal = 'W';
  chk_goal = solve(str, ans);
  if (chk_goal == ans[0] && goal == ans[n-1]) {
    cout << ans << endl;
    return 0;
  }

  ans = "SW";
  if (str[0] == 'o')
    goal = 'W';
  else
    goal = 'S';
  chk_goal = solve(str, ans);
  if (chk_goal == ans[0] && goal == ans[n-1]) {
    cout << ans << endl;
    return 0;
  }

  ans = "WS";
  if (str[0] == 'o')
    goal = 'W';
  else
    goal = 'S';
  chk_goal = solve(str, ans);
  if (chk_goal == ans[0] && goal == ans[n-1]) {  
    cout << ans << endl;
    return 0;
  }

  ans = "WW";
  if (str[0] == 'o')
    goal = 'S';
  else
    goal = 'W';
  chk_goal = solve(str, ans);
  if (chk_goal == ans[0] && goal == ans[n-1]) {    
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
