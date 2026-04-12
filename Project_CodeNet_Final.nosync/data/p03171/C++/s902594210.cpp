
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

typedef long long ll;

ll as[3010];
ll memo[3010][3010];
bool visited[3010][3010];

ll solve(int bg, int ed, int turn) {
  ll &res = memo[bg][ed];
  if(!visited[bg][ed]) {
    visited[bg][ed] = true;
    if(bg == ed) {
      res = 0;
    } else {
      if(turn == 0) {
        res = as[bg] + solve(bg+1, ed, !turn);
        res = max(res, as[ed-1] + solve(bg, ed-1, !turn));
      } else {
        res = solve(bg+1, ed, !turn) - as[bg];
        res = min(res, solve(bg, ed-1, !turn) - as[ed-1]);
      }
    }
  }
  return res;
}

int main(void) {
  int N;
  scanf("%d", &N);
  REP(i, N) {
    scanf("%lld", &as[i]);
  }
  ll res = solve(0, N, 0);
  printf("%lld\n", res);
  return 0;
}
