#include <cstdio>
#include <cstring>
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
  int n;
  while(scanf("%d", &n) && n){
    int lmin = 9999, lmax = 0, sum = 0, s;
    rep(i, n){
      scanf("%d", &s);
      lmin = min(lmin, s); lmax = max(lmax, s);
      sum += s;
    }

    printf("%d\n", (sum - lmin - lmax) / (n-2));
  }
  return 0;
}