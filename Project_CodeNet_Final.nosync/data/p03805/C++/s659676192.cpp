#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define ALL(c) (c).begin(), (c).end()

int g[10][10];

int main() {
  int n, m;
  while (cin >> n >> m) {
    memset(g,0,sizeof(g));
    REP(i,m) {
      int a, b;
      cin >> a >> b;
      a--;b--;
      g[a][b] = g[b][a] = 1;
    }

    vector<int> v(n);
    iota(ALL(v), 0);
    int ans = 0;
    do {
      if (v[0] != 0) continue;
      bool ng = 0;
      REP(i,n-1) {
        if (!g[v[i]][v[i+1]]) {
          ng = 1;
          break;
        }
      }
      if (!ng) ans++;
    } while(next_permutation(ALL(v)));
    cout << ans << endl;
  }
}
