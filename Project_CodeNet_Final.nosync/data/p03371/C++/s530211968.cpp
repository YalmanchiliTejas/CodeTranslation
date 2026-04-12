#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  int res = 1001001000;
  
  rep(i, 100001){
    int cost = c * 2 * i;
    int a_left = max(0, x - i);
    int b_left = max(0, y - i);
    
    cost += a_left * a + b_left * b;
    
   	res = min(res, cost);
  }
 
  cout << res << endl;
  return 0;
}