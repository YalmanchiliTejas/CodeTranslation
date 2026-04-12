#include <algorithm>
#include <bitset>
#include <cstdio>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T> using VEC = std::vector<T>;
template <class T> using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail> void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}

int main() {
  int n;
  cin >> n;
  VEC<string> s(n);
  REP(i, 0, n) {
    cin >> s[i];
    sort(ALL(s[i]));
  }
  string ans = s[0];
  DUMP(s);
  REP(i, 1, n) {
    stringstream update;
    int cur = 0;
    REP(c, 0, ans.length()) {
      for (int d = cur; d < s[i].length(); d++) {
        if (ans[c] == s[i][d]) {
          update << ans[c];
          cur = d+1;
          break;
        }
      }
    }
    ans = update.str();
    DUMP(i, ans);
  }
  cout << ans << endl;

  return 0;
}
