#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <functional>
#include <utility>

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (m); i < (int)(n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define INF 2000000000
//#define int long long int

#ifdef LOCAL
  #define eprintf(...) fprintf(stdout, __VA_ARGS__)
#else
  #define eprintf(...) 0
#endif

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

vector<vector<int>> vv;
map<int, map<int, int>> mm;

int dfs(int point, vector<bool> visited) {
  visited[point] = true;
  if(count(ALL(visited), true) == visited.size()) {
    return 1;
  }
  int result = 0;
  REP(dest, vv[point].size()) {
    if(visited[dest] == false && vv[point][dest] == 1) {
      result += dfs(dest, visited);
    }
  }
  return result;
}

int main() {
  int n, m;
  cin >> n >> m;
  //map<int, map<int, int>> mm;
  REP(i, n) {
    vv.push_back(vector<int>(n));
  }
  int a, b;
  REP(i, m) {
    cin >> a >> b;
    vv[a-1][b-1] = 1;
    vv[b-1][a-1] = 1;
  }

  int ans = 0;
  vector<int> visited_orig(n, 0);
  ans += dfs(0, vector<bool>(n));
  cout << ans << endl;

  return 0;
}
