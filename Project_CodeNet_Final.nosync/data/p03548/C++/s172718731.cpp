#include <iostream>
using namespace std;
int main(){
  int X,Y,Z;
  cin >> X >> Y >> Z;
  int cnt=0;
  X-=Z;
  while(true){
    X-=(Y+Z);
    if(X<0)break;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}