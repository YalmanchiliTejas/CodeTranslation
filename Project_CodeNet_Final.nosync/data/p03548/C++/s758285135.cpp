#include<bits/stdc++.h>

using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}

int main(){
  int x,y,z;
  cin >> x >> y >> z;
  x -= y + 2*z;
  int ans = 1;
  while(true){
    if(x  - y >= 0){
      x -= y;
    }else break;

    if(x - z >= 0){ans ++; x -= z;}
    else break;

  }
  cout << ans << endl;
  return 0;
}
