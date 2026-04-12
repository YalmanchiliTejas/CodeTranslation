#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s,e) for(int (i)=(s);(i)<(int)(e);(i)++)
#define REP(i,e) FOR(i,0,e)

#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)
#define UNIQUE(o) (o).erase(unique(sort(all((o)))))

typedef long long ll;
const int N = 100;
const int S = 1000;
int n;
int c[S+1];

int main() {
  int s;
  scanf("%d ", &n);
  while (n) {
    memset(c, 0, sizeof(c));
    int res = 0;
    int max_idx = 0, min_idx = S;
    REP(i,n) {
      scanf("%d ", &s);
      c[s]++;
      max_idx = max(max_idx, s);
      min_idx = min(min_idx, s);
      res += s;
    }
    res -= max_idx;
    res -= min_idx;
    n -= 2;
    res /= n;
    printf("%d\n", res);
    scanf("%d ", &n);
  }

  return 0;
}