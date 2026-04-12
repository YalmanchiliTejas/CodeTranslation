#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

using ll = long long;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int ans = 0;
  while(x>0 && y>0){
    if((a + b) < 2*c){
      ans += a;
      ans += b;
      x -= 1;
      y -= 1;
    }
    else{
      ans += 2*c;
      x -= 1;
      y -= 1;
    }
  }

  while(x>0){
    if(a < 2*c){
      ans += a;
      x--;
    }
    else{
      ans += 2*c;
      x--;
    }
  }

  while(y>0){
    if(b < 2*c){
      ans += b;
      y--;
    }
    else{
      ans += 2*c;
      y--;
    }
  }

  cout << ans << endl;

  return 0;
}
