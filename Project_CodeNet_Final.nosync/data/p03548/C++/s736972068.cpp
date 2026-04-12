#include <bits/stdc++.h>
using namespace std;
int main(){

  int X,Y,Z;
  cin >> X >> Y >> Z;

  long long int ans = 0;
  for(int i = 1;;i++){
    if(X - (Y * i + Z * (i+1)) >= 0)ans = i;
    else break;
  }

  cout << ans << endl;

  return 0;

}
