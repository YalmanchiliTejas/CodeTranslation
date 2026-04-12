#include<bits/stdc++.h>
using namespace std;
int main(){
  int X,Y,Z;
  cin >> X >> Y >> Z;
  int cnt = 0;
  X-=Z;
  while(X>=Y+Z){
    X-=Y+Z;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}

