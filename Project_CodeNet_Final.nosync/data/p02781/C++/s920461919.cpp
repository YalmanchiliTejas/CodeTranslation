#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

char buf[110];
int n;
ll memo[110][5][2];
ll solve(int pos, int k, int eq) {
  ll &res = memo[pos][k][eq];
  if(res < 0) {
    if(pos == n) {
      res = k == 0 ? 1 : 0;
    } else if(eq) {
      res = solve(pos+1, k, buf[pos] == '0');
      if(k > 0) {
        for(int d = 1; d <= buf[pos]-'0'; ++d) {
          res += solve(pos+1, k-1, buf[pos] == '0' + d);
        }
      }
    } else {
      res = solve(pos+1, k, false);
      if(k > 0) {
        for(int d = 1; d <= 9; ++d) {
          res += solve(pos+1, k-1, false);
        }
      }
    }
    // cerr << "> " << pos << " " << k << " " << eq << ": " << res << endl;
  }
  return res;
}

int main(void) {
  int k;
  scanf("%s%d", buf, &k);
  n = strlen(buf);
  memset(memo, -1, sizeof memo);
  ll res = solve(0, k, true);
  printf("%lld\n", res);
  return 0;
}
