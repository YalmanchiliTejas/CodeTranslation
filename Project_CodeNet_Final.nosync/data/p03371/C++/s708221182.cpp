#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int tmp, ans = 1000000000;
  for(int i = 0; i <= 200000; i++){
    tmp = c*2*i + a*max(0, x-i) + b*max(0, y-i);
    ans = min(ans, tmp);
  }
  cout << ans << endl;

}
