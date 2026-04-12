#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  long long ans = 1000000000;
  long long price;
  for ( int i = 0; i <= 100000; i++){
    price = c * 2 * i + a * max(x - i, 0) + b * max(y - i, 0);
    ans = min(ans, price);
  }

  cout << ans << endl;

  return 0;
}