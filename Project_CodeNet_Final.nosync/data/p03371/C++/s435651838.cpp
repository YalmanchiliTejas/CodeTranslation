#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A,B,C,X,Y;
  cin >>A>>B>>C>>X>>Y;
  
  if(X>=Y){
    if(A+B<2*C){
      cout<< X*A+Y*B<<endl;
      return 0;
    }
    if(A>=2*C){
      cout <<X*2*C<<endl;
      return 0;
    }
    cout<<Y*2*C+(X-Y)*A<<endl;
    return 0;
  }
  
   if(A+B<2*C){
      cout<< X*A+Y*B<<endl;
      return 0;
    }
    if(B>=2*C){
      cout <<Y*2*C<<endl;
      return 0;
    }
    cout<<X*2*C+(Y-X)*B<<endl;
    return 0;
}
