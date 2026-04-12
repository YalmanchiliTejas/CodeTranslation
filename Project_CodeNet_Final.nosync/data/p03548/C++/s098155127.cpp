#include <bits/stdc++.h>
using namespace std;

int main() {
  int X,Y,Z;
  cin >> X >> Y >> Z;

  int a = X/(Y+Z);
  if(X < ((Y+Z)*a) + Z){
   cout << a - 1 << endl;;
  }else{
    cout << a << endl;
  }
}
