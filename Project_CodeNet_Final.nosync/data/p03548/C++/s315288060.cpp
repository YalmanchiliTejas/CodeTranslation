#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {
  int X,Y,Z,ans;
  cin>>X>>Y>>Z;
  for(int i=0;;i++){
  	if(X<Y*i+Z*(i+1)){
      ans=i-1;
      break;
    }
  }
  cout<<ans<<endl;
}
