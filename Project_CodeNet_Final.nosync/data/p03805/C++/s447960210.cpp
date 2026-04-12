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
template <class T>
using VEC = std::vector<T>;
template <class T>
using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail>
void DUMP(Head &&head, Tail &&... tail)
{
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}

int dfs(VEC<VEC<int>> &g, int pos, VEC<bool> &used, int usedNum)
{
  int n = g.size();
  if (n == usedNum)
  {
    DUMP("inback");
    return 1;
  }
  else
  {
    int ans = 0;
    REP(i, 0, n)
    {

      if (g[pos][i] == 1 && !used[i])
      {
        DUMP(g, i, used, usedNum, ans);
        used[i] = 1;
        ++usedNum;
        ans += dfs(g, i, used, usedNum);
        --usedNum;
        used[i] = 0;
      }
    }
    return ans;
  }
}
int main()
{
  int n, m;
  cin >> n >> m;
  VEC<VEC<int>> g(n, VEC<int>(n, 0));
  REP(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a][b] = 1;
    g[b][a] = 1;
  }
  VEC<bool> used(n, 0);
  used[0] = 1;
  int ans = dfs(g, 0, used, 1);
  cout << ans << endl;

  return 0;
}
