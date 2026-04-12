#include <bits/stdc++.h>
using namespace std;
int main(){
  int X,Y,Z;
  cin >> X >> Y >> Z;
  int res = 0;
  X = X - Y - 2 * Z;
  while (X >= 0){
    res++;
    X = X - Y - Z;
  }
  cout << res;
}
