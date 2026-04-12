#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll ans = C*2*max(X,Y);
  int i = 0;
  while(i<2*max(X,Y)) {
     int x=X-i/2, y=Y-i/2;
     if(x<0) x=0;
     if(y<0) y=0;
     ll sum = C*i+A*x+B*y;
     ans = min(ans, sum);
     i += 2;
  }
  cout << ans << endl;
  return 0;
}