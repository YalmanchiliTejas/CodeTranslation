#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

#define INF 1e9


int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = INF;
  REP(i, max(X, Y) * 2+1){
    int a = max(0,X-i/2)*A, b = max(0,Y-i/2)*B;
    int cost = a + b + i * C;
    ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}
