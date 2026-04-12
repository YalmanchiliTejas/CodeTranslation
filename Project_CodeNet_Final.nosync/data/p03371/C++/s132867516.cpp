#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c , x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if(x > y){
    swap(x, y);
    swap(a, b);
  }
  if(2 * c >= a + b){
    ans = x * a + y * b;
  }else{
    ans = x * 2 * c;
    c *= 2;
    ans += min((y - x) * b, (y - x) * c);
  }
  cout << ans << endl;
  return 0;
}
