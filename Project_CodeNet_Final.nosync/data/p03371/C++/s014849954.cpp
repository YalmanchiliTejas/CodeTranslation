#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int chk(int x, int y){
  if(x-y < 0) return 0;
  return x-y;
}

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans = a*x + b*y;
  int n = max(x,y) * 2;
  for(int i = 0; i <= n; i++){
    int d = i / 2;
    int temp = (chk(x,d) * a) + (chk(y,d) * b) + (c * i);
    ans = min(ans, temp);
  }
  cout << ans << endl;
  return 0;
}
