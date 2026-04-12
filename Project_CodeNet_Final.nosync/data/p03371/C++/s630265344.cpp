#include<bits/stdc++.h>
using namespace std;
int main(){
int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  if(A+B<=2*C){
  cout<<A*X+B*Y<<endl;
  }else{
  if(X<=Y){
    if(B<=2*C)
    cout<<2*C*X+(Y-X)*B<<endl;
    else
      cout<<2*C*Y<<endl;
  }
    else{
      if(A<=2*C)
      cout<<2*C*Y+(X-Y)*A<<endl;
      else
        cout<<2*C*X<<endl;
    }
  }
  
   return 0;
}