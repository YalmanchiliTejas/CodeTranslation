#include <bits/stdc++.h>
using namespace std;
int main(){
  
  int X,Y,Z;
  cin >> X >> Y >> Z;
  int ans=X-Y-Z-Z;
  cout << ans/(Y+Z)+1 << endl;
  
}
