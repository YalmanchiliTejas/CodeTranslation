#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y;
  //入力
  cin >> a >> b >> c >> x >> y;
 
  //処理
  int ans=INT_MAX;

  for(int i = 0;i<2*(x+y);i++){
    ans=min(ans,max(0,x-i/2)*a + max(0,y-i/2)*b+c*i);
  }

  //出力
  cout << ans << endl;
  return 0;
}