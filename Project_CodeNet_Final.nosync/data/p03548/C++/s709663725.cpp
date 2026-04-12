#include <bits/stdc++.h>
using namespace std;

int main() {
  int X,Y,Z;
  cin >> X >> Y >> Z;
  int cnt = 0;
  while(X >= Y+2*Z){
    cnt += 1;
    X = X-Y-Z;
  }
  cout << cnt << endl;
  return 0;
}