#include <bits/stdc++.h>

using namespace std;

int main(){
  int X, Y, Z,ans=0;
  cin >> X >> Y >> Z;
  X -= Y + 2 * Z;
  while(X>=0){
    X -= Y + Z;
    ans++;
  }
  X += Y + Z;
  cout << ans  << endl;
}
