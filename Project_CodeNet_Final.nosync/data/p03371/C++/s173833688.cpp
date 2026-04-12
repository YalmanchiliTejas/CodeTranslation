#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A, B, C, X, Y;
  cin>>A>>B>>C>>X>>Y;
  if(A+B<=2*C) cout<<A*X+B*Y<<endl;
  else{
    if(X>=Y){
      long long price1=2*C*Y+A*(X-Y);
      long long price2=2*C*X;
      cout<<min(price1, price2)<<endl;
    }
    if(X<Y){
      long long price1=2*C*X+B*(Y-X);
      long long price2=2*C*Y;
      cout<<min(price1, price2)<<endl;
    }
  } //else
}
 
