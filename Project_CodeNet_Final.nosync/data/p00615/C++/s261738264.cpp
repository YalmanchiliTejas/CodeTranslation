#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

#define rep(i, j) FOR(i, 0, j)
#define FOR(i, j, k) for(int i = j; i < k; ++i)

using namespace std;

int main(){
  int n, m, tl;
  while(scanf("%d%d", &n, &m) && (n || m)){
    vector<int> d;
    d.push_back(0);
    rep(i, n + m){ scanf("%d", &tl); d.push_back(tl);}
    sort(d.begin(), d.end());
    int res = 0;
    rep(i, n + m) res = max(res, d[i + 1] - d[i]);

    printf("%d\n", res);
  }
  return 0;
}