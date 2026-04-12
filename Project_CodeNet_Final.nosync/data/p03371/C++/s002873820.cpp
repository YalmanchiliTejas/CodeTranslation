#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9


int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >>  X >> Y;
  int ans = INF;
  REP(i, max(X, Y)*2+1){
    int dx = max(X - i/2, 0), dy = max(Y - i/2, 0);
    int cost = A * dx + B*dy + C * i;
    // cerr << "i:" << i << " dx:" << dx << " dy:" << dy << " cost:" << cost << endl;
    ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}
