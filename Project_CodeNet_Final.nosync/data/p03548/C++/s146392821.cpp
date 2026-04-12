#include<iostream>
using namespace std;

int main(){
  int X, Y, Z;
  int ans = 0;
  cin >> X >> Y >> Z;

  while(Y + Z < X){
    ans++;
    X -= Y + Z;
  }

  if(X < Z) ans--;

  cout << ans << endl;
 return 0;
}
