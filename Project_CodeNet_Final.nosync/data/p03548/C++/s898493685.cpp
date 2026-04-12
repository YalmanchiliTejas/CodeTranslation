//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int X,Y,Z;
  cin >> X >> Y >> Z;
  int Ans = X/(Y+Z);
  if(X%(Y+Z)==Z) printf("%d\n",Ans);
  else printf("%d\n",Ans - 1);
  return 0;

}
