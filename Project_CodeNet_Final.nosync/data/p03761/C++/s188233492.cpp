#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;

int main() {
  //
  int n;
  cin >> n;
  vvi cnt(50, vi(26, 0));
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, s.size()) { cnt[i][s[j] - 'a']++; }
  }
  vi tmp(26, 0);
  rep(x, 26) {
    rep(i, n) {
      if (i == 0) {
        tmp[x] = cnt[i][x];
      } else {
        tmp[x] = min(tmp[x], cnt[i][x]);
      }
    }
  }
  rep(x, 26) {
    while (tmp[x] > 0) {
      cout << string(1, 'a' + x);
      tmp[x]--;
    }
  }
  cout << endl;
  return 0;
}
