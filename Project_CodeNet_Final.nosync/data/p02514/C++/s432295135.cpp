#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

#define REP(i,N) for(int i=0;i<(int)(N);++i)


int main() {
  for (;;) {
      int have[6];
      REP(i, 6) scanf("%d", &have[i]);
      if (accumulate(have, have + 6, 0) == 0) break;

      REP(i, 3) have[i] += have[i + 3];

      int bal = min(have[0], min(have[1], have[2]));
      int ans = 0;
      for (int i = 0; i <= min(100, bal); i++) {
          int ind = 0;
          ind += (have[0] - i) / 3;
          ind += (have[1] - i) / 3;
          ind += (have[2] - i) / 3;
          ans = max(ans, ind + i);
      }
      cout << ans << endl;
  }
  return 0;
}