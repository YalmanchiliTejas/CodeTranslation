#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans=0;
  int c2 = c*2;
  
  if (a > c2 && b > c2) {
    ans += max(x,y) * c2;
    cout << ans << endl;
    return 0;
  }
  while(0 < x || 0 < y) {
    if (y <= 0) if (a < c2) {ans +=a; x--; continue;}
    if (x <= 0) if (b < c2) {ans +=b; y--; continue;}
    if (a+b > c2) {ans+=c2; x--; y--;}
    else {ans += a+b ; x--; y--;}
  }
  
  cout << ans << endl;
}
