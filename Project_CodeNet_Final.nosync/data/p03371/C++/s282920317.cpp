#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, x, y;
  cin >> a >> b >> c >> x >> y;
  if(x < y) swap(x, y), swap(a, b);
  long long ans = 1000000000000000;
  for(int i = 0; i <= x; i++){
    long long k = i*a;
    k += (x-i) * 2 * c;
    if(y > x-i) k += (y - (x-i)) * b;
    ans = min(ans, k);
  }
  
  cout << ans << endl;
}