#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans = a*x+b*y;
  
  for (int i = 0; i <= max(x,y);i++) { //i枚分購入
    int sum = 0;
    sum += i*c*2; //i枚分なので、値段は2倍
    if (x > i) sum += (x-i) * a;
    if (y > i) sum += (y-i) * b;
    ans = min(ans,sum);
  }
  cout << ans << endl;
}
