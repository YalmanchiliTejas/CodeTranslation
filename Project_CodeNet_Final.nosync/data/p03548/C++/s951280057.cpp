#include <bits/stdc++.h>
using namespace std;
 
int main() {

  int X,Y,Z;

  cin >> X >> Y >> Z;

  int ans=0;

  while(X>Y+Z){
    X-=Y+Z;
    ans++;
  }

  if(X<Z) ans--;
  
  cout << ans << endl;
}