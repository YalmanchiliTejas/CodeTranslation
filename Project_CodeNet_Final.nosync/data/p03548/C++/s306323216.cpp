#include<bits/stdc++.h>
using namespace std;
int X,Y,Z,ans=0;

int main(){
  cin >> X  >> Y >> Z;

  while(1){
    X=X-2*Z;
    if(X<=0) break;
    X=X-Y;
    if(X<0){
      break;
    }
    ans++;
    X=X-Y;
    if(X<Z){
      break;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
