#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int X,Y,Z;
  cin>>X>>Y>>Z;
  
  int ans=0;
  
  
  while(true){
    ans++;
    X=X-(Y+Z);
    if(X-(Y+Z)<Z){
      break;
    }
  }
  
  cout<<ans<<endl;
}