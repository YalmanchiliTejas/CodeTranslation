#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;

  int64_t ans=0;
  if(2*C>A+B){
    ans=A*X+B*Y;
  }
  else{
    ans=2*C*min(X,Y);
    if(2*C>=A){
      ans=ans+A*(X-min(X,Y));
    }
    else{
      ans=ans+2*C*(X-min(X,Y));
    }
    if(2*C>=B){
      ans=ans+B*(Y-min(X,Y));
    }
    else{
      ans=ans+2*C*(Y-min(X,Y));
    }
  }

  cout<<ans<<endl;
}