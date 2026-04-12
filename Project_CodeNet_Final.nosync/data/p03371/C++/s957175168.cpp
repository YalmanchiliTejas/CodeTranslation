#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vec1;
typedef vector<string> vec2;
typedef vector<double> vec3;

int main() {
  
  int a, b, c;
  cin >> a >> b >> c;
  int x, y;
  cin >> x >> y;
  ll ans = 0;
  int n = x + y;
  for(int i = 0; i < n; i++) {
    if(x == 0 && y == 0) break;
    if(x > 0 && y > 0) {
      int d = min(a+b,c*2);
      ans = ans + d;
      x--;
      y--;
      continue;
    } 
    if(x == 0 && y > 0) {
      int d = min(b,c*2);
      ans = ans + d;
      y--;
    } else {
      int d = min(a,c*2);
      ans = ans + d;
      x--;
    }
  }
  cout << ans << endl;
}
